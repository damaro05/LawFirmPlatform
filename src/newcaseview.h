#ifndef NEWCASEVIEW_H
#define NEWCASEVIEW_H

#include <QWidget>
QT_FORWARD_DECLARE_CLASS( ClientView )
namespace Ui {
class NewCaseView;
}

class NewCaseView : public QWidget
{
    Q_OBJECT

public:
    explicit NewCaseView(QWidget *parent = 0);
    ~NewCaseView();

private slots:
    void on_pushButtonAccept_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::NewCaseView *ui;
    ClientView* _clientView;

    void setupView();
};

#endif // NEWCASEVIEW_H
