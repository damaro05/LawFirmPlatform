#ifndef PROFILEVIEW_H
#define PROFILEVIEW_H

#include <QWidget>
QT_FORWARD_DECLARE_CLASS( Lawyers )

namespace Ui {
class ProfileView;
}

class ProfileView : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileView(QWidget *parent = 0);
    ~ProfileView();

    void setupData( Lawyers &user );

private slots:
    void on_pushButtonSalaryFields_clicked();

private:
    void setupView();
    Ui::ProfileView *ui;
};

#endif // PROFILEVIEW_H
