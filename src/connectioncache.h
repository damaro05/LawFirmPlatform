#ifndef CONNECTIONCACHE_H
#define CONNECTIONCACHE_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( ":memory:" );
    if( !db.open() ){
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
                  qApp->tr("Unable to establish a database connection.\n"
                           "This example needs SQLite support. Please read "
                           "the Qt SQL driver documentation for information how "
                           "to build it.\n\n"
                           "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;

    query.exec( "create table HoursTest (fecha varchar(20) primary key, usuario varchar(20), horas int)" );
    query.exec( "insert into HoursTest values('20-03-2017', 'Marina Mancho', 3)" );
    query.exec( "insert into HoursTest values('21-03-2017', 'Sebastia Maya', 8)" );

    return true;
}

#endif // CONNECTIONCACHE_H
