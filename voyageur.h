#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include<QSqlQuery>
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
QT_CHARTS_USE_NAMESPACE
class Voyageur
{
    QString nom,prenom,mois,date;
    int id;
public:
    //constructeurs

    Voyageur();
    Voyageur(int,QString,QString,QString,QString);
    //Getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    QString getmois(){return mois;}

    int getID(){return id;}

    //setters
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setmois(QString m){mois=m;}


    void setid(int id){this->id=id;}
    QSqlQueryModel *chercher(int);
    QSqlQueryModel *sortid();
    QSqlQueryModel *sortid2();
    QSqlQueryModel *sortid3();


    void on_PDF_clicked();
QSqlQueryModel *historique();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(int);
     bool verifier(int id);
     QChart *stat ();
QSqlQueryModel *Notification();
};

#endif // VOYAGEUR_H

