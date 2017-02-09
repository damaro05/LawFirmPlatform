#include "listviewtemplate.h"
#include "ui_listviewtemplate.h"

ListViewTemplate::ListViewTemplate(QWidget *parent) : QWidget(parent), TemplateUi(new Ui::ListViewTemplate)
{
    TemplateUi->setupUi(this);
    scrollAreaContent->setLayout( scrollAreaLayout );
    TemplateUi->mainScrollArea->setWidget( scrollAreaContent );
}


ListViewTemplate::~ListViewTemplate()
{
    delete TemplateUi;
}
