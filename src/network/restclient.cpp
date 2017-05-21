#include "restclient.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QCoreApplication>
#include <QTime>

#include "../globals.h"

RestClient* RestClient::instance = NULL;

RestClient::RestClient()
{
    instance = this;
    nam = new QNetworkAccessManager();
//    defaultUrl = QString("http://aldebaranserver.sytes.net/api/");
    defaultUrl = QString("http://localhost:9001/");
    connect(nam, SIGNAL(finished(QNetworkReply*)),this, SLOT(finished(QNetworkReply*)));

    initializeVariables();
}

RestClient::~RestClient()
{
    delete nam;
}


void RestClient::finished( QNetworkReply *reply )
{
    if( reply->error() == QNetworkReply::NoError ){

        response = reply->readAll();
        processResponse();
        (response == "{\"msg\":\"Element doesnt exist\"}") ? (isCorrect=false) : (isCorrect=true);
//        qDebug() << "Response: " << response;
    }else {
        isCorrect = false;
        qDebug() << "ERROR: " << reply->errorString();
    }

    reply->deleteLater();
    isFinished = true;
}

void RestClient::getRequest( QString url )
{
    initializeVariables();
    url = defaultUrl + url;
//    defaultUrl.append( url );
    QNetworkRequest request = QNetworkRequest( QUrl(url) );
    request.setRawHeader("Content-Type", "application/json");

    nam->get( request );
    waitResponse();
}

void RestClient::postRequest( QString url, QByteArray postData )
{
    initializeVariables();
    url = defaultUrl + url;
    QByteArray postDataSize = QByteArray::number( postData.size() );

//    qDebug() << "Parameters: " << postData;
//    qDebug() << "url: " << url;

    QNetworkRequest request = QNetworkRequest( QUrl(url) );
    // Add the headers specifying their names and their values
    request.setRawHeader("User-Agent", "LawFirmPlatform v0.1");
    request.setRawHeader("X-Custom-User-Agent", "LawFirmPlatform v0.1");
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    nam->post( request, postData );
    waitResponse();
}

void RestClient::processResponse()
{
    QJsonDocument jsonDResponse = QJsonDocument::fromJson( response );
    jsonResponse = jsonDResponse.array();
//    foreach( const QJsonValue &value, jsonResponse ){
//        QJsonObject jsonObj = value.toObject();
//        qDebug() << "Name: " << jsonObj["name"].toString();
//        qDebug() << "Position: " << jsonObj["position"].toString();
//    }
}

void RestClient::initializeVariables()
{
    isFinished = false;
    isCorrect = false;
    response = NULL;
//    jsonResponse = NULL;
    _waitTime = 100;
}

void RestClient::waitResponse()
{
    QTime dieTime= QTime::currentTime().addMSecs( _waitTime );
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 5);
}
