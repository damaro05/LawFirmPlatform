#ifndef LAWYERVIEW_H
#define LAWYERVIEW_H

#include <QWidget>

QT_FORWARD_DECLARE_CLASS( QVBoxLayout )

using namespace std;
namespace Ui {
class LawyerView;
}

class LawyerView : public QWidget
{
    Q_OBJECT

public:
    explicit LawyerView(QWidget *parent = 0);
    ~LawyerView();

private:
    void setupView();
    void loadLawyer( const char* lawyerName, const char* lawyerPosition );

    Ui::LawyerView *ui;

    QVBoxLayout* _scrollAreaLayout;
    QWidget* _scrollAreaContent;
};

#endif // LAWYERVIEW_H
