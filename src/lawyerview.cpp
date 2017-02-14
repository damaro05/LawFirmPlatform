#include "lawyerview.h"
#include "ui_lawyerview.h"

#include <iostream>

#include <QVBoxLayout>

////------------ Struct Double Item List  -----------------------------------------------------------//
//LawyerView::DItemList::DItemList(const char* name, const char* position)
//    : ItemList(name), m_lposition(new QLabel(position))
//{

//}

////------------ End Struct Double Item list  ------------------------------------------------------//


LawyerView::LawyerView(QWidget *parent) : QWidget(parent), ui(new Ui::LawyerView)
{
    //Initializing pointers
    ui->setupUi(this);
    _scrollAreaContent = new QWidget();
    _scrollAreaLayout = new QVBoxLayout();

    setupView();

    //--- should communicate with server and load data             ---//
    std::string nameU, positionU;
    for( int i = 0; i < 2; i++){
        nameU = std::string( "Empleado " ) + std::to_string( i+1 );
        positionU = std::string( "Posición del empleado " ) + std::to_string( i+1 );
        loadLawyer( nameU.c_str(), positionU.c_str() );
    }

}

LawyerView::~LawyerView()
{
    delete ui;
    delete _scrollAreaLayout;
    delete _scrollAreaContent;
}

void LawyerView::setupView()
{
    //Set scroll area content
    _scrollAreaContent->setLayout( _scrollAreaLayout );
    ui->scrollArea->setWidget( _scrollAreaContent );

    //Set scroll area content style
    _scrollAreaContent->setObjectName( "scrollAreaContent" );
    _scrollAreaContent->setStyleSheet(" QWidget#scrollAreaContent{ background-color: rgb(255, 255, 255);"
                                    "          border: 1px solid rgb(156, 208, 208);"
                                    "          border-radius: 6px } ");

//    std::cout << scrollAreaContent->objectName().toStdString() << std::endl;
}

void LawyerView::loadLawyer( const char* lawyerName, const char* lawyerPosition )
{
    QLabel* lbName = new QLabel( lawyerName );
    QLabel* lbPosition = new QLabel( lawyerPosition );
    QVBoxLayout* layout1 = new QVBoxLayout();

    lbName->setMinimumSize( 250, 20 );
    lbName->setMaximumSize( 250, 20 );
    lbPosition->setMinimumSize( 250, 20 );
    lbPosition->setMaximumSize( 250, 20 );
    lbName->setStyleSheet(" QLabel{ color: rgb(56, 87, 88); } ");
    lbPosition->setStyleSheet(" QLabel{ color: rgb(56, 87, 88); } ");

    layout1->setSpacing(0);
    layout1->addStretch();
    layout1->setContentsMargins( 9,9,9,9 );
    layout1->addWidget( lbName );
    layout1->addWidget( lbPosition );

    QLabel* lbIconLawyer = new QLabel();
    lbIconLawyer->setPixmap( QPixmap(":/icons/Resources/imgs/icons/setDefault/User Filled-64.png") );
    lbIconLawyer->setMinimumSize( 64, 64 );
    lbIconLawyer->setMaximumSize( 64, 64 );

    QHBoxLayout* layout2 = new QHBoxLayout();
    layout2->addWidget( lbIconLawyer );
    layout2->addLayout( layout1 );

    QSpacerItem* horizontalSpacerL = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum );
    QSpacerItem* horizontalSpacerR = new QSpacerItem( 60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    QHBoxLayout* layout3 = new QHBoxLayout();
    layout3->addItem( horizontalSpacerL );
    layout3->addLayout( layout2 );
    layout3->addItem( horizontalSpacerR );

    //Delete all previous spacers in scrollAreaLayout
    for(int i = 0; i < _scrollAreaLayout->count(); i++){
        QLayoutItem* lai = _scrollAreaLayout->itemAt(i);
        if( lai->spacerItem() ){
            _scrollAreaLayout->removeItem(lai);
            delete lai;
            --i; }
    }

    //Set size for a final spacer depending of content
    int verticalSpacerHeight = _scrollAreaContent->height() - ((lbIconLawyer->height() * (_scrollAreaLayout->count()+1)) * 1.3);
    if( verticalSpacerHeight < 0 )
        verticalSpacerHeight = 10;
    QSpacerItem* verticalSpacer = new QSpacerItem( 20, verticalSpacerHeight, QSizePolicy::Expanding, QSizePolicy::Minimum );

    _scrollAreaLayout->addLayout( layout3 );
    _scrollAreaLayout->addItem( verticalSpacer );
}
