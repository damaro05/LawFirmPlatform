#ifndef LISTVIEWTEMPLATEDELEGATE_H
#define LISTVIEWTEMPLATEDELEGATE_H

#include <QPainter>
#include <QAbstractItemDelegate>
#include <QSortFilterProxyModel>

class ListViewTemplateDelegate : public QAbstractItemDelegate
{
public:
    ListViewTemplateDelegate(QObject* parent = 0);

    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;

    virtual ~ListViewTemplateDelegate();
};

#endif // LISTVIEWTEMPLATEDELEGATE_H
