#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include<QMainWindow>
#include<QObject>
#include<QWidget>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class fournisseur
{
    QString nom, prenom, email, type_equip, type_paiem, reclam;
    int id, num_tel;
public:
    //constructers

    fournisseur();
    fournisseur(int,QString,QString,int,QString,QString,QString,QString);

    //getters
    QString getNom() {return nom;}
        QString getPrenom() {return prenom;}
        int getID(){return id;}
        int getNum_tel(){return num_tel;}
        QString getEmail(){return email;}
        QString gettype_equip(){return type_equip;}
        QString gettype_paiem(){return type_paiem;}
        QString getreclam(){return reclam;}
    //setters
        void setNom(QString n) {nom=n;}
            void setPrenom(QString p) {prenom=p;}
            void setID(int id){this->id=id;}
            void setEmail(QString E) {email=E;}
            void setnum_tel(int T) {num_tel=T;}
            void settype_equip(QString type_E) {type_equip=type_E;}
            void settype_paiem(QString type_P) {type_paiem=type_P;}
            void setreclam(QString type_R) {reclam=type_R;}
      //fonctionnalites de bases relatives
                bool ajouter();
                QSqlQueryModel * afficher();
                bool supprimer(int id);
                bool modifier(int id);
                QSqlQueryModel* rechercherdynamique(QString input, QString filtrer);









};

#endif // FOURNISSEUR_H
