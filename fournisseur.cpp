#include "fournisseur.h"

fournisseur::fournisseur()
{

}
fournisseur::fournisseur(int id,QString nom,QString prenom,int num_tel,QString email,QString type_equip,QString type_paiem,QString reclam)
{
        this->id=id;
        this->nom=nom;
        this->prenom=prenom;
        this->num_tel=num_tel;
        this->email=email;
        this->type_equip=type_equip;
        this->type_paiem=type_paiem;
        this->reclam=reclam;

}
bool fournisseur::ajouter()

{
QSqlQuery query;
QString res= QString::number(id);
QString rest=QString::number(num_tel);
query.prepare("INSERT INTO GEST_FOURN(id, nom, prenom,num_tel,email,type_equip,type_paiem,reclam) " "VALUES(:id, :nom, :prenom,:num_tel, :email, :type_equip,:type_paiem, :reclam)" );
query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":num_tel",rest);
query.bindValue(":email",email);
query.bindValue(":type_equip",type_equip);
query.bindValue(":type_paiem",type_paiem);
query.bindValue(":reclam",reclam);



   return query.exec();
}

QSqlQueryModel * fournisseur::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from GEST_FOURN");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Num_tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Type_equip"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Type_paiem"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Reclamation"));

    return model;

}

bool fournisseur::supprimer(int id)
{

        QSqlQuery query;
        QString res=QString::number(id);
        query.prepare("DELETE FROM GEST_FOURN WHERE ID= :id ");
        query.bindValue(":id",res);
        return  query.exec();
}

bool fournisseur::modifier(int id)
{

    QSqlQuery query;
           QString res=QString::number(id);


                  query.prepare("UPDATE GEST_FOURN "" SET id=:id, nom=:nom, prenom=:prenom, email=:email, num_tel=:num_tel,reclam=:reclam where ID='"+res+"' ");
                   query.bindValue(":id",res);
                   query.bindValue(":nom", nom);
                   query.bindValue(":prenom", prenom);
                   query.bindValue(":email", email);
                   query.bindValue(":num_tel", num_tel);
                   query.bindValue(":reclam",reclam);
                       return    query.exec();

}
QSqlQueryModel* fournisseur::rechercherdynamique(QString input, QString filtrer)
{
    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM GEST_FOURN WHERE "+filtrer+" LIKE '%' || :inputValue || '%'");
    query.bindValue(":inputValue",input);
    query.exec();
    modal->setQuery(query);
    return modal;

}
