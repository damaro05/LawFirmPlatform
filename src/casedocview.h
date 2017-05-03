#ifndef CASEDOCVIEW_H
#define CASEDOCVIEW_H

#include "listviewtemplate.h"

class CaseDocView : public ListViewTemplate
{
public:
    CaseDocView();
    ~CaseDocView();

private:
    void setupView();
};

#endif // CASEDOCVIEW_H
