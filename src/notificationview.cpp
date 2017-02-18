#include "notificationview.h"
#include "ui_notificationview.h"

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

}

NotificationView::~NotificationView()
{
    delete ui;
}
