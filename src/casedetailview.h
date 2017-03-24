#ifndef CASEDETAILVIEW_H
#define CASEDETAILVIEW_H

#include <QWidget>

namespace Ui {
class CaseDetailView;
}

class CaseDetailView : public QWidget
{
    Q_OBJECT

public:
    explicit CaseDetailView(const QString& caseName, QWidget *parent = 0);
    ~CaseDetailView();

private:
    void setupView();
    void loadClientList();

    Ui::CaseDetailView *ui;
};

#endif // CASEDETAILVIEW_H
