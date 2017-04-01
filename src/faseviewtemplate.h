#ifndef FASEVIEWTEMPLATE_H
#define FASEVIEWTEMPLATE_H

#include <QWidget>

namespace Ui {
class FaseViewTemplate;
}

class FaseViewTemplate : public QWidget
{
    Q_OBJECT

public:
    explicit FaseViewTemplate(QWidget *parent = 0);
    ~FaseViewTemplate();

private slots:
    void on_lineEditTitle_editingFinished();

private:
    Ui::FaseViewTemplate *ui;
};

#endif // FASEVIEWTEMPLATE_H
