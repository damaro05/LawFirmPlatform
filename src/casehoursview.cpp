#include "casehoursview.h"
#include "ui_casehoursview.h"

#include "cmodeltableview.h"

#include <QDialogButtonBox>
#include <QMessageBox>

#include <QSqlTableModel>
#include <QSqlError>

#include <QDebug>
#include <iostream>

#define hoursColumn 2
using namespace std;

CaseHoursView::CaseHoursView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaseHoursView)
{
    ui->setupUi(this);
    model = new CModelTableView(this);

    buttonBox = new QDialogButtonBox( Qt::Horizontal );
    initializeModel( model, "HoursTest" );

    setupView();
//    connect(ui->pushBtnRevert, SIGNAL(clicked()), model, SLOT(revertAll()) );
}

CaseHoursView::~CaseHoursView()
{
    delete ui;
    delete model;
}

void CaseHoursView::setupView()
{
    ui->tableView->setModel( model );
//    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->tableView->resize(100,100);

//    ui->tableView->setVisible( false );
    ui->tableView->resizeColumnsToContents();
//    ui->tableView->resizeRowsToContents();
//    ui->tableView->setVisible( true );table->horizontalHeader()->setStretchLastSection(true);
//    ui->tableView->horizontalHeader()->setStretchLastSection( true );

    ui->tableView->setColumnWidth( 0, ui->tableView->width()/4 );
    ui->tableView->setColumnWidth( 1,(ui->tableView->width()/4) * 2 );
//    ui->tableView->setColumnWidth( 2, ui->tableView->width()/4 );
    ui->tableView->horizontalHeader()->setStretchLastSection( true );

//    buttonBox->addButton( ui->pushBtnRevert, QDialogButtonBox::ActionRole );
//    buttonBox->addButton( ui->pushBtnSubmit, QDialogButtonBox::ActionRole );

    updateTotalHours();
}

void CaseHoursView::initializeModel( QSqlTableModel* model, const QString& tablename )
{
    model->setTable( tablename );
    model->setEditStrategy( QSqlTableModel::OnManualSubmit );
    model->select();

    model->setHeaderData( 0, Qt::Horizontal, "Fecha" );
    model->setHeaderData( 1, Qt::Horizontal, "Usuario" );
    model->setHeaderData( 2, Qt::Horizontal, "Horas" );

    model->insertRow( model->rowCount() );

}

void CaseHoursView::on_pushBtnSubmit_clicked()
{
    submitHours();
    updateTotalHours();
}

void CaseHoursView::on_pushBtnRevert_clicked()
{
    model->revertAll();
}

void CaseHoursView::submitHours()
{
    model->database().transaction();
    if( model->submitAll() ){
        model->database().commit();
    }else{
        model->database().rollback();
        QMessageBox::warning( this, "CaseHoursView",
                              tr("The database reported an error: %1")
                              .arg(model->lastError().text() ) );
    }

}

double CaseHoursView::columnSum( int columnIndex )
{
    double total = 0;
    Q_ASSERT_X( columnIndex >= 0 && columnIndex < model->columnCount(), "column sum", "column doesn't exist");
    for( int i = 0; i < model->rowCount(); i++){
        auto temp = model->data( model->index(i, columnIndex), Qt::DisplayRole );
        bool ok;
        total += temp.toDouble( &ok );
        Q_ASSERT_X( temp.isNull() || ok, "column sum", "column has non-numeric values" );
    }
    return total;
}

void CaseHoursView::on_pushBtnNewRow_clicked()
{
    if( isEmpty( model->rowCount()-1 ) )
        return;
    model->insertRow( model->rowCount() );
    scrollToTheEnd();
}

void CaseHoursView::scrollToTheEnd()
{
    ui->tableView->scrollToBottom();
}

void CaseHoursView::updateTotalHours()
{
    ui->labelSumTotalHours->setText( QString::number(columnSum(hoursColumn)) + " horas" );
}

bool CaseHoursView::isEmpty( int row )
{
    bool empty = false;
    //We do not take into account the hour column (int)
    for( int i = 0; i < model->columnCount()-1; i++){
        auto idxData = model->data( model->index( row, i ), Qt::DisplayRole );
        if( idxData.isValid() && idxData.isNull() )
            empty = true;
    }
    return empty;
}
