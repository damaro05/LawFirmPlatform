#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "maintoolbar.h"
#include "notificationview.h"

#include <QCloseEvent>
#include <iostream>
using namespace std;
MainWindow* MainWindow::instance = NULL;

/*
 *  -En closeEvent: guardar la configuración del usuario, incluyendo las llamadas a la base de datos correspondiente
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;

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
    std::cout << "Destructor " << typeid(this).name() << std::endl;

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

void MainWindow::closeEvent( QCloseEvent*  )
{
//    if (maybeSave()) {
//            writeSettings();
//            event->accept();
//    } else {
//        event->ignore();
//    }
    qApp->quit();
}

