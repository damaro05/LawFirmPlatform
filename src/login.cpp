#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "network/restclient.h"

#include <QMessageBox>
#include <QDebug>
#include <QTime>
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle( "Ventana de Login" );
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username = ui->lineEditUser->text();
    QString password = ui->lineEditPassword->text();

    QByteArray jsonStringC = "{\"user\":\"mmancho\",\"password\":\"1234\"}";
    QByteArray jsonString = "{\"user\":\"";
    jsonString.append( username );
    jsonString.append( "\",\"password\":\"" );
    jsonString.append( password );
    jsonString.append( "\"}" );

    qDebug() << "Json:  " << jsonString;
    qDebug() << "JsonC: " << jsonStringC;

    rs = new RestClient();
    QString url = QString("login/");
    rs->postRequest( url, jsonString );


    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

//    qDebug() << "Respuesta: " << rs->response;
    bool correctLogin = false;

    if( rs->isFinished ){
        //Check if there are errors
        correctLogin = true;
    }

    if( correctLogin ){
        QMessageBox::information( this, "Login", "El usuario y la contraseña son correctos" );
        MainWindow::getInstance()->show();
        this->hide();
    }else {
        QMessageBox::warning( this, "Login", "El usuario y la contraseña no son correctos" );
    }
}

void Login::on_pushButton_2_clicked()
{
    qDebug() << "Respuesta: " << rs->response;
}
