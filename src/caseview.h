#ifndef CASEVIEW_H
#define CASEVIEW_H

#include <QWidget>
#include <QIcon>
class CaseFaseView;
class CaseHoursView;
class CaseLawyerView;
class CaseDocView;
class CaseCostView;
class CaseDetailView;
QT_FORWARD_DECLARE_CLASS( QSortFilterProxyModel )
QT_FORWARD_DECLARE_CLASS( RestClient )


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

    void loadFaseView();
    void LoadHoursView();
    void loadLawyerView();
    void loadDocView();
    void loadCostView();
    void loadDetailView();

    void loadCase( const QString& title );

    Ui::CaseView *ui;
    QSortFilterProxyModel* proxyModel;
    QSortFilterProxyModel* proxyModelOthers;

    CaseFaseView* faseView;
    CaseHoursView* hoursView;
    CaseLawyerView* lawyerView;
    CaseDocView* docView;
    CaseCostView* costView;
    CaseDetailView* detailView;

    QIcon faseIcon;
    QIcon hoursIcon;
    QIcon lawyerIcon;
    QIcon docIcon;
    QIcon costIcon;
    QIcon detailIcon;

    RestClient* restClient;
};

#endif // CASEVIEW_H
