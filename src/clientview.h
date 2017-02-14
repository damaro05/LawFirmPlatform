#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H
#include "listviewtemplate.h"

class ClientView : public ListViewTemplate
{
public:
    ClientView();
    ~ClientView();

    virtual void setupView();

private slots:
//    void on_lineEditSearch_returnPressed();

private:
//    void filterSearch( QKeyEvent &key );
//    bool eventFilter(QObject *obj, QEvent *event);

};

#endif // CLIENTVIEW_H
