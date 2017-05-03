#include "mainwindow.h"
#include "login.h"

#include <QApplication>
#include <QDebug>

#include "sql/connectioncache.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    w.showFullScreen();
//    a.setStyle("fusion");
    if( !createConnection() )
        return 1;
    Login loginWindow;

    loginWindow.show();
//    MainWindow::getInstance()->show();
    return a.exec();


}
