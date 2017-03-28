#include "tableviewtemplate.h"
#include "ui_tableviewtemplate.h"
#include "models/cmodeltableview.h"

#include <QDialogButtonBox>
#include <QMessageBox>

#include <QSqlTableModel>
#include <QSqlError>

#include <QDebug>
#include <iostream>
using namespace std;

TableViewTemplate::TableViewTemplate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableViewTemplate)
{
    ui->setupUi(this);

    buttonBox = new QDialogButtonBox( Qt::Horizontal );

//    connect(ui->pushBtnRevert, SIGNAL(clicked()), model, SLOT(revertAll()) );
}

TableViewTemplate::~TableViewTemplate()
{
    delete ui;
    delete buttonBox;
}

void TableViewTemplate::submitChanges()
{
    model->database().transaction();
    if( model->submitAll() ){
        model->database().commit();
    }else{
        model->database().rollback();
        QMessageBox::warning( this, typeid(this).name() ,
                              tr("The database reported an error: %1")
                              .arg(model->lastError().text() ) );
    }

}

double TableViewTemplate::columnSum( int columnIndex )
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


void TableViewTemplate::scrollToTheEnd()
{
    ui->tableView->scrollToBottom();
}

void TableViewTemplate::updateTotalHours()
{
    ui->labelSumTotalHours->setText( QString::number(columnSum( sumColumn )) + " horas" );
}

bool TableViewTemplate::isEmpty( int row )
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

void TableViewTemplate::on_pushBtnSubmit_clicked()
{
    submitChanges();
    updateTotalHours();
}

void TableViewTemplate::on_pushBtnRevert_clicked()
{
    model->revertAll();
}

void TableViewTemplate::on_pushBtnNewRow_clicked()
{
    if( isEmpty( model->rowCount()-1 ) )
        return;
    model->insertRow( model->rowCount() );
    scrollToTheEnd();

}
