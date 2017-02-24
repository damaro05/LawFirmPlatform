#include "caseview.h"
#include "ui_caseview.h"

#include <iostream>
#include <QListWidgetItem>

#include <QDebug>
#include <QKeyEvent>

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
}

void CaseView::setupView()
{
    ui->listViewOwnCases->setModel( proxyModel );
    ui->listViewOtherCases->setModel( proxyModelOthers );
    proxyModel->setFilterCaseSensitivity( Qt::CaseInsensitive );
    proxyModelOthers->setFilterCaseSensitivity( Qt::CaseInsensitive );

    loadListUserCases();
    loadListAllCases();

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

void CaseView::loadCase( const QString& title )
{
    ui->labelTitle->setText( title );
}