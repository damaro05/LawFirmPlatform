#include "casehoursview.h"
#include "ui_tableviewtemplate.h"
#include "models/cmodeltableview.h"
#include "models/cases.h"
#include "models/qjsontablemodel.h"
#include "globals.h"

#include <QDialogButtonBox>

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

void CaseHoursView::setupData( const Cases& currentCase )
{
    RestClient* rc = RestClient::getInstance();
    QString url = "cases/" + QString::number( currentCase.idcase() ) + "/hours";
    rc->getRequest( url );

    QJsonTableModel::Header header;
    header.push_back( QJsonTableModel::Heading( {{"title", "Fecha de creación"},{"index","entrydate"}} ) );
    header.push_back( QJsonTableModel::Heading( {{"title", "Usuario"},{"index","name"}} ) );
    header.push_back( QJsonTableModel::Heading( {{"title", "Horas"},{"index","hours"}} ) );

    QJsonTableModel* hoursModel = new QJsonTableModel( header, this );
    ui->tableView->setModel( hoursModel );

    bool hourscases = false;
    if( rc->isFinished )
        if( rc->isCorrect )
            hourscases = true;
    if( hourscases ){
        QJsonDocument jsonDResponse = QJsonDocument::fromJson( rc->response );
        hoursModel->setJson( jsonDResponse );
    }

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
