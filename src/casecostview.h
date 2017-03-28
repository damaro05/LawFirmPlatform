#ifndef CASECOSTVIEW_H
#define CASECOSTVIEW_H
#include "tableviewtemplate.h"

class CaseCostView : public TableViewTemplate
{
public:
    CaseCostView();
    ~CaseCostView();

    void initializeModel( QSqlTableModel* model, const QString& tablename ) override;

private:
    virtual void setupView() override;
};

#endif // CASECOSTVIEW_H
