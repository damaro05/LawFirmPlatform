#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_FORWARD_DECLARE_CLASS( MainToolBar )
QT_FORWARD_DECLARE_CLASS( Lawyers )
QT_FORWARD_DECLARE_CLASS( RestClient )
QT_FORWARD_DECLARE_CLASS( Cases )


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

    //Models
    Lawyers* user;
    QVector< Cases* > s_cases;
    Cases* currentCase;

private:
    explicit MainWindow(QWidget *parent = 0);
    void closeEvent( QCloseEvent* );
    void setupToolBar();
    void setupContent();
    void setupModels();

    Ui::MainWindow *ui;
    MainToolBar* mainToolBar;
    RestClient* restClient;

};

#endif // MAINWINDOW_H
