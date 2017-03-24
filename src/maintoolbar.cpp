#include "maintoolbar.h"
#include "ui_maintoolbar.h"

#include "mainwindow.h"
#include "profileview.h"
#include "listviewtemplate.h"
#include "lawyerview.h"
#include "clientview.h"
#include "caseview.h"

#include "notificationview.h"

#include "formtest.h"

#include <iostream>
using namespace std;

MainToolBar::MainToolBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainToolBar)
{
    ui->setupUi(this);

    menuButtons.append(ui->btnProfileView);
    menuButtons.append(ui->btnCaseView);
    menuButtons.append(ui->btnClientView);
    menuButtons.append(ui->btnLawyerView);

}

MainToolBar::~MainToolBar()
{
    delete ui;
}

void MainToolBar::on_btnProfileView_clicked()
{
    updateMenuButtons( ui->btnProfileView );

    ProfileView* profilev = new ProfileView();
    MainWindow::getInstance()->setCentralWidget( profilev );
}

void MainToolBar::on_btnCaseView_clicked()
{
    updateMenuButtons( ui->btnCaseView );
    CaseView* casev = new CaseView();
    MainWindow::getInstance()->setCentralWidget( casev );
//    lvt->show();
}

void MainToolBar::on_btnClientView_clicked()
{
    updateMenuButtons( ui->btnClientView );
    ClientView* clientv = new ClientView();
    MainWindow::getInstance()->setCentralWidget( clientv );
}

void MainToolBar::on_btnLawyerView_clicked()
{
    updateMenuButtons( ui->btnLawyerView );
    LawyerView* lawyerv = new LawyerView();
    MainWindow::getInstance()->setCentralWidget( lawyerv );
}


void MainToolBar::updateMenuButtons( QPushButton* pb )
{
    pb->setChecked(true);
    QList<QPushButton*>::iterator i;
    for(i = menuButtons.begin(); i != menuButtons.end(); i++){
        if( *i == pb ) continue;
        if( !(*i)->isChecked() ) continue;
        (*i)->setChecked(false);
    }
}

void MainToolBar::on_btnBell_clicked()
{
    NotificationView* nview = NotificationView::getInstance();
    QPoint pos;
    pos.setX( (ui->btnBell->pos().x() - ((nview->width() / 2)* 1.25 )) );
    pos.setY( (ui->btnBell->pos().y() + (nview->height() * 0.25 )) );
    nview->move( pos );
    (nview->isVisible()) ? (nview->setVisible(false)) : (nview->setVisible(true));
}

void MainToolBar::on_btnHelp_clicked()
{

}


