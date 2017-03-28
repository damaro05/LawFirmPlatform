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

    query.exec( "create table CostTest (fecha varchar(20) primary key, concepto varchar(20), importe int, doc varchar(20), estado int)" );
    query.exec( "insert into CostTest values('12-01-2016', 'Importe pagado al señor Gimenez por su representación en el juicio', 200, 'doc', 1)" );
    query.exec( "insert into CostTest values('14-03-2016', 'Apostillamiento de documentos', 300, 'no doc', 1)" );
    query.exec( "insert into CostTest values('01-02-2016', 'Notario', 250, 'doc', 2)" );
    query.exec( "insert into CostTest values('22-01-2016', 'Contratación de un experto para un juicio (tasación de cuadros)', 500, 'doc', 1)" );


    return true;
}

#endif // CONNECTIONCACHE_H
