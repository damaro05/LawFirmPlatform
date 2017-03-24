#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H
#include "listviewtemplate.h"

#include <QWidget>

QT_FORWARD_DECLARE_CLASS( QLineEdit )
class ClientView : public ListViewTemplate
{
public:
    ClientView();
    ~ClientView();

    virtual void setupView();

private slots:
    void searchOnReturnPressed();

private:
    QLabel* lbIconSearch;
    QLineEdit* leSearch;
    QWidget* inputSearch;

//    void filterSearch( QKeyEvent &key );
//    bool eventFilter(QObject *obj, QEvent *event);

};

#endif // CLIENTVIEW_H
