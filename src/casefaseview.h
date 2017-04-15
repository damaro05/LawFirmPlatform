#ifndef CASEFASEVIEW_H
#define CASEFASEVIEW_H

#include <QWidget>
QT_FORWARD_DECLARE_CLASS( QVBoxLayout )

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
    QWidget* _scrollContent;
    QVBoxLayout* _scrollLayout;
    void setupView();
};

#endif // CASEFASEVIEW_H
