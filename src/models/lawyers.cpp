#include "lawyers.h"

Lawyers::Lawyers()
{

}

Lawyers::Lawyers(QString name, QString surname, QString user, QString position,
                 QString address, QString phone, QString salary, QString bankaccount,
                 QString sex, QString education, QString state, int age) :
    _name(name), _surname(surname), _user(user), _position(position), _address(address), _phone(phone),
    _salary(salary), _bankaccount(bankaccount), _sex(sex), _education(education), _state(state), _age(age)
{
}

Lawyers::Lawyers(int id, QString name, QString surname, QString user, QString position,
                 QString address, QString phone, QString salary, QString bankaccount,
                 QString sex, QString education, QString state, int age) :
    _idlawyer(id), _name(name), _surname(surname), _user(user), _position(position), _address(address), _phone(phone),
    _salary(salary), _bankaccount(bankaccount), _sex(sex), _education(education), _state(state), _age(age)
{
}

Lawyers::~Lawyers()
{

}

QString Lawyers::name() const
{
    return _name;
}

void Lawyers::setName(const QString &name)
{
    _name = name;
}

QString Lawyers::surname() const
{
    return _surname;
}

void Lawyers::setSurname(const QString &surname)
{
    _surname = surname;
}

QString Lawyers::user() const
{
    return _user;
}

void Lawyers::setUser(const QString &user)
{
    _user = user;
}

QString Lawyers::position() const
{
    return _position;
}

void Lawyers::setPosition(const QString &position)
{
    _position = position;
}

QString Lawyers::address() const
{
    return _address;
}

void Lawyers::setAddress(const QString &address)
{
    _address = address;
}

QString Lawyers::phone() const
{
    return _phone;
}

void Lawyers::setPhone(const QString &phone)
{
    _phone = phone;
}

QString Lawyers::salary() const
{
    return _salary;
}

void Lawyers::setSalary(const QString &salary)
{
    _salary = salary;
}

QString Lawyers::bankaccount() const
{
    return _bankaccount;
}

void Lawyers::setBankaccount(const QString &bankaccount)
{
    _bankaccount = bankaccount;
}

QString Lawyers::sex() const
{
    return _sex;
}

void Lawyers::setSex(const QString &sex)
{
    _sex = sex;
}

QString Lawyers::education() const
{
    return _education;
}

void Lawyers::setEducation(const QString &education)
{
    _education = education;
}

QString Lawyers::state() const
{
    return _state;
}

void Lawyers::setState(const QString &state)
{
    _state = state;
}

int Lawyers::age() const
{
    return _age;
}

void Lawyers::setAge(int age)
{
    _age = age;
}

int Lawyers::idlawyer() const
{
    return _idlawyer;
}

void Lawyers::setIdlawyer(int idlawyer)
{
    _idlawyer = idlawyer;
}

