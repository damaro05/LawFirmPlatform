#include "maintoolbar.h"
#include "ui_maintoolbar.h"

#include "mainwindow.h"
#include "profileview.h"

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
    menuButtons.append(ui->btnlawyerView);

}

MainToolBar::~MainToolBar()
{
    delete ui;
}

void MainToolBar::on_btnProfileView_clicked()
{
    updateMenuButtons(ui->btnProfileView);

    ProfileView* pf = new ProfileView();
    MainWindow::getInstance()->setCentralWidget(pf);
}

void MainToolBar::on_btnCaseView_clicked()
{
    updateMenuButtons(ui->btnCaseView);
}

void MainToolBar::on_btnClientView_clicked()
{
    updateMenuButtons(ui->btnClientView);
}

void MainToolBar::on_btnlawyerView_clicked()
{
    updateMenuButtons(ui->btnlawyerView);
}


void MainToolBar::updateMenuButtons(QPushButton* pb)
{
    pb->setChecked(true);
    QList<QPushButton*>::iterator i;
    for(i = menuButtons.begin(); i != menuButtons.end(); i++){
        if( *i == pb ) continue;
        if( !(*i)->isChecked() ) continue;
        (*i)->setChecked(false);

        //Set log for menu action
//        std::cout <<  "unchecked " << (*i)->text().toStdString() << std::endl;
    }

}