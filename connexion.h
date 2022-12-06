#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connexion
{
    QSqlDatabase db;
public:
    Connexion();
    bool createconnect();
    void closeConnection();
};

#endif // CONNECTION_H
//0/55/44/77/22
