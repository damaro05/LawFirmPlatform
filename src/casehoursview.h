#ifndef CASEHOURSVIEW_H
#define CASEHOURSVIEW_H

#include "tableviewtemplate.h"
class Cases;
class CaseHoursView : public TableViewTemplate
{

public:
    CaseHoursView();
    ~CaseHoursView();

    void initializeModel( QSqlTableModel* model, const QString& tablename ) override;
    void setupData( const Cases& currentCase );

private:
    virtual void setupView() override;



};

#endif // CASEHOURSVIEW_H
