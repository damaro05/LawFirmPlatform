#ifndef LOGIN_H
#define LOGIN_H
#include "network/restclient.h"
#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_lineEditUser_returnPressed();

    void on_lineEditPassword_returnPressed();

    void on_pbEnter_clicked();

private:
    Ui::Login *ui;
    RestClient* rClient;
};

#endif // LOGIN_H
