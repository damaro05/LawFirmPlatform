#include "profileview.h"
#include "ui_profileview.h"

#include "network/restclient.h"

#include <QDebug>

ProfileView::ProfileView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileView)
{
    ui->setupUi(this);

    setupView();
}

ProfileView::~ProfileView()
{
    delete ui;
}

void ProfileView::setupView()
{
    //Hide sensitive fields
    ui->widgetSalaryFields->setVisible( false );
    //Retain position of salary fields
    QSizePolicy sp_retain = ui->widgetSalaryFields->sizePolicy();
    sp_retain.setRetainSizeWhenHidden(true);
    ui->widgetSalaryFields->setSizePolicy(sp_retain);

}

void ProfileView::on_pushButtonSalaryFields_clicked()
{
    (ui->widgetSalaryFields->isVisible()) ? (ui->widgetSalaryFields->setVisible(false)) : (ui->widgetSalaryFields->setVisible(true));

    setupData(1);
}

bool ProfileView::setupData( int user )
{

    QByteArray jsonString = "{\"user\":\"mmancho\",\"password\":\"1234\"}";

    RestClient* rs = new RestClient();

    QString url = QString("login/");
    qDebug() << "json: " << jsonString;
    rs->postRequest( url, jsonString );
}
