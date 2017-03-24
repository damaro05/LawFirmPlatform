#include "mainwindow.h"
#include <QApplication>

#include "connectioncache.h"

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

    MainWindow::getInstance()->show();
    return a.exec();


}
