#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "maintoolbar.h"
#include "formtest.h"

MainWindow* MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Singleton initialization
//    assert(instance == NULL);
    instance = this;

    ui->setupUi(this);

//    //Resize and disable resizing window
//    QRect rec = QApplication::desktop()->screenGeometry();
//    std::cout << "w " << rec.width() << " h " << rec.height() << std::endl;
//    this->setFixedSize(rec.width(), rec.height());

    setObjectName("MainWindow");
    setWindowTitle("Law Firm Platform");

    setupToolBar();
    setupContent();
//    setupMenuBar();


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupToolBar()
{
    MainToolBar* tb = new MainToolBar();
    ui->mainToolBar->addWidget(tb);
}

void MainWindow::setupContent()
{

}

