#ifndef CASEDETAILVIEW_H
#define CASEDETAILVIEW_H

#include <QWidget>
QT_FORWARD_DECLARE_CLASS( Cases )
namespace Ui {
class CaseDetailView;
}

class CaseDetailView : public QWidget
{
    Q_OBJECT

public:
    explicit CaseDetailView( const Cases& currentCase, QWidget *parent = 0 );
    ~CaseDetailView();

private:
    void setupView();
    void setupData( const Cases& currentCase );
    void loadClientList();

    Ui::CaseDetailView *ui;
};

#endif // CASEDETAILVIEW_H
