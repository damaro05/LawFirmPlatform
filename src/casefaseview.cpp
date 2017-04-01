#include "casefaseview.h"
#include "ui_casefaseview.h"

#include "faseviewtemplate.h"

#include <QVBoxLayout>

#include <iostream>
using namespace std;
CaseFaseView::CaseFaseView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaseFaseView)
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;
    ui->setupUi(this);

    setupView();
}

CaseFaseView::~CaseFaseView()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;
    delete ui;
}

void CaseFaseView::setupView()
{
    QWidget* contenedor = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();

    contenedor->setLayout( layout );
    ui->scrollArea->setWidget( contenedor );

    FaseViewTemplate* test = new FaseViewTemplate();
    FaseViewTemplate* test2 = new FaseViewTemplate();
    FaseViewTemplate* test3 = new FaseViewTemplate();
    FaseViewTemplate* test4 = new FaseViewTemplate();
    FaseViewTemplate* test5 = new FaseViewTemplate();
    layout->addWidget( test );
    layout->addWidget( test2 );
    layout->addWidget( test3 );
    layout->addWidget( test4 );
    layout->addWidget( test5 );
}
