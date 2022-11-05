#ifndef EMPLOYES_H
#define EMPLOYES_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>

class Employes
{
    QString nom,prenom,email,role,etat_civil,sexe,date_naiss;
    int cin,num_tel,num_aff,matricule;
public:
    //constructeurs
    Employes();
    Employes(int,QString,QString,QString,int,int,int,QString,QString,QString,QString);
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
    bool supprimer(int);
     bool modifier(int);
     bool supprimer2(QString);

};

#endif // EMPLOYES_H
