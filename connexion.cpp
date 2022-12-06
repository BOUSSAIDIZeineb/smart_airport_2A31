#include "connexion.h"


Connexion::Connexion()
{

}

bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("Azerty123");//inserer mot de passe de cet utilisateur

if (db.open())test=true;
test=true;





    return  test;
}
void Connexion::closeConnection(){db.close();}
