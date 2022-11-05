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
bool Employes::ajouter()
{
   // bool test=false;
    QSqlQuery query;
    QString cin_string=QString::number(cin);
          query.prepare("INSERT INTO Emp (cin, nom, prenom,matricule,num_tel,num_aff,email,role,etat_civil,sexe,date_naiss) ""VALUES (:cin, :nom, :prenom,:matricule,:num_tel,:num_aff,:email,:role,:etat_civil,:sexe,:date_naiss)"); //INSERT INTO emp VALUES (val cin, nom,prenom)meme ordre que le table
          query.bindValue(":cin", cin_string); //relier la valeur a la variable  d'une maniere securisé(:) //remplir la val de la requette sql
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
model->setQuery("select * from Emp");   // au lieu de (* tous)ou dans un ordre specifique    select cin,num from Emp  (lecture de colone)  select from Emp where nom=zeineb
/*
 * model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Prenom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("matricule"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("num_tel"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("num_aff"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("role"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("etat_civil"));
*/
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
////////////////////////////
bool Employes::supprimer2(QString cin){
    QSqlQuery query;
    query.prepare("Delete from Emp where cin=:cin");
    query.bindValue(":cin", cin);
    return query.exec();
}


// trie :"asc" ascendant... "desc" descendant ..........."sorting enabled" Qtableview
//selected la cle primaire
//printsupport pdf
//video intro
//chouf readme   smp.h copy paste badel l mail fl code  temchi l gmail gerer votre compte
//importer excel spanish man
