#ifndef EMPLOYES_H
#define EMPLOYES_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>

class Employes
{
    QString nom,prenom,email,role,etat_civil,sexe,date_naiss,date_1,date_2,etat_path;
    int cin,num_tel,num_aff,matricule;
    double s_base,s_brute,cnss,couverture,imposable;
public:
    //constructeurs
    Employes();
  //  Employes(int,QString,QString,QString,QString,QString,double,double,double);//paie
    Employes(int,QString,QString,QString,int,int,int,QString,QString,QString,QString);//ajout
    Employes(int ,int ,QString ,QString ,QString ,QString ,int ,int ,QString ,QString ,QString ,QString ,QString ,double ,double ,double,QString);
    //Getters
    QString getNom(){return nom;}
    QString getPrenom(){return prenom;}
    int getCIN(){return cin;}
    //setters
    void setNom(QString n){nom=n;}
    void setPrenom(QString p){prenom=p;}
    void setNom(int cin){this->cin=cin;}
    //Fonctionnalités de base relatives à l'entité employé
    bool ajouter();
    QSqlQueryModel * afficher();
     QSqlQueryModel * afficher_paie();
    bool supprimer(int);
     bool modifier(int);
      bool modifier2(int);
     bool supprimer2(QString);
     bool modifierEtat(QString);
};

#endif // EMPLOYES_H
