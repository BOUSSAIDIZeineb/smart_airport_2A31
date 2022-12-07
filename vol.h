#ifndef VOL_H
#define VOL_H
#include<QString>
#include<QSqlQueryModel>
#include<QTableView>
#include<QMessageBox>
#include<QSqlQuery>
#include <QSqlQueryModel>
class vol
{
    int NUM_VOL;
    QString DESTINATION;
    QString DATE_DEPART;
    QString DATE_ARRIVE;
    int NBR_PLACE;
    QString NOM_COMPAGNIE;
public:
    vol();
    vol(int,int,QString ,QString ,QString ,QString );
    int getNUM_VOL(){return NUM_VOL;}
    int getNBR_place(){return NBR_PLACE;}
    QString getDESTINATION(){return DESTINATION;}
    QString getDate_Depart(){return DATE_DEPART;}
    QString getDate_arrive(){return DATE_ARRIVE;}
    QString getnom_compagnie(){return NOM_COMPAGNIE;}

    void setNUM_VOL( int num){NUM_VOL=num;}
    void setNBR_place( int nbr){NBR_PLACE=nbr;}
    void  setDESTINATION(QString d){DATE_DEPART=d;}
    void  setDate_Depart(QString dd){ DATE_DEPART=dd;}
    void setDate_arrive(QString da ){ DATE_ARRIVE=da;}
    void setnom_compagnie(QString nom){ NOM_COMPAGNIE=nom;}
QString returnDate(QString);
      bool ajouter();
      QSqlQueryModel* afficher();
      bool supprimer(int);
      bool modifier();
      QSqlQueryModel *trier();
      QSqlQueryModel * chercher(QString NOM_COMPAGNIE);
       QSqlQueryModel *triera();
};

#endif // VOL_H
