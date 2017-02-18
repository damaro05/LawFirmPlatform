#ifndef NOTIFICATIONVIEW_H
#define NOTIFICATIONVIEW_H

#include <QWidget>

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

    Ui::NotificationView *ui;
};

#endif // NOTIFICATIONVIEW_H
