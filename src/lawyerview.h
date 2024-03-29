#ifndef LAWYERVIEW_H
#define LAWYERVIEW_H

#include "listviewtemplate.h"
#include <QWidget>

class LawyerView : public ListViewTemplate
{
public:
    LawyerView();
    ~LawyerView();

    virtual void setupView();
    void setupData();

protected:
    struct DItemList : ItemList{
        DItemList( const char* name, const char* position, const char* icon = NULL );
        QLabel* m_lposition;
    };
};

#endif // LAWYERVIEW_H
