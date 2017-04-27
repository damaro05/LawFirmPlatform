#include "restclient.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

RestClient::RestClient()
{
    nam = new QNetworkAccessManager();

    isFinished = false;
    response = NULL;

//    defaultUrl = QString("http://aldebaranserver.sytes.net/api/");
    defaultUrl = QString("http://localhost:9001/");
    connect(nam, SIGNAL(finished(QNetworkReply*)),this, SLOT(finished(QNetworkReply*)));
    //    QObject::connect( leSearch, &QLineEdit::returnPressed, this, &ListViewTemplate::searchOnReturnPressed );

}

RestClient::~RestClient()
{
    delete nam;
}


void RestClient::finished( QNetworkReply *reply )
{
    if( reply->error() == QNetworkReply::NoError ){
//        QByteArray response2 = reply->readAll();
//        response = reply->readAll();
//        qDebug() << "Mensaje: " << response;
//        QJsonDocument jsonResponse = QJsonDocument::fromJson( response );
//        QJsonArray jsonArray = jsonResponse.array();
//        foreach( const QJsonValue &value, jsonArray ){
//            QJsonObject jsonObj = value.toObject();
//            qDebug() << "Name: " << jsonObj["name"].toString();
//            qDebug() << "Position: " << jsonObj["position"].toString();
//        }
        qDebug() << "Mensaje: " << reply->readAll();
    }else {
        qDebug() << "ERROR: " << reply->errorString();
    }

    reply->deleteLater();
    isFinished = true;
}

void RestClient::getRequest( QString url )
{
    isFinished = false;
    response = NULL;

    defaultUrl.append( url );
    QNetworkRequest request = QNetworkRequest( QUrl(defaultUrl) );
    request.setRawHeader("Content-Type", "application/json");
    nam->get( request );
}

void RestClient::postRequest( QString url, QByteArray postData )
{
    isFinished = false;
    response = NULL;

    defaultUrl.append( url );
    QByteArray postDataSize = QByteArray::number( postData.size() );

    qDebug() << "Parameters: " << postData;
    qDebug() << "url: " << defaultUrl;

    QNetworkRequest request = QNetworkRequest( QUrl(defaultUrl) );
    // Add the headers specifying their names and their values
    request.setRawHeader("User-Agent", "LawFirmPlatform v0.1");
    request.setRawHeader("X-Custom-User-Agent", "LawFirmPlatform v0.1");
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    nam->post( request, postData );
}
