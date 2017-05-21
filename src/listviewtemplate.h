#ifndef LISTVIEWTEMPLATE_H
#define LISTVIEWTEMPLATE_H

#include <QWidget>

QT_FORWARD_DECLARE_CLASS( QLabel )
QT_FORWARD_DECLARE_CLASS( QVBoxLayout )
QT_FORWARD_DECLARE_CLASS( QHBoxLayout )
QT_FORWARD_DECLARE_CLASS( QLineEdit )
QT_FORWARD_DECLARE_CLASS( ListViewTemplateDelegate )
QT_FORWARD_DECLARE_CLASS( QListWidget )
QT_FORWARD_DECLARE_CLASS( QlistWidgetItem )

namespace Ui {
class ListViewTemplate;
}

class ListViewTemplate : public QWidget
{
    Q_OBJECT
protected:
    struct ItemList{
        ItemList( const char* name, const char* icon = NULL);
        QLabel* m_lname;
        QLabel* m_licon;
        QVBoxLayout* m_flayout;
        QHBoxLayout* m_slayout;
        QHBoxLayout* m_tlayout;
        QWidget* m_finalItem;
    };
    Ui::ListViewTemplate *ui;
    QVector< QWidget* > s_listElements;
    QVector< ItemList *> s_listItemList;

    QVBoxLayout* _scrollAreaLayout;

    QLineEdit* leSearch;
    QLabel* lbIconSearch;
    QWidget* inputSearch;

    ListViewTemplateDelegate* lvDelegate;
//    QListWidget* listWidget;
    QPixmap* listPixmap;

    void setupFilterSearch();

private:
    int contentHeight;
    bool searchFilterActive;
    QWidget* _scrollAreaContent;

public:
    QListWidget* listWidget;

    explicit ListViewTemplate(QWidget *parent = 0);
    virtual ~ListViewTemplate();

    virtual void setupView();
    void addElementList( ItemList* element );
    void addElementList( const QString &firstLable, const QString &secondLabel = NULL, const QString &img = NULL );
    void adjustLayoutContent( const int &rowHeight, int contentElements );

public slots:
    void searchOnReturnPressed();
};

#endif // LISTVIEWTEMPLATE_H
