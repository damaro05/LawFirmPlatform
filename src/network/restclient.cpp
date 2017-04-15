#include "restclient.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
RestClient::RestClient()
{
    nam = new QNetworkAccessManager();

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
        qDebug() << "Mensaje: " << reply->readAll();
    }else {
        qDebug() << "ERROR: " << reply->errorString();
    }

}

void RestClient::getRequest( QString url )
{
    QNetworkRequest request = QNetworkRequest( QUrl(url) );
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    nam->get( request );
}

void RestClient::postRequest( QString url, QString parameters )
{
    qDebug() << "Parameters: " << parameters;

    QByteArray postData;
    postData.append( parameters.toLatin1() );

    QNetworkRequest request = QNetworkRequest( QUrl(url) );
    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    nam->post( request, postData );
}
