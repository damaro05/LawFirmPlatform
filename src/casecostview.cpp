#include "casecostview.h"
#include "ui_tableviewtemplate.h"
#include "models/cmodeltableview.h"
#include "models/cases.h"
#include "models/qjsontablemodel.h"
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
    ui->tableView->setColumnWidth( 0, (ui->tableView->width()/10) * 2.5 );
    ui->tableView->setColumnWidth( 1, (ui->tableView->width()/10) * 5.3 );
    ui->tableView->setColumnWidth( 2, (ui->tableView->width()/10) * 1 );
    ui->tableView->setColumnWidth( 3, (ui->tableView->width()/10) * 0.5 );
    ui->tableView->setColumnWidth( 4, (ui->tableView->width()/10) * 0.5 );

    ui->tableView->horizontalHeader()->setStretchLastSection( true );

    ui->pushBtnRevert->hide();
    ui->pushBtnSubmit->hide();

    updateTotalLabel();
}

void CaseCostView::setupData( const Cases& currentCase )
{
    RestClient* rc = RestClient::getInstance();
    QString url = "cases/" + QString::number( currentCase.idcase() ) + "/cost";
    rc->getRequest( url );

    QJsonTableModel::Header header;
    header.push_back( QJsonTableModel::Heading( {{"title", "Fecha de creación"},{"index","entrydate"}} ) );
    header.push_back( QJsonTableModel::Heading( {{"title", "Concepto"},{"index","concept"}} ) );
    header.push_back( QJsonTableModel::Heading( {{"title", "Importe"},{"index","amount"}} ) );
    header.push_back( QJsonTableModel::Heading( {{"title", "Doc"},{"index","doc"}} ) );
    header.push_back( QJsonTableModel::Heading( {{"title", "Estado"},{"index","state"}} ) );

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
