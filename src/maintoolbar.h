#ifndef MAINTOOLBAR_H
#define MAINTOOLBAR_H

#include <QWidget>
QT_FORWARD_DECLARE_CLASS(QPushButton)

namespace Ui {
class MainToolBar;
}

class MainToolBar : public QWidget
{
    Q_OBJECT

public:
    explicit MainToolBar(QWidget *parent = 0);
    ~MainToolBar();

private slots:
    void on_btnProfileView_clicked();
    void on_btnCaseView_clicked();
    void on_btnClientView_clicked();
    void on_btnLawyerView_clicked();
    void on_btnBell_clicked();
    void on_btnHelp_clicked();

private:
    void updateMenuButtons(QPushButton* pb);

    Ui::MainToolBar *ui;
    QList<QPushButton*> menuButtons;
};

#endif // MAINTOOLBAR_H
