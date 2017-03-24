#ifndef CASEHOURSVIEW_H
#define CASEHOURSVIEW_H

#include <QWidget>
QT_FORWARD_DECLARE_CLASS( QSqlTableModel )
QT_FORWARD_DECLARE_CLASS( QDialogButtonBox )

class CModelTableView;
namespace Ui {
class CaseHoursView;
}

class CaseHoursView : public QWidget
{
    Q_OBJECT

public:
    explicit CaseHoursView(QWidget *parent = 0);
    ~CaseHoursView();

private slots:
    void on_pushBtnSubmit_clicked();

    void on_pushBtnRevert_clicked();

    void on_pushBtnNewRow_clicked();

private:
    void setupView();
    void submitHours();
    void scrollToTheEnd();
    void updateTotalHours();
    void initializeModel( QSqlTableModel* model, const QString& tablename );

    bool isEmpty( int row );
    double columnSum( int columnIndex );
    Ui::CaseHoursView *ui;

    CModelTableView* model;

    QDialogButtonBox* buttonBox;
};

#endif // CASEHOURSVIEW_H
