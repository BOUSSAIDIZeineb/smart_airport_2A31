#include "fournisseur.h"

fournisseur::fournisseur()
{}
fournisseur::fournisseur(QString reclam)
{
    this->reclam=reclam;
}
fournisseur::fournisseur(int id,QString nom,QString prenom,int num_tel,QString email,QString type_equip,QString type_paiem,int nb_equip,int prix)
{
        this->id=id;
        this->nom=nom;
        this->prenom=prenom;
        this->num_tel=num_tel;
        this->email=email;
        this->type_equip=type_equip;
        this->type_paiem=type_paiem;
        //this->reclam=reclam;
        this->nb_equip=nb_equip;
        this->prix=prix;

}
fournisseur::fournisseur(int id,QString nom,QString prenom,int num_tel,QString email,QString type_equip,QString type_paiem,QString reclam,int nb_equip,int prix)
{
        this->id=id;
        this->nom=nom;
        this->prenom=prenom;
        this->num_tel=num_tel;
        this->email=email;
        this->type_equip=type_equip;
        this->type_paiem=type_paiem;
        this->reclam=reclam;
        this->nb_equip=nb_equip;
        this->prix=prix;

}



bool fournisseur::ajouter()

{
QSqlQuery query;
QString res= QString::number(id);
QString rest=QString::number(num_tel);
query.prepare("INSERT INTO GEST_FOURN(id, nom, prenom,num_tel,email,type_equip,type_paiem,nb_equip,prix) " "VALUES(:id, :nom, :prenom,:num_tel, :email, :type_equip,:type_paiem, :nb_equip, :prix)" );
query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":num_tel",rest);
query.bindValue(":email",email);
query.bindValue(":type_equip",type_equip);
query.bindValue(":type_paiem",type_paiem);
//query.bindValue(":reclam",reclam);
query.bindValue(":nb_equip",nb_equip);
query.bindValue(":prix",prix);


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
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("NBR EQUIP"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("PRIX"));

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


                   query.prepare("UPDATE GEST_FOURN "" SET id=:id, nom=:nom, prenom=:prenom, email=:email, num_tel=:num_tel,type_equip=:type_equip,type_paiem=:type_paiem,reclam=:reclam,nb_equip=:nb_equip,prix=:prix where ID='"+res+"' ");
                   query.bindValue(":id",res);
                   query.bindValue(":nom", nom);
                   query.bindValue(":prenom", prenom);
                   query.bindValue(":email", email);
                   query.bindValue(":num_tel", num_tel);
                   query.bindValue(":type_equip",type_equip);
                   query.bindValue(":type_paiem",type_paiem);
                   query.bindValue(":reclam",reclam);
                   query.bindValue(":nb_equip",nb_equip);
                   query.bindValue(":prix",prix);

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

QSqlQuery fournisseur::login()
{
    QSqlQuery query;
    query.prepare("SELECT LOGIN from account where login='system' and password='1234");

    query.exec();
    return query;
}

int fournisseur :: dist_prix()   //distinction par prix
{
    int sum=0;

    QSqlQuery query;
    query.prepare("SELECT distinct(prix) FROM GEST_FOURN");

    if(query.exec()){
         while( query.next() ) {
             sum++;
         }
    }
    return sum;
}

QStringList fournisseur :: count_prix() //bch ne7sbo 9adeh mn mara fama lprix selectionne
{
    QStringList rfid;

    QSqlQuery query;
    query.prepare("SELECT distinct(prix) FROM GEST_FOURN order by prix desc");
    if(query.exec()){
         while( query.next() ) {
             rfid.append(query.value( 0 ).toString()); //return les valeurs des prix y7othom f wost liste
         }
    }
    return rfid;
}
bool fournisseur::ajouterReclam(int id_r,int id_f,QString rec)

{
QSqlQuery query;
QSqlQuery query2;
query2.prepare("UPDATE GEST_FOURN SET reclam=:rec where ID=:id_f" );
query2.bindValue(":rec",rec);
query2.bindValue(":id_f",id_f);
query2.exec();

query.prepare("insert into  RECLAMATION (id_r,id_f,rec) values (:id_r,:id_f,:rec) " );
query.bindValue(":id_r",id_r);
query.bindValue(":id_f",id_f);
query.bindValue(":rec",rec);

return query.exec();
}
QSqlQueryModel * fournisseur::afficherReclam(int idd)
{

    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("select rec from RECLAMATION where ID_F=:idd");
    query.bindValue(":idd",idd);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Reclamation"));

    return model;

}

