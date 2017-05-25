#include "newcaseview.h"
#include "ui_newcaseview.h"

#include "clientview.h"
#include "mainwindow.h"
#include "lawyerview.h"
#include "models/cases.h"
#include "globals.h"

#include <QListWidget>
#include <QDate>
#include <QMessageBox>

NewCaseView::NewCaseView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewCaseView)
{
    ui->setupUi(this);
    _clientView = new ClientView();

    setupView();
}

NewCaseView::~NewCaseView()
{
    delete ui;
    delete _clientView;
}

void NewCaseView::setupView()
{
    auto date = QDateTime::currentDateTime();
    QString dateString = date.toString( "yyyy-MM-dd hh:mm:ss" );
    ui->lbEditCurrentDate->setText( dateString );

    QGridLayout* ly = new QGridLayout();
    ly->addWidget( _clientView );
    ui->widgetClients->setLayout( ly );

}

void NewCaseView::on_pushButtonAccept_clicked()
{
    int itemsIteration = 0;
    QByteArray clients = "[";
    QListWidgetItem* item;
    QList<QListWidgetItem*> list = _clientView->listWidget->selectedItems();
    foreach (item, list) {
//        qDebug() << item->text() << " data: " << item->data(Qt::DisplayRole) << " "
//                 << item->data(Qt::UserRole+1) << " - " << item->data(Qt::UserRole+2);
        if( itemsIteration > 0 )
            clients.append(",");
        clients.append( "\"" + item->data( Qt::UserRole+2 ).toString() + "\"" );
        itemsIteration++;
    }

    clients.append( "]" );
    qDebug() << "Clients " << clients;

    QString casename = ui->lineEditName->text();
    QString currentdate = ui->lbEditCurrentDate->text();
    QString state = "true";

    QByteArray jsonString = "{\"name\":\"";
    jsonString.append( casename );
    jsonString.append( "\",\"startdate\":\"" );
    jsonString.append( currentdate );
    jsonString.append( "\",\"state\":\"" );
    jsonString.append( state + "\"" );

    if( itemsIteration > 0 ){
        jsonString.append( ",\"idclient\":" );
        jsonString.append( clients );
    }
    jsonString.append( "}" );

    qDebug() << "Atributos: " << jsonString;

    QString url = QString("cases");
    RestClient* rc = RestClient::getInstance();
    rc->postRequest( url, jsonString );
    bool correctPost = false;
    if( rc->isFinished )
        if( rc->isCorrect )
            correctPost = true;

    if( correctPost ){
        QMessageBox::information( this, "Nuevo Caso", "Nuevo caso creado correctamente" );

    }else {
        QMessageBox::warning( this, "Nuevo Caso", "Error al crear el caso, intentelo de nuevo" );
    }

    this->close();
}

void NewCaseView::on_pushButtonCancel_clicked()
{
    if( this->close() )
        qDebug() << "Cerrando new Case";
}
