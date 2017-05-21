#include "newcaseview.h"
#include "ui_newcaseview.h"

#include "clientview.h"
#include "globals.h"

#include <QListWidget>

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
    QGridLayout* ly = new QGridLayout();
    ly->addWidget( _clientView );
    ui->widgetClients->setLayout( ly );

}

void NewCaseView::on_pushButtonAccept_clicked()
{
    QListWidgetItem* item;
    QList<QListWidgetItem*> list = _clientView->listWidget->selectedItems();
    foreach (item, list) {
        qDebug() << item->text() << " data: " << item->data(Qt::DisplayRole) << " "
                 << item->data(Qt::UserRole+1);
    }
    qDebug() << "Abogados seleccionados: ";

}

void NewCaseView::on_pushButtonCancel_clicked()
{
    if( this->close() )
        qDebug() << "Cerrando new Case";
}
