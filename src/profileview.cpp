#include "profileview.h"
#include "ui_profileview.h"

#include "models/lawyers.h"
#include "models/qjsontablemodel.h"
#include "globals.h"

#include <QStringListModel>

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

    //Change user icon sex
    if( user.sex() == "Masculino" )
        ui->labelSex->setPixmap( QPixmap(":/icons/Resources/imgs/icons/setDefault/Male Filled-24.png"));

    //Parsear education
    QStringList eduList = user.education().split(",", QString::SkipEmptyParts);
    QStringListModel* eduModel = new QStringListModel();
    eduModel->setStringList( eduList );

    ui->tableViewEducation->setModel( eduModel );
    ui->tableViewEducation->horizontalHeader()->setStretchLastSection( true );

    //Look for assigned cases
    RestClient* rc = RestClient::getInstance();
    QString url = "assignedcases/" + QString::number( user.idlawyer() );
//    QString url = "assignedcases/" + QString::number( 2 );

    rc->getRequest( url );

    QJsonTableModel::Header header;
    header.push_back( QJsonTableModel::Heading( {{"title","Nombre caso"}, {"index","name"}} ) );
    header.push_back( QJsonTableModel::Heading( {{"title","Fecha asignación"}, {"index","startdate"}} ) );

    QJsonTableModel* casesModel = new QJsonTableModel( header, this );
    ui->tableViewAsignedCases->setModel( casesModel );

    bool assignedcases = false;
    if( rc->isFinished ){
        //Check if there are errors
        if( rc->isCorrect )
            assignedcases = true;
    }

    if( assignedcases ){
        QJsonDocument jsonDResponse = QJsonDocument::fromJson( rc->response );
        casesModel->setJson( jsonDResponse );
    }

    //Define columb size
    ui->tableViewAsignedCases->setColumnWidth( 0, (ui->tableViewAsignedCases->width()/2) );
    ui->tableViewAsignedCases->horizontalHeader()->setStretchLastSection( true );

}
