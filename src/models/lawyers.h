#ifndef LAWYERS_H
#define LAWYERS_H

#include <QString>
class Lawyers
{
public:
    Lawyers();
    Lawyers(QString name, QString surname, QString user, QString position, QString address,
            QString phone, QString salary, QString bankaccount, QString sex, QString education,
            QString state, int age);

    QString name() const;
    void setName(const QString &name);

    QString surname() const;
    void setSurname(const QString &surname);

    QString user() const;
    void setUser(const QString &user);

    QString position() const;
    void setPosition(const QString &position);

    QString address() const;
    void setAddress(const QString &address);

    QString phone() const;
    void setPhone(const QString &phone);

    QString salary() const;
    void setSalary(const QString &salary);

    QString bankaccount() const;
    void setBankaccount(const QString &bankaccount);

    QString sex() const;
    void setSex(const QString &sex);

    QString education() const;
    void setEducation(const QString &education);

    QString state() const;
    void setState(const QString &state);

    int age() const;
    void setAge(int age);

private:

    QString _name;
    QString _surname;
    QString _user;
    QString _position;
    QString _address;
    QString _phone;
    QString _salary;
    QString _bankaccount;
    QString _sex;
    QString _education;
    QString _state;
    int _age;


};

#endif // LAWYERS_H
