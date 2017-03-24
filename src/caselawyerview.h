#ifndef CASELAWYERVIEW_H
#define CASELAWYERVIEW_H
#include "lawyerview.h"

class CaseLawyerView : public LawyerView
{
public:
    CaseLawyerView();
    ~CaseLawyerView();

private:
    void setupView();
};

#endif // CASELAWYERVIEW_H
