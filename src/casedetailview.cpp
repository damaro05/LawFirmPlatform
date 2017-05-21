#include "casedetailview.h"
#include "ui_casedetailview.h"
#include "models/cases.h"
#include "globals.h"
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
}

void CaseDetailView::setupData(const Cases& currentCase )
{
    QString state = "Cerrado";
    if( currentCase.state() )
        state = "Abierto";
    ui->labelTitle->setText( currentCase.name() );
    ui->labelStartdate->setText( ui->labelStartdate->text().append( QString(" ").append( currentCase.startDate()) ) );
    ui->labelState->setText( ui->labelState->text().append( QString(" ").append(state) ) );

    RestClient* rc = RestClient::getInstance();
    QString url = "cases/" + QString::number( currentCase.idcase() ) + "/clients";
    rc->getRequest( url );
    bool casesLawyersReq = false;
    if( rc->isFinished )
        if( rc->isCorrect )
            casesLawyersReq = true;
    if ( casesLawyersReq ){
        foreach ( const QJsonValue &value, rc->jsonResponse ) {
            QJsonObject jsonObj = value.toObject();
            QString cname = jsonObj["name"].toString();
            QString csurname = jsonObj["surname"].toString();
            if( jsonObj["type"].toString() == "Enterprise" )
                csurname.prepend(" - Persona de Contacto: ");
            else csurname.prepend(" ");
            cname.append( csurname );
            clientsList << cname;
        }
    }

    loadClientList();
}

void CaseDetailView::loadClientList()
{
    cModel = new QStringListModel( this );
    if( clientsList.isEmpty() )
        clientsList << "Este caso no tiene ningun cliente";
    cModel->setStringList( clientsList );
    ui->listViewClients->setModel( cModel );
    ui->listViewClients->setEditTriggers( QAbstractItemView::NoEditTriggers );
}
