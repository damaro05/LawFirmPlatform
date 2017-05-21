#include "casedocview.h"
#include "ui_listviewtemplate.h"
#include "globals.h"

#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
CaseDocView::CaseDocView()
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;
    ui->mainScrollArea->setMinimumHeight( 300 );

    setupView();
    setupFilterSearch();
    QObject::connect( leSearch, &QLineEdit::returnPressed, this, &ListViewTemplate::searchOnReturnPressed );

//    //Load Data from Database and active some threads
    QString nameU;
    for( int i = 0; i < 6; i++){
        nameU =  QString( "Documento " ).append( QString::number( i+1 ) );
        addElementList( nameU, NULL, ":/icons/Resources/imgs/icons/setDefault/Document Filled-64.png" );
    }
}

CaseDocView::~CaseDocView()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;
}

void CaseDocView::setupView()
{
    ui->labelTitleTemplate->setText( "Documentación" );

    QIcon icon, iconEdit;
    icon.addFile( ":/icons/Resources/imgs/icons/setDefault/Plus Filled-48.png", QSize( 48, 48 ), QIcon::Normal, QIcon::Off );
    icon.addFile( ":/icons/Resources/imgs/icons/setDefault/Plus Filled2-48.png", QSize( 48, 48 ), QIcon::Normal, QIcon::On );
    iconEdit.addFile( ":/icons/Resources/imgs/icons/setDefault/Edit Row-32.png", QSize( 32, 32 ), QIcon::Normal, QIcon::Off );
    QPushButton* assigned = new QPushButton( icon, "" );
    assigned->setMinimumSize( 48, 48 );
    assigned->setMaximumSize( 48, 48 );
    assigned->setIconSize( QSize(44,48) );
    assigned->setCheckable( true );
    assigned->setFlat( true );
    assigned->setStyleSheet("QPushButton:hover:!pressed{ border: 0px solid #0089B2;"
                            "image: url(:/icons/Resources/imgs/icons/setDefault/Plus Filled2-48.png); } "
                            "QPushButton{ background-color: none; border: none; }");

    QLabel* buttonDescription = new QLabel( "Añadir documento" );
    buttonDescription->setFont( QFont("Garamond", 12) );
//    buttonDescription->setFont( QFont("Garamond", 12, QFont::Bold, false) );
    buttonDescription->setStyleSheet(" QLabel{ color: rgb(56, 87, 88); } ");

    QSpacerItem* spacerR = new QSpacerItem( 70, 20, QSizePolicy::Expanding, QSizePolicy::Expanding );
    QSpacerItem* spacerL = new QSpacerItem( 70, 20, QSizePolicy::Minimum, QSizePolicy::Minimum );

    QHBoxLayout* footer = new QHBoxLayout();
    footer->setSpacing( 15 );
    footer->addItem( spacerL );
    footer->addWidget( assigned );
    footer->addWidget( buttonDescription );
    footer->addItem( spacerR );

    ui->verticalLayoutFooter->addItem( new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Minimum) );
    ui->verticalLayoutFooter->addLayout( footer );

}
