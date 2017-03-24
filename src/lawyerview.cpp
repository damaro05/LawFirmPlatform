#include "lawyerview.h"
#include "ui_listviewtemplate.h"

#include <iostream>

////------------ Struct Double Item List  -----------------------------------------------------------//
LawyerView::DItemList::DItemList(const char* name, const char* position, const char* icon )
    : ItemList(name, icon), m_lposition(new QLabel(position))
{
    m_lposition->setMinimumSize( 250, 20 );
    m_lposition->setMaximumSize( 250, 20 );
    m_lposition->setFont( QFont("Garamond", 12) );
    m_lposition->setStyleSheet(" QLabel{ color: rgb(56, 87, 88); } ");

    for( int i = 0; i < m_flayout->count(); i++ ){
        QLayoutItem* lai = m_flayout->itemAt( i );
        if( lai->spacerItem() ){
            m_flayout->removeItem( lai );
            delete lai;
            --i; }
    }
    m_flayout->addWidget( m_lposition );
    QSpacerItem* vsFirstLay = new QSpacerItem( 10, 15, QSizePolicy::Expanding, QSizePolicy::Minimum );
    m_flayout->addItem( vsFirstLay );

}

////------------ End Struct Double Item list  ------------------------------------------------------//


LawyerView::LawyerView()
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;
    setupView();

    //Load Data from Database and active some threads
    std::string nameU, positionU;
    for( int i = 0; i < 5; i++){
        nameU = std::string( "Abogado numero " ) + std::to_string( i+1 );
        positionU = std::string( "Posición del abogado numero " ) + std::to_string( i+1 );
        addElementList( new DItemList( nameU.c_str(), positionU.c_str() ) );
    }
}

LawyerView::~LawyerView()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;
}

void LawyerView::setupView()
{
    ui->labelTitleTemplate->setText( "Listado de Abogados" );

}
