#include "caseview.h"
#include "ui_caseview.h"
#include "casehoursview.h"
#include "caselawyerview.h"
#include "casedocview.h"
#include "casedetailview.h"

#include <iostream>
#include <QListWidgetItem>

#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>

#include <QSortFilterProxyModel>
#include <QStringListModel>

using namespace std;
/*
    reajustar el tamaño del qlabel title con el title actual que se le asigna dinamicamente
    -En loadCase: cargar caso de la base de datos y preguntar al usuario por la confirmación de la accion,
        retornar bool para saber si se carga correctamente.
    -En loadListUserCases y loadListAllCases: cargar los elementos de la base de datos
    -En connect: intentar usar un unico connect pasando como parametro de la funcion el proxyfilter necesario

*/
CaseView::CaseView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaseView)
{
    ui->setupUi(this);
    proxyModel = new QSortFilterProxyModel( this );
    proxyModelOthers = new QSortFilterProxyModel( this );

    setupView();

    connect( ui->lineEditSearch, SIGNAL(textChanged(QString)), this, SLOT(updateListFilter(QString)) );
    connect( ui->lineEditSearchOthers, SIGNAL(textChanged(QString)), this, SLOT(updateListFilterOthers(QString)) );

}

CaseView::~CaseView()
{
    delete ui;
    delete hoursView;
    delete lawyerView;
    delete docView;
    delete detailView;
}

void CaseView::setupView()
{
    //setup filter
    ui->listViewOwnCases->setModel( proxyModel );
    ui->listViewOtherCases->setModel( proxyModelOthers );
    proxyModel->setFilterCaseSensitivity( Qt::CaseInsensitive );
    proxyModelOthers->setFilterCaseSensitivity( Qt::CaseInsensitive );

    //Load user cases and all cases
    loadListUserCases();
    loadListAllCases();

    //Set as default the first case
    ui->labelTitle->setText( ui->listViewOwnCases->indexAt(QPoint(0,0)).data().toString() );
    LoadHoursView();
    loadLawyerView();
    loadDocView();
    loadDetailView();

    //Load tabs icons
    QSize iconSize = QSize( 130, 48 );
    hoursIcon.addFile(":/icons/Resources/imgs/icons/setDefault/Time-48.png", iconSize, QIcon::Normal, QIcon::Off );
    hoursIcon.addFile(":/icons/Resources/imgs/icons/setDefault/Time Filled-48.png", iconSize, QIcon::Normal, QIcon::On );
    lawyerIcon.addFile(":/icons/Resources/imgs/icons/setDefault/Conference Call-48.png", iconSize, QIcon::Normal, QIcon::Off );
    lawyerIcon.addFile(":/icons/Resources/imgs/icons/setDefault/Conference Call Filled-48.png", iconSize, QIcon::Normal, QIcon::On );
    docIcon.addFile(":/icons/Resources/imgs/icons/setDefault/Box-48.png",iconSize, QIcon::Normal, QIcon::Off );
    docIcon.addFile(":/icons/Resources/imgs/icons/setDefault/Box Filled-48.png", iconSize, QIcon::Normal, QIcon::On );
    detailIcon.addFile(":/icons/Resources/imgs/icons/setDefault/Info-48.png", iconSize, QIcon::Normal, QIcon::Off );
    detailIcon.addFile(":/icons/Resources/imgs/icons/setDefault/Info Filled-48.png", iconSize, QIcon::Normal, QIcon::On );

    ui->tabWidget->addTab( hoursView, hoursIcon, "" );
    ui->tabWidget->addTab( lawyerView, lawyerIcon, "" );
    ui->tabWidget->addTab( docView, docIcon, "" );
    ui->tabWidget->addTab( detailView, detailIcon, "" );
}

void CaseView::loadListUserCases()
{
    QStringList list;
    list << "Oak" << "Fir" << "Pine" << "Birch" << "Hazel" << "Redwood" << "Sycamore" << "Chestnut"  << "Mahogany" ;
    for( int i = 0; i < 20; i++ ){
        list << QString( "Caso " ) + QString( std::to_string( i+1 ).c_str() );
    }

    proxyModel->setSourceModel( new QStringListModel(list) );

}

void CaseView::loadListAllCases()
{
    QStringList list;
    for( int i = 0; i < 20; i++ ){
        list << QString( "Otros Casos " ) + QString( std::to_string( i+1 ).c_str() );
    }

    proxyModelOthers->setSourceModel( new QStringListModel(list) );
}

void CaseView::updateListFilter( const QString& filterString )
{
    proxyModel->setFilterWildcard( QString("%1").arg( filterString ) );
}

void CaseView::updateListFilterOthers( const QString& filterString )
{
    proxyModelOthers->setFilterWildcard( QString("%1").arg( filterString ) );
}

void CaseView::on_listViewOwnCases_doubleClicked(const QModelIndex &index)
{
    loadCase( index.data().toString() );
}

void CaseView::on_listViewOtherCases_doubleClicked(const QModelIndex &index)
{
    loadCase( index.data().toString() );
}

void CaseView::LoadHoursView()
{
    hoursView = new CaseHoursView();
    ui->tabWidget->addTab( hoursView, hoursIcon, "" );
}

void CaseView::loadLawyerView()
{
    lawyerView = new CaseLawyerView();
    ui->tabWidget->addTab( lawyerView, lawyerIcon, "" );
}

void CaseView::loadDocView()
{
    docView = new CaseDocView();
    ui->tabWidget->addTab( docView, docIcon, "" );
}

void CaseView::loadDetailView()
{
    detailView = new CaseDetailView( ui->labelTitle->text() );
    ui->tabWidget->addTab( detailView, detailIcon, "" );
}


void CaseView::loadCase( const QString& title )
{
/*  List of Messages (Box class)
    void            about
    void            aboutQT
    StandardButton  critical
    StandardButton  information
    StandardButton  question
    StandardButton  warning
*/
    //QMessageBox::about(this, "My Title", "This is my custom message");
    QMessageBox ::StandardButton reply = QMessageBox::question(this, "Cambiar de caso", "¿Esta seguro que quiere cambiar de caso?",
                                                               QMessageBox::Yes | QMessageBox::No );

    if(reply ==  QMessageBox::Yes){
        ui->labelTitle->setText( title );
        //Reloading detail view
        if( hoursView )
            delete hoursView;
        if( lawyerView )
            delete lawyerView;
        if( detailView )
            delete detailView;

        LoadHoursView();
        loadLawyerView();
        loadDetailView();

    }else {
        qDebug() << "No is clicked";
    }


}
