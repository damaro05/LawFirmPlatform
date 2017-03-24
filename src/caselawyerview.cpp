#include "caselawyerview.h"
#include "ui_listviewtemplate.h"

#include <QPushButton>
#include <QHBoxLayout>
CaseLawyerView::CaseLawyerView()
{
    ui->mainScrollArea->setMinimumHeight( 300 );

    setupView();
}

CaseLawyerView::~CaseLawyerView()
{

}

void CaseLawyerView::setupView()
{
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
                            "QPushButton{ background-color: white; border: none; }");

    QLabel* buttonDescription = new QLabel( "Asignar abogado" );
    buttonDescription->setFont( QFont("Garamond", 12) );
//    buttonDescription->setFont( QFont("Garamond", 12, QFont::Bold, false) );
    buttonDescription->setStyleSheet(" QLabel{ color: rgb(56, 87, 88); } ");

    QPushButton* edit = new QPushButton( iconEdit, "Editar" );
    edit->setMaximumSize( 75, 32 );
    edit->setMinimumSize( 75, 32 );
    edit->setIconSize( QSize(32, 32) );
    edit->setFlat( true );
    edit->setFont( QFont("Garamond", 8, QFont::Bold, false) );
    edit->setStyleSheet("QPushButton:hover:!pressed{ border: 1px solid #80C7C6; }"
                        "QPushButton{ color: rgb(56, 87, 86); }" );

    QSpacerItem* spacerRButton = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    QSpacerItem* spacerR = new QSpacerItem( 70, 20, QSizePolicy::Minimum, QSizePolicy::Minimum );
    QSpacerItem* spacerL = new QSpacerItem( 70, 20, QSizePolicy::Minimum, QSizePolicy::Minimum );

    QHBoxLayout* footer = new QHBoxLayout();
    footer->setSpacing( 15 );
    footer->addItem( spacerL );
    footer->addWidget( assigned );
    footer->addWidget( buttonDescription );
    footer->addItem( spacerRButton );
    footer->addWidget( edit );
    footer->addItem( spacerR );

    ui->verticalLayoutFooter->addItem( new QSpacerItem(20,20,QSizePolicy::Expanding,QSizePolicy::Minimum) );
    ui->verticalLayoutFooter->addLayout( footer );


}
