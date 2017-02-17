#include "listviewtemplate.h"
#include "ui_listviewtemplate.h"
#include <iostream>

#include <QVBoxLayout>
#include <QKeyEvent>
#include <QDebug>
using namespace std;
/*
        Falta el control de punteros para las estructuras y los vectores de la clase
*/
////------------ Struct ItemList  -----------------------------------------------------------//
ListViewTemplate::ItemList::ItemList(const char* name, const char* icon): m_lname(new QLabel(name))
{
    m_flayout = new QVBoxLayout();
    QSpacerItem* vsFirstLay = new QSpacerItem( 10, 15, QSizePolicy::Expanding, QSizePolicy::Minimum );
    m_lname->setMinimumSize( 250, 20 );
    m_lname->setMaximumSize( 250, 20 );
    m_lname->setStyleSheet(" QLabel{ color: rgb(56, 87, 88); } ");

    m_flayout->setSpacing(0);
    m_flayout->addStretch();
    m_flayout->setContentsMargins( 9,9,9,9 );
    m_flayout->SetMinimumSize;
    m_flayout->addWidget( m_lname );
    m_flayout->addItem( vsFirstLay );
    std::string ly1Name = std::string("FirstLayout ") + name;
    m_flayout->setObjectName( ly1Name.c_str() );

    m_licon = new QLabel();
    if( !icon )
        icon = ":/icons/Resources/imgs/icons/setDefault/User Filled-64.png";
    m_licon->setPixmap( QPixmap( icon ) );
    m_licon->setMinimumSize( 64, 64 );
    m_licon->setMaximumSize( 64, 64 );

    m_slayout = new QHBoxLayout();
    m_slayout->addWidget( m_licon );
    m_slayout->addLayout( m_flayout );
    std::string ly2Name = std::string("SecondLayout ") +  name;
    m_slayout->setObjectName( ly2Name.c_str() );

    QSpacerItem* hsLSecondLay = new QSpacerItem( 20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum );
    QSpacerItem* hsRSecondLay = new QSpacerItem( 60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum );
    m_tlayout = new QHBoxLayout();
    m_tlayout->addItem( hsLSecondLay );
    m_tlayout->addLayout( m_slayout );
    m_tlayout->addItem( hsRSecondLay );
    m_tlayout->setSpacing(0);
    m_tlayout->addStretch();
    m_tlayout->setContentsMargins( 0,0,0,0 );
    m_tlayout->SetMinimumSize;
    std::string ly3Name = std::string("ThirdLayout ") +  name;
    m_tlayout->setObjectName( ly3Name.c_str() );

    m_finalItem = new QWidget();
    m_finalItem->setObjectName( name );
    m_finalItem->setLayout( m_tlayout );

}

////------------ End Struct ItemList  ------------------------------------------------------//


ListViewTemplate::ListViewTemplate(QWidget *parent) : QWidget(parent), ui(new Ui::ListViewTemplate)
{
    std::cout << "Constractor " << typeid(this).name() << std::endl;
    ui->setupUi( this );
    _scrollAreaContent = new QWidget();
    _scrollAreaLayout = new QVBoxLayout();

    setupView();

    //Search filter
//    qApp->installEventFilter(this);
}


ListViewTemplate::~ListViewTemplate()
{
    std::cout << "Destructor " << typeid(this).name() << std::endl;
    delete ui;
    delete _scrollAreaLayout;
    delete _scrollAreaContent;
}

void ListViewTemplate::setupView()
{
    //Set scroll area content
    _scrollAreaContent->setLayout( _scrollAreaLayout );
    ui->mainScrollArea->setWidget( _scrollAreaContent );

    //Set scroll area content style
    _scrollAreaContent->setObjectName( "scrollAreaContent" );
    _scrollAreaContent->setStyleSheet(" QWidget#scrollAreaContent{ background-color: rgb(255, 255, 255);"
                                    "          border: 1px solid rgb(156, 208, 208);"
                                    "          border-radius: 6px } ");

}

void ListViewTemplate::addElementList( ItemList* element )
{

    //recbe una struct y la agrega al scroll area
    //Final cliente es m_finalItem
    _scrollAreaLayout->addWidget( element->m_finalItem );
    //Content elements minus spacer to be delete
    int elements = _scrollAreaLayout->count()-1;
    if( elements < 1) elements = 1;
    adjustLayoutContent( element->m_licon->height(), elements );

    s_listItemList.push_back( element );
    s_listElements.push_back( element->m_finalItem );
}

void ListViewTemplate::adjustLayoutContent( const int &rowHeight, int contentElements )
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
        _scrollAreaLayout->addItem( verticalSpacer );
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

