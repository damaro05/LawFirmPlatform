#ifndef RESTCLIENT_H
#define RESTCLIENT_H

#include <QWidget>

class QNetworkAccessManager;
class QNetworkReply;
class QByteArray;

class RestClient : public QObject
{
    Q_OBJECT

public:
    void getRequest( QString url );
    void postRequest( QString url, QByteArray postData );

    RestClient();
    ~RestClient();

    QNetworkAccessManager* nam;
    bool isFinished;
    QByteArray response;

private slots:
    void finished( QNetworkReply* reply );

private:

    QString defaultUrl;
};

#endif // RESTCLIENT_H
