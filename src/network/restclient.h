#ifndef RESTCLIENT_H
#define RESTCLIENT_H

#include <QWidget>
#include <QJsonArray>
QT_FORWARD_DECLARE_CLASS( QNetworkAccessManager )
QT_FORWARD_DECLARE_CLASS( QNetworkReply )

class RestClient : public QObject
{
    Q_OBJECT

public:
    static RestClient* instance;
    static RestClient* getInstance(){
        if( instance == NULL )
            instance = new RestClient();
        return instance;
    }

    void getRequest( QString url );
    void postRequest( QString url, QByteArray postData );

    ~RestClient();

    bool isFinished;
    bool isCorrect;

    QByteArray response;
    QJsonArray jsonResponse;

private slots:
    void finished( QNetworkReply* reply );

private:
    RestClient();
    void processResponse();
    void initializeVariables();
    void waitResponse();
    QNetworkAccessManager* nam;
    QString defaultUrl;

    int _waitTime;
};

#endif // RESTCLIENT_H
