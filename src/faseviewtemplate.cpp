#include "faseviewtemplate.h"
#include "ui_faseviewtemplate.h"

FaseViewTemplate::FaseViewTemplate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaseViewTemplate)
{
    ui->setupUi(this);
}

FaseViewTemplate::~FaseViewTemplate()
{
    delete ui;
}

void FaseViewTemplate::on_lineEditTitle_editingFinished()
{
//    ui->lineEditTitle->setReadOnly( true );
}
