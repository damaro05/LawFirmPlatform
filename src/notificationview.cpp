#include "notificationview.h"
#include "ui_notificationview.h"

#include <QSystemTrayIcon>

NotificationView* NotificationView::instance = NULL;

NotificationView::NotificationView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotificationView)
{
    instance = this;
    ui->setupUi(this);

    //Transparency and bring window to the front
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint );
//    setParent(0); // Create TopLevel-Widget
//    setAttribute(Qt::WA_NoSystemBackground, true);
//    setAttribute(Qt::WA_TranslucentBackground, true);
//    setAttribute(Qt::WA_PaintOnScreen);

    mSystemTryIcon = new QSystemTrayIcon( this );
    mSystemTryIcon->setIcon( QIcon(":/icons/Resources/imgs/icons/setDefault/18_icon-icons.com_73792.png") );
    mSystemTryIcon->setVisible( true );

    //setup list widget
    ui->listWidget->setSelectionMode( QAbstractItemView::SingleSelection );

    setupView();
}

NotificationView::~NotificationView()
{
    delete ui;
}

void NotificationView::setupView()
{
    QString notification = "No hay notificaciones";
    new QListWidgetItem( notification, ui->listWidget );
    showNotificationOnDesktop( notification.toStdString().c_str() );
}

void NotificationView::showNotificationOnDesktop( const char* message )
{
    mSystemTryIcon->showMessage( "Notificación", message );
}
