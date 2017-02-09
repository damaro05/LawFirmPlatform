#ifndef PROFILEVIEW_H
#define PROFILEVIEW_H

#include <QWidget>
#include <QDialogButtonBox>
#include <QEvent>

namespace Ui {
class ProfileView;
}

class ProfileView : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileView(QWidget *parent = 0);
    ~ProfileView();

private slots:
    void on_pushButtonSalaryFields_clicked();

private:
    Ui::ProfileView *ui;
};

#endif // PROFILEVIEW_H
