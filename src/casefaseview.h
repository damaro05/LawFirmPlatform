#ifndef CASEFASEVIEW_H
#define CASEFASEVIEW_H

#include <QWidget>

namespace Ui {
class CaseFaseView;
}

class CaseFaseView : public QWidget
{
    Q_OBJECT

public:
    explicit CaseFaseView(QWidget *parent = 0);
    ~CaseFaseView();

private:
    Ui::CaseFaseView *ui;

    void setupView();
};

#endif // CASEFASEVIEW_H
