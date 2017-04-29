#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "network/restclient.h"

#include <QMessageBox>
#include <QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowTitle( "Ventana de Login" );

    rClient = RestClient::getInstance();
}

Login::~Login()
{
    delete ui;
}

void Login::on_lineEditUser_returnPressed()
{
    on_pbEnter_clicked();
}

void Login::on_lineEditPassword_returnPressed()
{
    on_pbEnter_clicked();
}

void Login::on_pbEnter_clicked()
{
    QString username = ui->lineEditUser->text();
    QString password = ui->lineEditPassword->text();

    QByteArray jsonString = "{\"user\":\"";
    jsonString.append( username );
    jsonString.append( "\",\"password\":\"" );
    jsonString.append( password );
    jsonString.append( "\"}" );

    QString url = QString("login/");
    rClient->postRequest( url, jsonString );

//    qDebug() << "Respuesta: " << rs->response;
    bool correctLogin = false;

    if( rClient->isFinished ){
        //Check if there are errors
        if( rClient->isCorrect )
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
