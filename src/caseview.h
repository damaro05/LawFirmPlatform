#ifndef CASEVIEW_H
#define CASEVIEW_H

#include <QWidget>
#include <QIcon>
class CaseLawyerView;
class CaseDetailView;
QT_FORWARD_DECLARE_CLASS( QSortFilterProxyModel )

namespace Ui {
class CaseView;
}

class CaseView : public QWidget
{
    Q_OBJECT

public:
    explicit CaseView(QWidget *parent = 0);
    ~CaseView();

private slots:
    void updateListFilter( const QString& filterString );
    void updateListFilterOthers( const QString& filterString );
    void on_listViewOwnCases_doubleClicked(const QModelIndex &index);

    void on_listViewOtherCases_doubleClicked(const QModelIndex &index);

private:
    void setupView();
    void loadListUserCases();
    void loadListAllCases();

    void loadLawyerView();
    void loadDetailView();

    void loadCase( const QString& title );

    Ui::CaseView *ui;
    QSortFilterProxyModel* proxyModel;
    QSortFilterProxyModel* proxyModelOthers;

    CaseLawyerView* lawyerView;
    CaseDetailView* detailView;

    QIcon faseIcon;
    QIcon hourIcon;
    QIcon lawyerIcon;
    QIcon docIcon;
    QIcon costIcon;
    QIcon detailIcon;
};

#endif // CASEVIEW_H
