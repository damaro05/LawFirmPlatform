#ifndef CASES_H
#define CASES_H

#include <QString>

class Cases
{
public:
    static unsigned int numCases;
    Cases();
    Cases( QString name, QString startdate, bool state = false );
    Cases( int id, QString name, QString startdate, bool state = false );
    ~Cases();

    int idcase() const;
    void setIdcase(int idcase);

    QString name() const;
    void setName(const QString &name);

    QString startDate() const;
    void setStartDate(const QString &startDate);

    bool state() const;
    void setState(bool state);

private:
    int _idcase;
    QString _name;
    QString _startDate;
    bool _state;

};

#endif // CASES_H
