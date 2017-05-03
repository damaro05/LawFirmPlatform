#ifndef CASEVIEW_H
#define CASEVIEW_H

#include <QWidget>
#include <QIcon>
#include <QMap>
QT_FORWARD_DECLARE_CLASS( CaseFaseView )
QT_FORWARD_DECLARE_CLASS( CaseHoursView )
QT_FORWARD_DECLARE_CLASS( CaseLawyerView )
QT_FORWARD_DECLARE_CLASS( CaseDocView )
QT_FORWARD_DECLARE_CLASS( CaseCostView )
QT_FORWARD_DECLARE_CLASS( CaseDetailView )
QT_FORWARD_DECLARE_CLASS( QSortFilterProxyModel )
QT_FORWARD_DECLARE_CLASS( RestClient )
QT_FORWARD_DECLARE_CLASS( MainWindow )


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
    void loadListAllCases();
//    void loadListUserCases();

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

    MainWindow* mWindow;
    RestClient* restClient;

    //Pair posicion array mWindow y idCase. current case sera la posicon del array de mwindow
    QMap<QString, int> caseIdMap;
    QMap<int, QString> accessByIdCase;
};

#endif // CASEVIEW_H
