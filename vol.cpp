#include "vol.h"
#include<QSqlQueryModel>
vol::vol()
{
       NUM_VOL=0;
       DESTINATION="";
       DATE_DEPART="";
       DATE_ARRIVE="";
       NBR_PLACE=0;
       NOM_COMPAGNIE="";
}


vol::vol(int,int,QString ,QString ,QString ,QString )
{
     this->NUM_VOL=NUM_VOL;
     this->NBR_PLACE=NBR_PLACE;
     this->DESTINATION=DESTINATION;
     this->DATE_ARRIVE=DATE_ARRIVE;
     this->DATE_DEPART=DATE_DEPART;
     this-> NOM_COMPAGNIE= NOM_COMPAGNIE;
 }


QString vol::returnDate(QString id){
    QSqlQuery q("select * from vol where num_vol="+id);
    while(q.next()){
        return q.value(2).toString();
    }
    return "";
}

bool vol::ajouter()
{
  QSqlQuery query;
  QString num=QString::number(NUM_VOL);
  query.prepare("insert into  VOL (NUM_VOL,DESTINATION,DATE_DEPART,DATE_ARRIVE,NBR_PLACE,NOM_COMPAGNIE)"  "values(:NUM_VOL, :DESTINATION, :DATE_DEPART, :DATE_ARRIVE, :NBR_PLACE, :NOM_COMPAGNIE)");
  query.bindValue(":NUM_VOL",NUM_VOL );
  query.bindValue(":DESTINATION",DESTINATION );
  query.bindValue(":DATE_DEPART",DATE_DEPART );
  query.bindValue(":DATE_ARRIVE",DATE_ARRIVE);
  query.bindValue(":NBR_PLACE",NBR_PLACE);
   query.bindValue(":NOM_COMPAGNIE",NOM_COMPAGNIE);
  return query.exec();
}

bool vol::supprimer(int)
{
    QSqlQuery query;

        query.prepare("Delete from  VOL where NUM_VOL=:NUM_VOL");
        query.bindValue(":NUM_VOL", NUM_VOL);
        return query.exec();


    }


bool vol::modifier()
{

    QSqlQuery query;
            QString num=QString::number(NUM_VOL);

query.prepare("UPDATE VOL SET  NUM_VOL=:NUM_VOL,DESTINATION=:DESTINATION,DATE_DEPART=:DATE_DEPART,DATE_ARRIVE=:DATE_ARRIVE ,NBR_PLACE=:NBR_PLACE ,NOM_COMPAGNIE=:NOM_COMPAGNIE WHERE NUM_VOL=:NUM_VOL" );

query.bindValue(":NUM_VOL",NUM_VOL );
query.bindValue(":DESTINATION",DESTINATION );
query.bindValue(":DATE_DEPART",DATE_DEPART );
query.bindValue(":DATE_ARRIVE",DATE_ARRIVE );
query.bindValue(":NBR_PLACE",NBR_PLACE);
query.bindValue(":NOM_COMPAGNIE",NOM_COMPAGNIE);

            return query.exec();



}

QSqlQueryModel* vol::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;
    model->setQuery("SELECT* FROM VOL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_VOL"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESTINATION"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATE_DEPART"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_ARRIVE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBR_PLACE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NOM_COMPAGNIE"));

       return model;

}
QSqlQueryModel * vol::trier()
{
     //ml Z-A
    {

               QSqlQuery * q = new  QSqlQuery ();
                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("SELECT * from vol order by NOM_COMPAGNIE DESC");
                      q->exec();
                      model->setQuery(*q);
                      return model;
    }
}
QSqlQueryModel *vol::chercher(QString NOM_COMPAGNIE )
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from VOL where NOM_COMPAGNIE like '" +NOM_COMPAGNIE+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUM_VOL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESTINATION"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATE_DEPART"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_COMPAGNIE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_ARRIVE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("NBR_PLACE"));

    return model;
}


/*QSqlQueryModel * vol:: *triera()


{

           QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * from vol order by NOM_COMPAGNIE ASC");
                  q->exec();
                  model->setQuery(*q);
                   return model;

}*/
