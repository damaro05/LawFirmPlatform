#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_FORWARD_DECLARE_CLASS( MainToolBar )

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ~MainWindow();

    //SINGLETON
    static MainWindow* instance;
    static MainWindow* getInstance(){
        if(instance == NULL)
            instance = new MainWindow();
        return instance;
    }

private:
    explicit MainWindow(QWidget *parent = 0);
    void closeEvent( QCloseEvent* );
    void setupToolBar();
    void setupContent();

    Ui::MainWindow *ui;
    MainToolBar* mainToolBar;

};

#endif // MAINWINDOW_H
