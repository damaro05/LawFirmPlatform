#include "clientview.h"
#include "ui_clientview.h"

#include <QVBoxLayout>
#include <QKeyEvent>
#include <QDebug>

ClientView::ClientView(QWidget *parent) : QWidget(parent), ui(new Ui::ClientView)
{
    //Initializing pointers
    ui->setupUi(this);
    _scrollAreaContent = new QWidget();
    _scrollAreaLayout = new QVBoxLayout();

    setupView();

    //--- should communicate with server and load data             ---//
    std::string nameU;
    for( int i = 0; i < 10; i++){
        nameU = std::string( "Cliente numero " ) + std::to_string( i+1 );
        loadClient( nameU.c_str() );
    }

    //Search filter
//    qApp->installEventFilter(this);
}

ClientView::~ClientView()
{
    delete ui;
    delete _scrollAreaLayout;
    delete _scrollAreaContent;
}

void ClientView::setupView()
{
    //Set scroll area content
    _scrollAreaContent->setLayout( _scrollAreaLayout );
    ui->scrollArea->setWidget( _scrollAreaContent );

    //Set scroll area content style
    _scrollAreaContent->setObjectName( "scrollAreaContent" );
    _scrollAreaContent->setStyleSheet(" QWidget#scrollAreaContent{ background-color: rgb(255, 255, 255);"
                                    "          border: 1px solid rgb(156, 208, 208);"
                                    "          border-radius: 6px } ");

}

void ClientView::loadClient( const char* clientName )
{
    QLabel* lbName = new QLabel( clientName );
    QSpacerItem* verticalSpacerName = new QSpacerItem( 10, 15, QSizePolicy::Expanding, QSizePolicy::Minimum );
    QVBoxLayout* layout1 = new QVBoxLayout();

    lbName->setMinimumSize( 250, 20 );
    lbName->setMaximumSize( 250, 20 );
    lbName->setStyleSheet(" QLabel{ color: rgb(56, 87, 88); } ");

    layout1->setSpacing(0);
    layout1->addStretch();
    layout1->setContentsMargins( 9,9,9,9 );
    layout1->SetMinimumSize;
    layout1->addWidget( lbName );
    layout1->addItem( verticalSpacerName );

//    std::string ly1Name = clientName + std::string(" layout1");
//    layout1->setObjectName( ly1Name.c_str() );

    QLabel* lbIconClient = new QLabel();
    lbIconClient->setPixmap( QPixmap(":/icons/Resources/imgs/icons/setDefault/User Filled-64.png") );
    lbIconClient->setMinimumSize( 64, 64 );
    lbIconClient->setMaximumSize( 64, 64 );

    QHBoxLayout* layout2 = new QHBoxLayout();
    layout2->addWidget( lbIconClient );
    layout2->addLayout( layout1 );

//    std::string ly2Name = clientName + std::string(" layout2");
//    layout2->setObjectName( ly2Name.c_str() );

    QSpacerItem* horizontalSpacerL = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum );
    QSpacerItem* horizontalSpacerR = new QSpacerItem( 60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    QHBoxLayout* layout3 = new QHBoxLayout();
    layout3->addItem( horizontalSpacerL );
    layout3->addLayout( layout2 );
    layout3->addItem( horizontalSpacerR );

    layout3->setSpacing(0);
    layout3->addStretch();
    layout3->setContentsMargins( 0,0,0,0 );
    layout3->SetMinimumSize;

    QWidget *finalClient = new QWidget();
    finalClient->setObjectName( clientName );
    finalClient->setLayout( layout3 );

//    std::string ly3Name = clientName + std::string(" layout3");
//    layout3->setObjectName( clientName );
//    std::cout << layout3->objectName().toStdString() << std::endl;

    _scrollAreaLayout->addWidget( finalClient );
    //Content elements minus spacer to be delete
    int elements = _scrollAreaLayout->count()-1;
    if( elements < 1) elements = 1;
    adjustLayoutContent( lbIconClient->height(), elements );

    s_clients.push_back( finalClient );
}

void ClientView::adjustLayoutContent( const int &rowHeight, int contentElements )
{

    //Delete all previous spacers in scrollAreaLayout
        for(int i = 0; i < _scrollAreaLayout->count(); i++){
            QLayoutItem* lai = _scrollAreaLayout->itemAt(i);
            if( lai->spacerItem() ){
                _scrollAreaLayout->removeItem(lai);
                delete lai;
                --i; }
        }

        //Set size for a final spacer depending of content
        int verticalSpacerHeight = _scrollAreaContent->height() - (( rowHeight * contentElements) * 1.3 );
        if( verticalSpacerHeight < 0 )
            verticalSpacerHeight = 10;
        QSpacerItem* verticalSpacer = new QSpacerItem( 20, verticalSpacerHeight, QSizePolicy::Expanding, QSizePolicy::Minimum );

        std::cout << "verticalSpacer " << verticalSpacerHeight << std::endl;
        _scrollAreaLayout->addItem( verticalSpacer );
}

void ClientView::on_lineEditSearch_returnPressed()
{
    std::cout << "Clientes: " << s_clients.size() << std::endl;
    if( !ui->lineEditSearch->text().isEmpty() ){
        QString toSee = ui->lineEditSearch->text();
        bool find = false;
        int findOn;

        for(int i = 0; i < s_clients.size(); i++){
            if( toSee != s_clients[i]->objectName() )
                continue;
            find = true;
            findOn = i;
        }
        if(find){
            for(int i = 0; i < s_clients.size(); i++){
                if( i == findOn ) {
                    s_clients[i]->setVisible(true);
                    continue;
                }
                s_clients[i]->setVisible(false);
                //Send size of found as a second parameter
                adjustLayoutContent(64,1);}

        }else{
            for(int i = 0; i < s_clients.size(); i++){
                if( s_clients[i]->isVisible() )
                    continue;
                s_clients[i]->setVisible(true);
                //Send number of Clients created as a second parameter
                adjustLayoutContent(64, _scrollAreaLayout->count() );
            }
        }
    }
}
//    std::cout << "Dentro funcion" << std::endl;
////    QWidget *toHide = _scrollAreaContent->findChild<QWidget*>( ui->lineEditSearch->text() );
////    if( toHide )
////        std::cout << "Encontrado " << toHide->objectName().toStdString() << std::endl;

//    if( !ui->lineEditSearch->text().isEmpty() )
//    {
//        QWidget* list = _scrollAreaContent->findChild< QWidget* >( ui->lineEditSearch->text() );
//        QList< QWidget* > list2 = _scrollAreaContent->findChildren< QWidget* >();
//        QList< QWidget* >::iterator i;

//        if( list ){
//            _scrollAreaLFilter->addWidget( list );
//            _scrollAreaContent2->setLayout( _scrollAreaLFilter );

//            ui->scrollArea->setWidget( _scrollAreaContent2 );
//        }else{
//            ui->scrollArea->setWidget( _scrollAreaContent );
//        }
//    }



//        for(i = list2.begin(); i != list2.end(); i++){
//            if( list ){
////                int com = QString::compare( (*i)->objectName(), list->objectName(), Qt::CaseInsensitive );
//                if ( (*i)->objectName() == list->objectName() )
//                    std::cout << "Iguales " <<  std::endl;
//            }
//        }
//    }


//bool ClientView::eventFilter(QObject *obj, QEvent *event)
//{
//    if( obj == ui->lineEditSearch && event->type() == QEvent::KeyPress ){
//        QKeyEvent* key = static_cast< QKeyEvent* >(event);
////        qDebug() << "pressed " << key->key();
////        filterSearch( *key );
//    }
//    return QObject::eventFilter( obj, event );

//}

//void ClientView::filterSearch( QKeyEvent &key )
//{
////    std::cout << "line edit " << ui->lineEditSearch->text().toStdString() << std::endl;
////    std::cout << "key pressed " << key.text().toStdString() << std::endl;

//    if( key.key() == Qt::Key_Enter ){
//        std::cout << "Enter pressed " << std::endl;

//        QList< QHBoxLayout* > list = _scrollAreaLayout->findChildren< QHBoxLayout* >();
//        QList<QHBoxLayout*>::iterator i;
//        for(i = list.begin(); i != list.end(); i++){
//            std::cout << "El objeto " << (*i)->objectName().toStdString() << " contiene " << ui->lineEditSearch->text().toStdString() << std::endl;
//            qWarning() << (*i)->objectName().contains( ui->lineEditSearch->text() );

//            if( (*i)->objectName().contains( ui->lineEditSearch->text() ) )
//                continue;

//            _scrollAreaLFilter->addItem( *i );

//        }
//        _scrollAreaContent->setLayout( _scrollAreaLFilter );
//    }
//}



