#ifndef LISTVIEWTEMPLATE_H
#define LISTVIEWTEMPLATE_H

#include <iostream>
#include <QWidget>
#include <QVBoxLayout>

using namespace std;
namespace Ui {
class ListViewTemplate;
}

class ListViewTemplate : public QWidget
{
    Q_OBJECT
public:
    explicit ListViewTemplate(QWidget *parent = 0);
    virtual ~ListViewTemplate();

protected:
    Ui::ListViewTemplate *TemplateUi;

private:
//    virtual void setupView();
//    virtual void loadObjList( const char* obj );

//    Ui::ListViewTemplate *ui;
    QVBoxLayout* scrollAreaLayout = new QVBoxLayout();
    QWidget* scrollAreaContent = new QWidget();
};

#endif // LISTVIEWTEMPLATE_H
