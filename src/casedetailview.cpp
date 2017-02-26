#include "casedetailview.h"
#include "ui_casedetailview.h"

#include <QStringListModel>

CaseDetailView::CaseDetailView(const QString& caseName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaseDetailView)
{
    ui->setupUi(this);
    ui->labelTitle->setText( caseName );

    setupView();
}

CaseDetailView::~CaseDetailView()
{
    delete ui;
}

void CaseDetailView::setupView()
{
    loadClientList();
}

void CaseDetailView::loadClientList()
{
    //Call database or caseClientView
    QStringListModel* model = new QStringListModel( this );
    QStringList list;
    for( int i = 0; i < 20; i++ ){
        list << QString( "Cliente numero  " ) + QString( std::to_string( i+1 ).c_str() );
    }

    model->setStringList( list );
    ui->listViewClients->setModel( model );
    ui->listViewClients->setEditTriggers( QAbstractItemView::NoEditTriggers );

}
