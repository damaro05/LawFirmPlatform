#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>


//QT_FORWARD_DECLARE_CLASS(QMenu)
#include <QDockWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //SINGLETON
    static MainWindow* instance;
    static MainWindow* getInstance(){
        if(instance == NULL)
            instance = new MainWindow();
        return instance;
    }

private:
    void setupToolBar();
    void setupContent();

    Ui::MainWindow *ui;
    QDockWidget* contentDockW = new QDockWidget;
    QMenu *m;

};

#endif // MAINWINDOW_H
