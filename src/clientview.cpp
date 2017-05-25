#include "clientview.h"
#include "ui_listviewtemplate.h"
#include "globals.h"

#include <QLineEdit>
#include <QVBoxLayout>
//#include <qtconcurrentrun.h>
//#include <QtConcurrent>
//#include <QThread>
//ClientView::ClientView():lbIconSearch(new QLabel()), leSearch(new QLineEdit()), inputSearch(new QWidget())
ClientView::ClientView()
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;
    setupFilterSearch();
    setupView();

    setupData();

    QObject::connect( leSearch, &QLineEdit::returnPressed, this, &ListViewTemplate::searchOnReturnPressed );
}

ClientView::~ClientView()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;
}

void ClientView::setupView()
{
    ui->labelTitleTemplate->setText( "Listado de Clientes" );
}

void ClientView::setupData()
{
    RestClient* rc = RestClient::getInstance();
    QString url = "clients";
    rc->getRequest( url );
    bool clientsReq = false;
    if( rc->isFinished )
        if( rc->isCorrect )
            clientsReq = true;
    if( clientsReq ){
        foreach ( const QJsonValue &value, rc->jsonResponse ) {
            QJsonObject jsonObj = value.toObject();
            //jsonObj has type (Individual, Enterprise)
            QString cname = jsonObj["name"].toString();
            QString surname = jsonObj["surname"].toString();
            int idclient = jsonObj["idclient"].toInt();
            QString intermediary = NULL;
            if( jsonObj["type"].toString() == "Enterprise" ){
                intermediary.prepend("Persona de contacto : ");
                intermediary.append( surname );
            }else {
                surname.prepend(" ");
                cname.append( surname ); }
            addElementList( cname, intermediary, NULL, idclient );
        }
    }

//    for(int i = 0; i < 10000; i++){
//        QString aux = "Cliente de prueba numero: " + QString::number(i);
//        addElementList(aux);
//    }
}


//void ClientView::searchOnReturnPressed()
//{
//    if( leSearch->text().isEmpty() )
//        return;

//    QString tofind = leSearch->text();
//    bool find = false;
//    int rowheight;
//    QVector<int> findOn;

//    for( int i = 0; i < s_listElements.size(); i++ ){
//        if( !s_listElements[i]->objectName().contains( tofind, Qt::CaseInsensitive ) )
//            continue;
//        find = true;
//        findOn.append( i );
//    }
//    if( !s_listElements.isEmpty() )
//        rowheight = s_listItemList[0]->m_licon->height();

//    //Change this with ternary conditional
//    if( find ){
//        for( int i = 0; i < s_listElements.size(); i++ ){
//            s_listElements[i]->setVisible( false );
//            for( int j = 0; j < findOn.size(); j++){
//                if( i == findOn[j] ){
//                    s_listElements[i]->setVisible( true );
//                    continue;
//                }
//            }
//        }
//        //send size of found as a second parameter
////        std::cout << "find si<e " << findOn.size() << std::endl;
//        adjustLayoutContent( rowheight, findOn.size() );
//    }else{
//        for( int i = 0; i < s_listElements.size(); i++ ){
//            if( s_listElements[i]->isVisible() )
//                continue;
//            s_listElements[i]->setVisible( true );
//            //send number of clients created as a second parameter
//            adjustLayoutContent( rowheight, s_listElements.size() );
//        }
//    }
//}
