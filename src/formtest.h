#ifndef FORMTEST_H
#define FORMTEST_H

#include <QWidget>

#include <QScrollArea>

namespace Ui {
class FormTest;
}

class FormTest : public QWidget
{
    Q_OBJECT

public:
    explicit FormTest(QWidget *parent = 0);
    ~FormTest();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FormTest *ui;

    QScrollArea* sca;
};

#endif // FORMTEST_H
