#include "cmodeltableview.h"

#include <QDebug>
#include <QIdentityProxyModel>

CModelTableView::CModelTableView(QObject *parent)
    : QSqlTableModel(parent)
{
    totalHours = 0;
}


QVariant CModelTableView::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlTableModel::data( index, role );

    int row = index.row();
    int col = index.column();

    // generate a log message when this method gets called
//    qDebug() << QString("row %1, col%2, role %3")
//            .arg(row).arg(col).arg(role);


    switch( role ){
        case Qt::DisplayRole:
//            if( value.isValid() && col == 2 ){
//                qDebug() << QString("Row %1").arg( value.toString() );
//            }
        break;
        case Qt::TextAlignmentRole:
            return Qt::AlignHCenter + Qt::AlignVCenter;
        break;
    }

    return value;

}
