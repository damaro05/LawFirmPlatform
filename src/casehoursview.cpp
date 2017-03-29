#include "casehoursview.h"
#include "ui_tableviewtemplate.h"
#include "models/cmodeltableview.h"

#include <QDialogButtonBox>

#include <iostream>
using namespace std;
CaseHoursView::CaseHoursView()
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;
    model = new CModelTableView(this);
    initializeModel( model, "HoursTest" );

    setupView();
}

CaseHoursView::~CaseHoursView()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;
    delete model;
}

void CaseHoursView::setupView()
{
    //Define title and column to be calculated
    ui->labelTitle->setText( "Registro de horas" );
    sumColumn = 2;
    sumColumnType = QString(" horas");

    ui->tableView->setModel( model );
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setColumnWidth( 0, (ui->tableView->width()/6) * 2 );
    ui->tableView->setColumnWidth( 1, (ui->tableView->width()/6) * 3 );
    ui->tableView->horizontalHeader()->setStretchLastSection( true );

    updateTotalLabel();
}

void CaseHoursView::initializeModel( QSqlTableModel *model, const QString &tablename )
{
    model->setTable( tablename );
    model->setEditStrategy( QSqlTableModel::OnManualSubmit );
    model->select();

    model->setHeaderData( 0, Qt::Horizontal, "Fecha" );
    model->setHeaderData( 1, Qt::Horizontal, "Usuario" );
    model->setHeaderData( 2, Qt::Horizontal, "Horas" );

    newDefaultRow( 0, 1 );
}
