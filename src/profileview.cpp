#include "profileview.h"
#include "ui_profileview.h"

#include "models/lawyers.h"
#include "network/restclient.h"

#include <QStandardItem>
#include <QStringListModel>
#include <QDebug>

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

void ProfileView::setupData( Lawyers &user )
{
    ui->labelName->setText( user.name() + QString(" ") + user.surname() );
    ui->labelUser->setText( user.user() );
    ui->labelPosition->setText( user.position() );
    ui->labelAddress->setText( user.address() );
    ui->labelPhone->setText( user.phone() );

    ui->labelSalary->setText( user.salary() + QString(" €") );
    ui->labelBankAccount->setText( user.bankaccount() );
    ui->labelAge->setText( QString::number(user.age()) );

    //Hacer if para sex


    //Parsear education
    QStringList eduList = user.education().split(",", QString::SkipEmptyParts);
    QStringListModel * eduModel = new QStringListModel();
    eduModel->setStringList( eduList );
    ui->tableViewEducation->setModel( eduModel );
    ui->tableViewEducation->horizontalHeader()->setStretchLastSection( true );
}
