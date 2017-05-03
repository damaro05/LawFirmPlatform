#include "casedetailview.h"
#include "ui_casedetailview.h"
#include "models/cases.h"
#include <QStringListModel>

CaseDetailView::CaseDetailView(const Cases& currentCase, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaseDetailView)
{
    ui->setupUi(this);

    setupView();
    setupData( currentCase );
}

CaseDetailView::~CaseDetailView()
{
    delete ui;
}

void CaseDetailView::setupView()
{
    loadClientList();
}

void CaseDetailView::setupData(const Cases& currentCase )
{
    ui->labelTitle->setText( currentCase.name() );

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
