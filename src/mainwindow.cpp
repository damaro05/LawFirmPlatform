#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "maintoolbar.h"
#include "notificationview.h"
#include "models/lawyers.h"

#include "network/restclient.h"

#include <QCloseEvent>

#include <QJsonObject>
#include <QJsonObject>

#include <QDebug>
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

    restClient = RestClient::getInstance();

//    //Resize and disable resizing window
//    QRect rec = QApplication::desktop()->screenGeometry();
//    std::cout << "w " << rec.width() << " h " << rec.height() << std::endl;
//    this->setFixedSize(rec.width(), rec.height());

    setObjectName("MainWindow");
    setWindowTitle("Law Firm Platform");

    setupContent();
//    setupMenuBar();
    setupToolBar();

}


MainWindow::~MainWindow()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;

    delete ui;
    delete mainToolBar;
}

void MainWindow::setupToolBar()
{
    mainToolBar = new MainToolBar();
    ui->mainToolBar->addWidget( mainToolBar );
}

void MainWindow::setupContent()
{
    //Initialize current user
    foreach( const QJsonValue &value, restClient->jsonResponse ){
        QJsonObject jsonObj = value.toObject();
        user = new Lawyers( jsonObj["name"].toString(), jsonObj["surname"].toString(), jsonObj["user"].toString(), jsonObj["position"].toString(),
                jsonObj["address"].toString(), jsonObj["phone"].toString(), jsonObj["salary"].toString(), jsonObj["bankaccount"].toString(),
                jsonObj["sex"].toString(), jsonObj["education"].toString(), jsonObj["state"].toString(), jsonObj["age"].toInt() );
    }


    //Set models from the current user
    setupModels();
}

void MainWindow::setupModels()
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

