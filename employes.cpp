#include "employes.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QMessageBox>
#include<QTableView>
Employes::Employes()
{
        cin=0;
        nom="";
        prenom="";
        email="";
        num_tel=0;
        num_aff=0;
        matricule=0;
        role="";
        etat_civil="";
        sexe="";
        date_naiss="";
        s_base=0;
        s_brute=0;
        cnss=0;
        couverture=0;
        imposable=0;
}
Employes::Employes(int cin,QString nom,QString prenom,QString email,int num_tel,int num_aff,int matricule,QString role,QString etat_civil,QString sexe,QString date_naiss)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->num_tel=num_tel;
    this->num_aff=num_aff;
    this->matricule=matricule;
    this->role=role;
    this->etat_civil=etat_civil;
    this->sexe=sexe;
    this->date_naiss=date_naiss;

}

Employes::Employes(int cin,int matricule,QString nom,QString prenom,QString role,QString email,int num_tel,int num_aff,QString etat_civil,QString sexe,QString date_naiss,QString date_1,QString date_2,double s_base,double s_brute,double cnss,QString etat_path)
{
    this->cin=cin;
    this->matricule=matricule;
    this->nom=nom;
    this->prenom=prenom;
    this->role=role;
    this->email=email;
    this->num_tel=num_tel;
    this->num_aff=num_aff;
    this->etat_civil=etat_civil;
    this->sexe=sexe;
    this->date_naiss=date_naiss;
    this->date_1=date_1;
    this->date_2=date_2;
    this->s_base=s_base;
    this->s_brute=s_brute;
    this->cnss=cnss;
    this->couverture=(cnss * s_brute)/100;
    this->imposable=s_brute-couverture;
    this->etat_path=etat_path;

}


bool Employes::ajouter()
{
   // bool test=false;
    QSqlQuery query;
    QString cin_string=QString::number(cin);
          query.prepare("INSERT INTO Emp (cin, nom, prenom,matricule,num_tel,num_aff,email,role,etat_civil,sexe,date_naiss) ""VALUES (:cin, :nom, :prenom,:matricule,:num_tel,:num_aff,:email,:role,:etat_civil,:sexe,:date_naiss)");
          query.bindValue(":cin", cin_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":email", email);
          query.bindValue(":num_tel", num_tel);
          query.bindValue(":num_aff", num_aff);
          query.bindValue(":matricule", matricule);
          query.bindValue(":role", role);
          query.bindValue(":etat_civil", etat_civil);
          query.bindValue(":sexe", sexe);
          query.bindValue(":date_naiss", date_naiss);


          return query.exec();
    //return test;
}

QSqlQueryModel *Employes::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select cin ,matricule ,nom ,prenom,num_tel,num_aff,email,role,etat_civil,sexe,date_naiss  from Emp");

return model;
}

QSqlQueryModel *Employes::afficher_paie()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery(" select matricule, nom, prenom, role,s_base,s_brute,cnss,couverture,imposable,date_1,date_2 ,etat_path from Emp ");

return model;
}

bool Employes::supprimer(int cin)
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);
          query.prepare("Delete from Emp where CIN=:cin");
          query.bindValue(":cin", cin_string);
          return query.exec();
}

bool Employes::modifier(int cin)
{
    QSqlQuery query;
           QString res=QString::number(cin);


             query.prepare("UPDATE Emp "" SET cin=:cin, nom=:nom, prenom=:prenom,email=:email,num_tel=:num_tel,num_aff=:num_aff,matricule=:matricule,role=:role,etat_civil=:etat_civil,sexe=:sexe,date_naiss=:date_naiss where CIN='"+res+"' ");


                   query.bindValue(":cin", res);
                   query.bindValue(":nom", nom);
                   query.bindValue(":prenom", prenom);
                   query.bindValue(":email", email);
                   query.bindValue(":num_tel", num_tel);
                   query.bindValue(":num_aff", num_aff);
                   query.bindValue(":matricule", matricule);
                   query.bindValue(":role", role);
                   query.bindValue(":etat_civil", etat_civil);
                   query.bindValue(":sexe", sexe);
                   query.bindValue(":date_naiss", date_naiss);


               return query.exec();
}
bool Employes::modifier2(int cin)
{
    QSqlQuery query;
           QString res=QString::number(cin);


             query.prepare("UPDATE Emp "" SET cin=:cin, nom=:nom, prenom=:prenom,email=:email,num_tel=:num_tel,num_aff=:num_aff,matricule=:matricule,role=:role,etat_civil=:etat_civil,sexe=:sexe,date_naiss=:date_naiss,s_base=:s_base,s_brute=:s_brute,cnss=:cnss,couverture=:couverture,imposable=:imposable,date_1=:date_1,date_2=:date_2    where matricule='"+res+"' ");


                   query.bindValue(":cin", cin);
                   query.bindValue(":nom", nom);
                   query.bindValue(":prenom", prenom);
                   query.bindValue(":email", email);
                   query.bindValue(":num_tel", num_tel);
                   query.bindValue(":num_aff", num_aff);
                    query.bindValue(":matricule", res);
                   query.bindValue(":role", role);
                   query.bindValue(":etat_civil", etat_civil);
                   query.bindValue(":sexe", sexe);
                   query.bindValue(":date_naiss", date_naiss);
                   query.bindValue(":s_base", s_base);
                   query.bindValue(":s_brute", s_brute);
                   query.bindValue(":cnss", cnss);
                   query.bindValue(":couverture", couverture);
                   query.bindValue(":imposable", imposable);
                   query.bindValue(":date_1", date_1);
                   query.bindValue(":date_2", date_2);


               return query.exec();
}
bool Employes::supprimer2(QString cin){
    QSqlQuery query;
    query.prepare("Delete from Emp where cin=:cin");
    query.bindValue(":cin", cin);
    return query.exec();
}

bool Employes::modifierEtat(QString etat_path)
{
    QSqlQuery query;



                query.prepare("UPDATE Emp SET  etat_path=:etat_path ");

                       query.bindValue(":etat_path", etat_path);




                  return query.exec();
}


