#ifndef CASEHOURSVIEW_H
#define CASEHOURSVIEW_H

#include "tableviewtemplate.h"

class CaseHoursView : public TableViewTemplate
{

public:
    CaseHoursView();
    ~CaseHoursView();

    void initializeModel( QSqlTableModel* model, const QString& tablename ) override;

private:
    virtual void setupView() override;


};

#endif // CASEHOURSVIEW_H
