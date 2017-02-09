#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H
#include <iostream>

#include <QWidget>
QT_FORWARD_DECLARE_CLASS( QVBoxLayout )

using namespace std;
namespace Ui {
class ClientView;
}

class ClientView : public QWidget
{
    Q_OBJECT

public:
    explicit ClientView(QWidget *parent = 0);
    ~ClientView();

private slots:
    void on_lineEditSearch_returnPressed();

private:
    void setupView();
    void loadClient( const char* clientName );

//    void filterSearch( QKeyEvent &key );
//    bool eventFilter(QObject *obj, QEvent *event);

    Ui::ClientView *ui;

    QVBoxLayout* _scrollAreaLayout;
    QWidget* _scrollAreaContent;
};

#endif // CLIENTVIEW_H
