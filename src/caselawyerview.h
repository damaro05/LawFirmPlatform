#ifndef CASELAWYERVIEW_H
#define CASELAWYERVIEW_H

#include "lawyerview.h"
class Cases;
class CaseLawyerView : public LawyerView
{
public:
    CaseLawyerView();
    ~CaseLawyerView();

    void setupView();
    void setupData( const Cases& currentCase );
};

#endif // CASELAWYERVIEW_H
