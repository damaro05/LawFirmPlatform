#include "casefaseview.h"
#include "ui_casefaseview.h"
#include "faseviewtemplate.h"
#include "globals.h"

#include <QVBoxLayout>

CaseFaseView::CaseFaseView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaseFaseView)
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;
    ui->setupUi(this);

    _scrollContent = new QWidget();
    _scrollLayout = new QVBoxLayout();
    setupView();

}

CaseFaseView::~CaseFaseView()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;
    delete ui;
    //Memory Error
//    delete _scrollContent;
//    delete _scrollLayout;
}

void CaseFaseView::setupView()
{
    _scrollContent->setLayout( _scrollLayout );
    ui->scrollArea->setWidget( _scrollContent );

    //Set scroll area content style
    _scrollContent->setObjectName( "scrollAreaContent" );
    _scrollContent->setStyleSheet(" QWidget#scrollAreaContent{ background-color: rgb(255, 255, 255);"
                                    "          border: 1px solid rgb(156, 208, 208);"
                                    "          border-radius: 6px } ");


    FaseViewTemplate* test = new FaseViewTemplate();
    _scrollLayout->addWidget( test );
}
