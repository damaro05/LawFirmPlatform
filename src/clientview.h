#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H
#include "listviewtemplate.h"

#include <QWidget>

#include <QNetworkAccessManager>
#include <QUrl>
class QFile;
class QNetworkReply;

QT_FORWARD_DECLARE_CLASS( QLineEdit )
class ClientView : public ListViewTemplate
{
public:
    ClientView();
    ~ClientView();

    virtual void setupView();

private slots:
//    void searchOnReturnPressed();

private:
//    QLabel* lbIconSearch;
//    QLineEdit* leSearch;
//    QWidget* inputSearch;

//    void filterSearch( QKeyEvent &key );
//    bool eventFilter(QObject *obj, QEvent *event);

    void httpReadyRead();
    QUrl url;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    QFile *file;

};

#endif // CLIENTVIEW_H
