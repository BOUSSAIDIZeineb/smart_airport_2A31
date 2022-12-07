
#include "voyageur.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QDebug>
#include <qdebug.h>
#include <string>
#include <notif.h>
using namespace std;
QT_CHARTS_USE_NAMESPACE
Voyageur::Voyageur()
{
    id=0;
    nom="";
    prenom="";
    mois="";
}
Voyageur::Voyageur(int id,QString nom,QString prenom,QString mois,QString date)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->mois=mois;
this->date=date;
}
bool Voyageur::ajouter()
{

   // bool test=false;

    QSqlQuery query;
    QString id_string=QString::number(id);
          query.prepare("INSERT INTO voyageur (id, nom, prenom,mois,Datee,etat) ""VALUES (:id, :forename, :surname, :month,To_date(:date,'dd/MM/yyyy'),0)");
          query.bindValue(":id", id_string);
          query.bindValue(":forename", nom);
          query.bindValue(":surname", prenom);
          query.bindValue(":month", mois);
query.bindValue(":date", date);
          return query.exec();
    //return test;
}






QSqlQueryModel *Voyageur::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from voyageur");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("mois"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de voyage"));
return model;
}


bool Voyageur::supprimer(int id)
{
    QSqlQuery query;
    QString id_string=QString::number(id);
          query.prepare("Delete from voyageur where ID=:id");
          query.bindValue(":id", id_string);
          return query.exec();
}

bool Voyageur::modifier(int id)
{
    QSqlQuery query;
           QString res=QString::number(id);


             query.prepare("UPDATE voyageur "" SET id=:id, nom=:nom, prenom=:prenom, mois=:mois, datee = :date where ID='"+res+"' ");


                   query.bindValue(":id", res);
                   query.bindValue(":nom", nom);
                   query.bindValue(":prenom", prenom);
                   query.bindValue(":mois", mois);
                   query.bindValue(":datee", date);

               return query.exec();
}

QSqlQueryModel *Voyageur::chercher(int id)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QString str ;
    //Connexion Conn;
    //Conn.ouvrirConnexion();
    //Conn.openBD();
    if(id== NULL){
        str="SELECT * FROM  voyageur";
    }

         str="select * from voyageur where id ="+QString::number(id);
        model->setQuery(str);
    //Conn.fermerConnexion() ;
        return model;

}

QSqlQueryModel *Voyageur::sortid()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from voyageur ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mois"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date_voyage"));
    return model;
}


QSqlQueryModel *Voyageur::sortid2()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from voyageur ORDER BY nom ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mois"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date_voyage"));
    return model;
}

QSqlQueryModel *Voyageur::sortid3()
{

    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from voyageur ORDER BY prenom ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mois"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date_voyage"));
    return model;
}



QChart * Voyageur::stat(){

    QSqlQuery q,q1,q2,q3,q4,q5,q6,q7,q8,q9,q10,q11,q12;
    q.exec("Select * from voyageur");
    int tot=0;
    while (q.next())
        tot++;
   qDebug() << "total =" << tot;
    q1.prepare("Select * from voyageur where mois = :nom ");
    q1.bindValue(":nom","Janvier");
    q1.exec();

    int tot_jan=0;
    while (q1.next())
        tot_jan++;
 qDebug() << "pourcentage don =" << tot_jan;
    qreal pour_jan=(tot_jan*100)/tot;

    q2.prepare("Select * from voyageur where mois = :nom ");
    q2.bindValue(":nom","Fevrier");
    q2.exec();
    int tot_fev=0;
    while (q2.next())
        tot_fev++;

    qreal pour_fev=(tot_fev*100)/tot;

    q3.prepare("Select * from voyageur where mois = :nom ");
    q3.bindValue(":nom","Mars");
    q3.exec();
    int tot_mars=0;
    while (q3.next())
        tot_mars++;
    qreal pour_mars=(tot_mars*100)/tot;

    q4.prepare("Select * from voyageur where mois = :nom ");
    q4.bindValue(":nom","Avril");
    q4.exec();
    int tot_av=0;
    while (q4.next())
        tot_av++;
    qreal pour_av=(tot_av*100)/tot;

    q5.prepare("Select * from voyageur where mois = :nom ");
    q5.bindValue(":nom","Mai");
    q5.exec();
    int tot_mai=0;
    while (q5.next())
        tot_mai++;
    qreal pour_mai=(tot_mai*100)/tot;
    q6.prepare("Select * from voyageur where mois = :nom ");
    q6.bindValue(":nom","Juin");
    q6.exec();
    int tot_juin=0;
    while (q6.next())
        tot_juin++;
    qreal pour_juin=(tot_juin*100)/tot;
    q7.prepare("Select * from voyageur where mois = :nom ");
    q7.bindValue(":nom","Juillet");
    q7.exec();
    int tot_Juillet=0;
    while (q7.next())
        tot_Juillet++;
    qreal pour_Juil=(tot_Juillet*100)/tot;
    q8.prepare("Select * from voyageur where mois = :nom ");
    q8.bindValue(":nom","Aout");
    q8.exec();
    int tot_aou=0;
    while (q8.next())
        tot_aou++;
    qreal pour_aou=(tot_aou*100)/tot;
    q9.prepare("Select * from voyageur where mois = :nom ");
    q9.bindValue(":nom","Septembre");
    q9.exec();
    int tot_sep=0;
    while (q9.next())
        tot_sep++;
    qreal pour_sep=(tot_sep*100)/tot;
    q10.prepare("Select * from voyageur where mois = :nom ");
    q10.bindValue(":nom","Octobre");
    q10.exec();
    int tot_oct=0;
    while (q10.next())
        tot_oct++;
    qreal pour_oct=(tot_oct*100)/tot;
    q11.prepare("Select * from voyageur where mois = :nom ");
    q11.bindValue(":nom","Novembre");
    q11.exec();
    int tot_nov=0;
    while (q11.next())
        tot_nov++;
    qreal pour_nov=(tot_nov*100)/tot;
    q12.prepare("Select * from voyageur where mois = :nom ");
    q12.bindValue(":nom","Decembre");
    q12.exec();
    int tot_dec=0;
    while (q12.next())
        tot_dec++;
    qreal pour_dec=(tot_dec*100)/tot;
    QPieSeries *series = new QPieSeries();
     series->append("Janvier",pour_jan);
     series->append("Fevrier",pour_fev);
     series->append("Mars",pour_mars);
     series->append("Avril",pour_av);
     series->append("Mai",pour_mai);
     series->append("Juin",pour_juin);
     series->append("Juillet",pour_Juil);
     series->append("Aout",pour_aou);
     series->append("Septembre",pour_sep);
     series->append("Octobre",pour_oct);
     series->append("Novembre",pour_nov);
     series->append("Decembre",pour_dec);
     QPieSlice *slice0= series->slices().at(0);
     slice0->setLabelVisible();
     QPieSlice *slice1 = series->slices().at(1);

     slice1->setLabelVisible();

     slice1->setBrush(Qt::green);

     QPieSlice *slice2= series->slices().at(2);
     slice2->setLabelVisible();
      slice2->setBrush(Qt::red);
     QPieSlice *slice3= series->slices().at(3);
     slice3->setLabelVisible();
      slice3->setBrush(Qt::yellow);
     QPieSlice *slice4= series->slices().at(4);
     slice4->setLabelVisible();
      slice4->setBrush(Qt::blue);
      QPieSlice *slice5= series->slices().at(5);
      slice5->setLabelVisible();
      QPieSlice *slice6= series->slices().at(6);
      slice6->setLabelVisible();
      QPieSlice *slice7= series->slices().at(7);
      slice7->setLabelVisible();
      QPieSlice *slice8= series->slices().at(8);
      slice8->setLabelVisible();
      QPieSlice *slice9= series->slices().at(9);
      slice9->setLabelVisible();
      QPieSlice *slice10= series->slices().at(10);
      slice10->setLabelVisible();
      QPieSlice *slice11= series->slices().at(11);
      slice11->setLabelVisible();


     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Nombre des voyageurs par mois");
     chart->legend()->hide();

    return chart;


}
QSqlQueryModel *Voyageur::historique(){


    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("Select * from voyageur where datee< sysdate");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("mois"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date_voyage"));
    return model;



}
QSqlQueryModel * Voyageur::Notification(){

    QSqlQuery q1,q2,q3;
    q1.prepare("SELECT * FROM VOYAGEUR where datee< sysdate");
    q1.exec();

    int total=0;
    while(q1.next())
    {
        total++;

    }
QString ch=QString::number(total);
notif *n= new notif("Alerte","il y'a "+ch+" voyageurs que leur date a depassé");
n->afficher();
        QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery(q1);
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("mois"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date_voyage"));
        return model;



}

