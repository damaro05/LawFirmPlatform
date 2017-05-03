#include "cases.h"

unsigned int Cases::numCases = 0;

Cases::Cases()
{
    //Set numCases as idcase
    numCases++;
}

Cases::Cases( QString name, QString startdate, bool state ) : _name(name), _startDate(startdate), _state(state)
{
    numCases++;

}

Cases::Cases( int id, QString name, QString startdate, bool state ) : _idcase(id), _name(name), _startDate(startdate), _state(state)
{
    numCases++;
}

Cases::~Cases()
{

}

int Cases::idcase() const
{
    return _idcase;
}

void Cases::setIdcase(int idcase)
{
    _idcase = idcase;
}

QString Cases::name() const
{
    return _name;
}

void Cases::setName(const QString &name)
{
    _name = name;
}

QString Cases::startDate() const
{
    return _startDate;
}

void Cases::setStartDate(const QString &startDate)
{
    _startDate = startDate;
}

bool Cases::state() const
{
    return _state;
}

void Cases::setState(bool state)
{
    _state = state;
}
