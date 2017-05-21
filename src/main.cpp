#include "mainwindow.h"
#include "login.h"

#include <QApplication>
#include <QDebug>
#include "sql/connectioncache.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QFile res(":/fonts/fonts/AppleGaramond.ttf");
//    if( !res.open(QIODevice::ReadOnly) )
//        qDebug() << "Not able to open the font file";

    //set up font
//    QFontDatabase::addApplicationFont(":/fonts/fonts/AppleGaramond.ttf");
//    QFont f("Garamond", 14, QFont::Normal);

//    MainWindow w;
//    w.show();
//    w.showFullScreen();
//    a.setStyle("fusion");
    if( !createConnection() )
        return 1;
    Login loginWindow;
//    loginWindow.setFont( f );
//    QApplication::setFont( f );
    loginWindow.show();
//    MainWindow::getInstance()->show();
    return a.exec();


}
