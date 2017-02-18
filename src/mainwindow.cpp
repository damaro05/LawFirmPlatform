#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "maintoolbar.h"

MainWindow* MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Singleton initialization
//    assert(instance == NULL);
    instance = this;

    ui->setupUi(this);
    mainToolBar = new MainToolBar();

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
    delete mainToolBar;
}

void MainWindow::setupToolBar()
{
    ui->mainToolBar->addWidget( mainToolBar );
}

void MainWindow::setupContent()
{

}

