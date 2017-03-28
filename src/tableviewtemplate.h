#ifndef TABLEVIEWTEMPLATE_H
#define TABLEVIEWTEMPLATE_H

#include <QWidget>
QT_FORWARD_DECLARE_CLASS( QSqlTableModel )
QT_FORWARD_DECLARE_CLASS( QDialogButtonBox )

class CModelTableView;
namespace Ui {
class TableViewTemplate;
}

class TableViewTemplate : public QWidget
{
    Q_OBJECT

protected:
    int sumColumn;
    Ui::TableViewTemplate *ui;
    CModelTableView* model;
    QDialogButtonBox* buttonBox;

public:
    explicit TableViewTemplate(QWidget *parent = 0);
    virtual ~TableViewTemplate();
    virtual void initializeModel( QSqlTableModel* model, const QString& tablename ) = 0;
    virtual void setupView() = 0;
    void updateTotalHours();

private slots:

    void on_pushBtnSubmit_clicked();

    void on_pushBtnRevert_clicked();

    void on_pushBtnNewRow_clicked();

private:

    void submitChanges();
    void scrollToTheEnd();

    bool isEmpty( int row );
    double columnSum( int columnIndex );

};

#endif // TABLEVIEWTEMPLATE_H
