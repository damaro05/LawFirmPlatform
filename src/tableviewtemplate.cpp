#include "tableviewtemplate.h"
#include "ui_tableviewtemplate.h"
#include "models/cmodeltableview.h"

#include <QDialogButtonBox>
#include <QMessageBox>

#include <QSqlTableModel>
#include <QSqlError>

#include <QDebug>
#include <QDate>
#include <iostream>
using namespace std;

TableViewTemplate::TableViewTemplate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableViewTemplate)
{
    ui->setupUi(this);
    buttonBox = new QDialogButtonBox( Qt::Horizontal );
    setupView();
//    connect(ui->pushBtnRevert, SIGNAL(clicked()), model, SLOT(revertAll()) );
}

TableViewTemplate::~TableViewTemplate()
{
    delete ui;
    delete buttonBox;
}

void TableViewTemplate::setupView()
{
    buttonBox->setMinimumHeight( 32 );
    buttonBox->setMinimumWidth( 205 );
    buttonBox->setMaximumHeight( 32 );
    buttonBox->setMaximumWidth( 205 );
    buttonBox->addButton( ui->pushBtnRevert, QDialogButtonBox::ActionRole );
    buttonBox->addButton( ui->pushBtnSubmit, QDialogButtonBox::ActionRole );
    ui->layouButtonBox->addWidget( buttonBox );
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

void TableViewTemplate::updateTotalLabel(const QString &type )
{
    if ( !type.isEmpty() )
        sumColumnType = type;
    ui->labelSumTotalHours->setText( QString::number(columnSum( sumColumn )) + sumColumnType );
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
    updateTotalLabel();
}

void TableViewTemplate::on_pushBtnRevert_clicked()
{
    model->revertAll();
}

void TableViewTemplate::on_pushBtnNewRow_clicked()
{
    if( isEmpty( model->rowCount()-1 ) )
        return;
    //If user send user as a second parameter
    newDefaultRow( 0 );
}

void TableViewTemplate::newDefaultRow( int columnTime, int columnUser )
{

    model->insertRow( model->rowCount() );
    if( columnTime != -1 )
        setDefaultColTime( columnTime );
    if( columnUser != -1 )
        setDefaultColUser( columnUser, "Default User" );

    scrollToTheEnd();
}

void TableViewTemplate::setDefaultColTime( int column )
{
    auto date = QDateTime::currentDateTime();
    QString dateString = date.toString( "yyyy-MM-dd hh:mm:ss" );
    model->setData( model->index( model->rowCount()-1, column), dateString, Qt::EditRole );
}

void TableViewTemplate::setDefaultColUser( int column, const QString &user )
{
    model->setData( model->index( model->rowCount()-1, column), user, Qt::EditRole );
}
