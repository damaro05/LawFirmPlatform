#ifndef NOTIFICATIONVIEW_H
#define NOTIFICATIONVIEW_H

#include <QWidget>

QT_FORWARD_DECLARE_CLASS( QSystemTrayIcon )

namespace Ui {
class NotificationView;
}

class NotificationView : public QWidget
{
    Q_OBJECT

public:
    ~NotificationView();
    static NotificationView* instance;
    static NotificationView* getInstance(){
        if(instance == NULL)
            instance = new NotificationView();
        return instance;
    }

private:
    explicit NotificationView(QWidget *parent = 0);
    void setupView();
    void showNotificationOnDesktop( const char* message );

    Ui::NotificationView *ui;
    QSystemTrayIcon* mSystemTryIcon;
};

#endif // NOTIFICATIONVIEW_H
