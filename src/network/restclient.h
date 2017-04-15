#ifndef RESTCLIENT_H
#define RESTCLIENT_H

#include <QWidget>

class QNetworkAccessManager;
class QNetworkReply;

class RestClient : public QObject
{
    Q_OBJECT

public:
    void getRequest( QString url );
    void postRequest( QString url, QString parameters );

    RestClient();
    ~RestClient();

private slots:
    void finished( QNetworkReply* reply );

private:
    QNetworkAccessManager* nam;
};

#endif // RESTCLIENT_H
