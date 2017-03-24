#ifndef CMODELTABLEVIEW_H
#define CMODELTABLEVIEW_H

#include <QSqlTableModel>

class CModelTableView : public QSqlTableModel
{
    Q_OBJECT
private:
    int totalHours;
public:
    CModelTableView(QObject *parent = 0);

    QVariant data(const QModelIndex &item, int role) const Q_DECL_OVERRIDE;
//    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

};

#endif // CMODELTABLEVIEW_H
