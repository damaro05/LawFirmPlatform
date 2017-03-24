#include "formtest.h"
#include "ui_formtest.h"

FormTest::FormTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTest)
{
    ui->setupUi(this);

    sca = new QScrollArea();

    //Transparency
//    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
//    setParent(0); // Create TopLevel-Widget
//    setAttribute(Qt::WA_NoSystemBackground, true);
//    setAttribute(Qt::WA_TranslucentBackground, true);
//    setAttribute(Qt::WA_PaintOnScreen);


//    for(int i = 0; i < 1; i++){
//        this->on_pushButton_clicked();
//    }
//    this->on_pushButton_2_clicked();

    ui->scrollArea->setWidget(ui->mainwidget);
}

FormTest::~FormTest()
{
    delete ui;
}

void FormTest::on_pushButton_clicked()
{


}

void FormTest::on_pushButton_2_clicked()
{
    QLabel* lb1 = new QLabel("Nombre");
    QLabel* lb2 = new QLabel("Cargo");
    QVBoxLayout* layout1 = new QVBoxLayout();
    layout1->addWidget(lb1);
    layout1->addWidget(lb2);

    QLabel* lb3 = new QLabel();
    lb3->setPixmap( QPixmap(":/icons/Resources/imgs/icons/setDefault/Graduation Cap Filled-48.png") );

    QHBoxLayout* layout2 = new QHBoxLayout();
    layout2->addWidget(lb3);
    layout2->addLayout(layout1);

    QSpacerItem* space = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    QHBoxLayout* layout3 = new QHBoxLayout();
    layout3->addLayout(layout2);
    layout3->addItem(space);

    //Delete all spacers
    for(int i = 0; i < ui->mainlayout->count(); i++){
        QLayoutItem* lai = ui->mainlayout->itemAt(i);
        if( lai->spacerItem() ){
            ui->mainlayout->removeItem(lai);
            delete lai;
            --i;
        }
    }

    QSpacerItem* vspacer = new QSpacerItem(20, 350, QSizePolicy::Expanding, QSizePolicy::Minimum);
    ui->mainlayout->addLayout(layout3);
    ui->mainlayout->addItem(vspacer);

}
