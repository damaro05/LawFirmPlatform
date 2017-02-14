#include "clientview.h"
#include "ui_listviewtemplate.h"

#include <iostream>
#include <QLineEdit>
#include <QVBoxLayout>

using namespace std;
ClientView::ClientView()
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;

    setupView();

    std::string nameU;
    for( int i = 0; i < 100; i++){
        nameU = std::string( "Cliente numero " ) + std::to_string( i+1 );
        addElementList( new ItemList( nameU.c_str() ) );
    }
}

ClientView::~ClientView()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;

}

void ClientView::setupView()
{
    QLineEdit* lineSearch = new QLineEdit();
    QVBoxLayout* tands = new QVBoxLayout();

    ui->verticalLayoutTest->addWidget( ui->labelTitleTemplate );
    ui->verticalLayoutTest->addWidget( lineSearch );

}







