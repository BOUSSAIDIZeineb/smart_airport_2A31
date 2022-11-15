#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
    //QSqlQuery *query = new QSqlQuery(db);

    QSqlDatabase db;
public:
    Connection();
    bool createconnection();
    void closeconnection();
};

#endif // CONNECTION_H
