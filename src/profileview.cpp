#include "profileview.h"
#include "ui_profileview.h"

ProfileView::ProfileView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileView)
{
    ui->setupUi(this);

    setupView();
}

ProfileView::~ProfileView()
{
    delete ui;
}

void ProfileView::setupView()
{
    //Hide sensitive fields
    ui->widgetSalaryFields->setVisible( false );
    //Retain position of salary fields
    QSizePolicy sp_retain = ui->widgetSalaryFields->sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);
    ui->widgetSalaryFields->setSizePolicy(sp_retain);

}

void ProfileView::on_pushButtonSalaryFields_clicked()
{
    (ui->widgetSalaryFields->isVisible()) ? (ui->widgetSalaryFields->setVisible(false)) : (ui->widgetSalaryFields->setVisible(true));
}
