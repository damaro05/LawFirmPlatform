#include "clientview.h"
#include "ui_listviewtemplate.h"

#include <iostream>
#include <QLineEdit>
#include <QVBoxLayout>

using namespace std;
ClientView::ClientView():lbIconSearch(new QLabel()), leSearch(new QLineEdit()), inputSearch(new QWidget())
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;
    setupView();

    QObject::connect( leSearch, &QLineEdit::returnPressed, this, &ClientView::searchOnReturnPressed );

    //Load Data from Database and active some threads
    std::string nameU;
    for( int i = 0; i < 10; i++){
        nameU = std::string( "Cliente numero " ) + std::to_string( i+1 );
        addElementList( new ItemList( nameU.c_str() ) );
    }

    addElementList( new ItemList( "Oak" ));
    addElementList( new ItemList( "Fir" ));
    addElementList( new ItemList( "Pine" ));
    addElementList( new ItemList( "Birch" ));
    addElementList( new ItemList( "Hazel" ));
    addElementList( new ItemList( "Redwood" ));
    addElementList( new ItemList( "Sycamore" ));
    addElementList( new ItemList( "Pablo Perez" ));
    addElementList( new ItemList( "Pablo Martinez" ));
}

ClientView::~ClientView()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;
    delete lbIconSearch;
    delete leSearch;
    delete inputSearch;
}

void ClientView::setupView()
{
    ui->labelTitleTemplate->setText( "Listado de Clientes" );
    inputSearch->setLayout(new QHBoxLayout());
    inputSearch->layout()->addWidget( lbIconSearch );
    inputSearch->layout()->addWidget( leSearch );
    ui->verticalLayoutTitle->addWidget( ui->labelTitleTemplate );
    ui->verticalLayoutTitle->addWidget( inputSearch );

    lbIconSearch->setPixmap( QPixmap(":/icons/Resources/imgs/icons/setDefault/Search Filled2-24.png") );
    lbIconSearch->setMinimumSize( 24, 24 );
    lbIconSearch->setMaximumSize( 24, 24 );
    lbIconSearch->setStyleSheet( "QLabel{ border: none;}" );

    leSearch->setMinimumSize( 180, 25 );
    leSearch->setMaximumSize( 180, 25 );
    leSearch->setFont( QFont("Garamond", 12) );
    leSearch->setStyleSheet( "QLineEdit{ border: none; color: rgb(56,87,86); }" );
    leSearch->setMaxLength( 250 );
    leSearch->setPlaceholderText( "Buscar" );

    inputSearch->setObjectName( "inputSearch" );
    inputSearch->setMinimumSize( 215, 28 );
    inputSearch->setMaximumSize( 215, 28 );
    inputSearch->setStyleSheet( "QWidget#inputSearch{ background-color: white; border: 1px solid rgb(156,208,208);"
                                "border-radius: 6px; }" );
    inputSearch->layout()->setSpacing( 0 );
    inputSearch->layout()->setContentsMargins( 0,0,0,0 );


}

void ClientView::searchOnReturnPressed()
{
    if( leSearch->text().isEmpty() )
        return;

    QString tofind = leSearch->text();
    bool find = false;
    int rowheight;
    QVector<int> findOn;

    for( int i = 0; i < s_listElements.size(); i++ ){
        if( !s_listElements[i]->objectName().contains( tofind, Qt::CaseInsensitive ) )
            continue;
        find = true;
        findOn.append( i );
    }
    if( !s_listElements.isEmpty() )
        rowheight = s_listItemList[0]->m_licon->height();

    //Change this with ternary conditional
    if( find ){
        for( int i = 0; i < s_listElements.size(); i++ ){
            s_listElements[i]->setVisible( false );
            for( int j = 0; j < findOn.size(); j++){
                if( i == findOn[j] ){
                    s_listElements[i]->setVisible( true );
                    continue;
                }
            }
        }
        //send size of found as a second parameter
//        std::cout << "find si<e " << findOn.size() << std::endl;
        adjustLayoutContent( rowheight, findOn.size() );
    }else{
        for( int i = 0; i < s_listElements.size(); i++ ){
            if( s_listElements[i]->isVisible() )
                continue;
            s_listElements[i]->setVisible( true );
            //send number of clients created as a second parameter
            adjustLayoutContent( rowheight, s_listElements.size() );
        }
    }
}


