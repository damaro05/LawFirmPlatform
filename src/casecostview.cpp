#include "casecostview.h"
#include "ui_tableviewtemplate.h"
#include "models/cmodeltableview.h"
#include "globals.h"
CaseCostView::CaseCostView()
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;
    model = new CModelTableView(this);
    initializeModel( model, "CostTest" );

    setupView();
}

CaseCostView::~CaseCostView()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;
    delete model;
}

void CaseCostView::setupView()
{
    //Define title and column to be calculated
    ui->labelTitle->setText( "Listado de costes" );
    sumColumn = 2;
    sumColumnType = QString(" €");

    ui->tableView->setMinimumWidth( 800 );
    ui->tableView->setModel( model );
    ui->tableView->resizeColumnsToContents();

    ui->pushBtnRevert->hide();
    ui->pushBtnSubmit->hide();

    updateTotalLabel();
}

void CaseCostView::initializeModel( QSqlTableModel *model, const QString &tablename )
{
    model->setTable( tablename );
    model->setEditStrategy( QSqlTableModel::OnManualSubmit );
    model->select();

    model->setHeaderData( 0, Qt::Horizontal, "Fecha" );
    model->setHeaderData( 1, Qt::Horizontal, "Concepto" );
    model->setHeaderData( 2, Qt::Horizontal, "Importe" );
    model->setHeaderData( 3, Qt::Horizontal, "Doc" );
    model->setHeaderData( 4, Qt::Horizontal, "Estado" );

    newDefaultRow( 0, 1 );
}
