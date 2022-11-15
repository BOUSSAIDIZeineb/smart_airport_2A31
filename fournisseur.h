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
    int id, num_tel,nb_equip,prix;
public:
    //constructers

    fournisseur();
    fournisseur(int,QString,QString,int,QString,QString,QString,QString,
                int,int);
    fournisseur(int,QString,QString,int,QString,QString,QString,int,int);
    fournisseur(QString);
    //getters
    QString getNom() {return nom;}
        QString getPrenom() {return prenom;}
        int getID(){return id;}
        int getNum_tel(){return num_tel;}
        QString getEmail(){return email;}
        QString gettype_equip(){return type_equip;}
        QString gettype_paiem(){return type_paiem;}
        QString getreclam(){return reclam;}
        int getNb_equip(){return nb_equip;}
        int getprix(){return prix;}
    //setters
        void setNom(QString n) {nom=n;}
            void setPrenom(QString p) {prenom=p;}
            void setID(int id){this->id=id;}
            void setEmail(QString E) {email=E;}
            void setnum_tel(int T) {num_tel=T;}
            void settype_equip(QString type_E) {type_equip=type_E;}
            void settype_paiem(QString type_P) {type_paiem=type_P;}
            void setreclam(QString type_R) {reclam=type_R;}
            void setNb_equip(int nb) {nb_equip=nb;}
            void setprix(int pr) {prix=pr;}
      //fonctionnalites de bases relatives
                bool ajouter();
                QSqlQueryModel * afficher();
                bool supprimer(int id);
                bool modifier(int id);
                QSqlQueryModel* rechercherdynamique(QString input, QString filtrer);
                QSqlQuery login();
                int dist_prix();
                QStringList count_prix();
                bool ajouterReclam(int,int,QString);
                QSqlQueryModel * afficherReclam(int);







};

#endif // FOURNISSEUR_H
