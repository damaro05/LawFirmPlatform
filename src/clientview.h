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
    void adjustLayoutContent( const int &rowHeight, int contentElements );
    void loadClient( const char* clientName );

//    void filterSearch( QKeyEvent &key );
//    bool eventFilter(QObject *obj, QEvent *event);

    Ui::ClientView *ui;

    QVBoxLayout* _scrollAreaLayout;
    QWidget* _scrollAreaContent;

    QVector< QWidget* > s_clients;
};

#endif // CLIENTVIEW_H
