#include "profileview.h"
#include "ui_profileview.h"

ProfileView::ProfileView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileView)
{
    ui->setupUi(this);

    //Retain position of salary fields
    QSizePolicy sp_retain = ui->widgetSalaryFields->sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);
    ui->widgetSalaryFields->setSizePolicy(sp_retain);

}

ProfileView::~ProfileView()
{
    delete ui;
}

void ProfileView::on_pushButtonSalaryFields_clicked()
{
    if( ui->widgetSalaryFields->isVisible() )
        ui->widgetSalaryFields->setVisible(false);
    else ui->widgetSalaryFields->setVisible(true);
}
