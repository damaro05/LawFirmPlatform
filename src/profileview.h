#ifndef PROFILEVIEW_H
#define PROFILEVIEW_H

#include <QWidget>

namespace Ui {
class ProfileView;
}

class ProfileView : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileView(QWidget *parent = 0);
    ~ProfileView();

private:
    Ui::ProfileView *ui;
};

#endif // PROFILEVIEW_H
