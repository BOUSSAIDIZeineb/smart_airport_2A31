#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include"employes.h"
#include<QMessageBox>
#include<QDate>
#include<QDateEdit>
#include<QTextStream>
#include<QTextDocument>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include<QGraphicsDropShadowEffect>
#include"smtp.h"
#include<QFileDialog>
#include<QDir>
#include <QPdfWriter>
#include <QDesktopServices>
#include "exportexcelobject.h"
#include "stat_combo.h"

#include "fournisseur.h"
#include "connection.h"
#include "qcustomplot.h"
#include "excel.h"
#include <QRadioButton>
#include <QPainter>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>

#include <QUrl>
#include <QApplication>
#include <QtCore>
#include"voyageur.h"
#include"stat.h"
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
#include <fstream>
#include "notif.h"
#include <QPixmap>
QT_CHARTS_USE_NAMESPACE
using namespace std;

//free_shop
#include <QUrl>
#include<QPieSlice >
#include<QPieSeries>
#include <QtCharts>
#include <QSystemTrayIcon>
#include <QPlainTextEdit>
#include <QRegExpValidator>
#include <QDesktopServices>
#include "QIntValidator"
#include <QGuiApplication>
#include "qrcode.h"
#include "produit.h"

#include "vol.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //arduino
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); //

    //mail
        connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
        connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));


      QObject::connect(ui->tabWidget_2,&QTabWidget::currentChanged,this,&MainWindow::on_tabWidget_2_currentChanged);


    QObject::connect(ui->le_cins,&QLineEdit::textChanged,this,&MainWindow::on_le_cins_textChanged);
    QObject::connect(ui->pb_aff,&QPushButton::clicked,this,&MainWindow::on_pb_aff_clicked);

  //controle de saisie
         ui->le_cin->setValidator( new QIntValidator(1,99999999, this));

   //hide
          ui->tabWidget->hide();
           ui->tabWidget_2->hide();
            ui->tabWidget_3->hide();
            ui->tabWidget_5->hide();
             ui->tabWidget_6->hide();
             ui->Le_Num_vol->hide();
            //borhene
             ui->le_id_v->setValidator(new QIntValidator(0,99999999,this));
             ui->le_ids_v->setValidator(new QIntValidator(0,99999999,this));
             ui->le_id_4v->setValidator(new QIntValidator(0,99999999,this));


   //pics
    QPixmap pix0("C:/Users/zeineb/OneDrive/Pictures/pics projet/logo app.PNG");
    int w0=ui->label_logo->width();
    int h0=ui->label_logo->height();
    ui->label_logo->setPixmap(pix0.scaled(w0,h0,Qt::KeepAspectRatio));

    QPixmap pixp1("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/prof.JPG");
    int wp1=ui->label_pro1->width();
    int hp1=ui->label_pro1->height();
    ui->label_pro1->setPixmap(pixp1.scaled(wp1,hp1,Qt::KeepAspectRatio));

    QPixmap pixp2("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/prof.JPG");
    int wp2=ui->label_pro2->width();
    int hp2=ui->label_pro2->height();
    ui->label_pro2->setPixmap(pixp2.scaled(wp2,hp2,Qt::KeepAspectRatio));

    QPixmap pixp3("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/prof.JPG");
    int wp3=ui->label_pro3->width();
    int hp3=ui->label_pro3->height();
    ui->label_pro3->setPixmap(pixp3.scaled(wp3,hp3,Qt::KeepAspectRatio));

    QPixmap pix1("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
    int w1=ui->label_bg1->width();
    int h1=ui->label_bg1->height();
    ui->label_bg1->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));

    QPixmap pix2("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
    int w2=ui->label_bg2->width();
    int h2=ui->label_bg2->height();
    ui->label_bg2->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));

    QPixmap pix3("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
    int w3=ui->label_bg3->width();
    int h3=ui->label_bg3->height();
    ui->label_bg3->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));

    QPixmap pix4("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
    int w4=ui->label_bg4->width();
    int h4=ui->label_bg4->height();
    ui->label_bg4->setPixmap(pix4.scaled(w4,h4,Qt::KeepAspectRatio));

    QPixmap pix5("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
    int w5=ui->label_bg2_4->width();
    int h5=ui->label_bg2_4->height();
    ui->label_bg2_4->setPixmap(pix5.scaled(w5,h5,Qt::KeepAspectRatio));


    QPixmap pix6("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
    int w6=ui->label_bg2_3->width();
    int h6=ui->label_bg2_3->height();
    ui->label_bg2_3->setPixmap(pix6.scaled(w6,h6,Qt::KeepAspectRatio));


    QPixmap pix7("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
    int w7=ui->label_bg2_5->width();
    int h7=ui->label_bg2_5->height();
    ui->label_bg2_5->setPixmap(pix7.scaled(w7,h7,Qt::KeepAspectRatio));




//fournisseur
    ui->tableViewf->setModel(fourn.afficher());
       ui->tableView_f2->setModel(fourn.afficher());
       ui->tableView_f3->setModel(fourn.afficher());
       QPixmap pixf0("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
          int wf0=ui->label_b1->width();
          int hf0=ui->label_b1->height();
          ui->label_b1->setPixmap(pixf0.scaled(wf0,hf0,Qt::KeepAspectRatio));
          QPixmap pixf1("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
             int wf1=ui->label_b2->width();
             int hf1=ui->label_b2->height();
             ui->label_b2->setPixmap(pixf1.scaled(wf1,hf1,Qt::KeepAspectRatio));
             QPixmap pixf2("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                int wf2=ui->label_b3->width();
                int hf2=ui->label_b3->height();
                ui->label_b3->setPixmap(pixf2.scaled(wf2,hf2,Qt::KeepAspectRatio));
                QPixmap pixf3("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                   int wf3=ui->label_b5->width();
                   int hf3=ui->label_b5->height();
                   ui->label_b5->setPixmap(pixf3.scaled(wf3,hf3,Qt::KeepAspectRatio));
                   QPixmap pixf4("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                      int wf4=ui->label_b4->width();
                      int hf4=ui->label_b4->height();
                      ui->label_b4->setPixmap(pixf4.scaled(wf4,hf4,Qt::KeepAspectRatio));
                      QPixmap pixf8("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                         int wf8=ui->label_b8->width();
                         int hf8=ui->label_b8->height();
                         ui->label_b8->setPixmap(pixf8.scaled(wf8,hf8,Qt::KeepAspectRatio));
                         QPixmap pixf9("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                            int wf9=ui->label_b2->width();
                            int hf9=ui->label_b2->height();
                            ui->label_b2->setPixmap(pixf9.scaled(wf9,hf9,Qt::KeepAspectRatio));
                            QPixmap pixf6("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                               int wf6=ui->label_b6->width();
                               int hf6=ui->label_b6->height();
                               ui->label_b6->setPixmap(pixf6.scaled(wf6,hf6,Qt::KeepAspectRatio));
//*****************************voyageur*****************************************

                              ui->tableView_v3->setModel(V.afficher());


                              QPixmap pixv1("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                              int wv1=ui-> label_bgv1_3->width();
                              int hv1=ui-> label_bgv1->height();
                              ui-> label_bgv1->setPixmap(pixv1.scaled(wv1,hv1,Qt::KeepAspectRatio));

                              QPixmap pixv2("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                              int wv2=ui-> label_bgv1_2->width();
                              int hv2=ui-> label_bgv1_2->height();
                              ui-> label_bgv1_2->setPixmap(pixv2.scaled(wv2,hv2,Qt::KeepAspectRatio));

                              QPixmap pixv3("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                              int wv3=ui-> label_bgv1_3->width();
                              int hv3=ui-> label_bgv1_3->height();
                              ui-> label_bgv1_3->setPixmap(pixv3.scaled(wv3,hv3,Qt::KeepAspectRatio));

                              QPixmap pixv4("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                              int wv4=ui-> label_bgv1_4->width();
                              int hv4=ui-> label_bgv1_4->height();
                              ui-> label_bgv1_4->setPixmap(pixv4.scaled(wv4,hv4,Qt::KeepAspectRatio));

                              QPixmap pixv5("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                              int wv5=ui-> label_bgv1_5->width();
                              int hv5=ui-> label_bgv1_5->height();
                              ui-> label_bgv1_5->setPixmap(pixv5.scaled(wv5,hv5,Qt::KeepAspectRatio));

                              QPixmap pixv6("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                              int wv6=ui-> label_bgv1_6->width();
                              int hv6=ui-> label_bgv1_6->height();
                              ui-> label_bgv1_6->setPixmap(pixv2.scaled(wv6,hv6,Qt::KeepAspectRatio));

                              QPixmap pixv7("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                              int wv7=ui-> label_bgv1_7->width();
                              int hv7=ui-> label_bgv1_7->height();
                              ui-> label_bgv1_7->setPixmap(pixv7.scaled(wv7,hv7,Qt::KeepAspectRatio));

                                ui->tableView_v2->setModel(Voyageur().historique());





    //**********free-shop**********************************************
                                   //chat
                                       mSocket=new QTcpSocket(this);
                                           mSocket->connectToHost("localhost",2000);
                                           if (mSocket->waitForConnected(3000))
                                           {
                                               ui->plainTextEditfs->appendPlainText("se connecter correctement");
                                           }
                                           else
                                           {
                                               ui->plainTextEditfs->appendPlainText("connected");
                                           }
                                           connect(mSocket,SIGNAL(readyRead()),this,SLOT(leer()));


       QPixmap pixfs("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
        int wfs=ui-> label_94->width();
        int hfs=ui-> label_94->height();
        ui-> label_94->setPixmap(pixfs.scaled(wfs,hfs,Qt::KeepAspectRatio));

                                           //heni
                                           ui->tableView_vol->setModel(v.afficher());
                                           ui->table_chercher->setModel(v.afficher());

                                                   QPixmap pixv0l1("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                                                   int wv01=ui-> label_vol->width();
                                                   int hv01=ui-> label_vol->height();
                                                   ui-> label_vol->setPixmap(pixv0l1.scaled(wv01,hv01,Qt::KeepAspectRatio));

                                                   QPixmap pixv02("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                                                   int wv02=ui-> label_vol_2->width();
                                                   int hv02=ui-> label_vol_2->height();
                                                   ui-> label_vol_2->setPixmap(pixv02.scaled(wv02,hv02,Qt::KeepAspectRatio));

                                                   QPixmap pixv03("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                                                   int wv03=ui-> label_vol_3->width();
                                                   int hv03=ui-> label_vol_3->height();
                                                   ui-> label_vol_3->setPixmap(pixv03.scaled(wv03,hv03,Qt::KeepAspectRatio));


                                                   QPixmap pixv04("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                                                   int wv04=ui-> label_vol_4->width();
                                                   int hv04=ui-> label_vol_4->height();
                                                   ui-> label_vol_4->setPixmap(pixv04.scaled(wv04,hv04,Qt::KeepAspectRatio));

                                                   QPixmap pixv05("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                                                   int wv05=ui-> label_vol_5->width();
                                                   int hv05=ui-> label_vol_5->height();
                                                   ui-> label_vol_5->setPixmap(pixv05.scaled(wv05,hv05,Qt::KeepAspectRatio));

                                                   QPixmap pixv06("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
                                                   int wv06=ui-> label_vol_6->width();
                                                   int hv06=ui-> label_vol_6->height();
                                                   ui-> label_vol_6->setPixmap(pixv06.scaled(wv06,hv06,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_pushButton_clicked()
{
   qDebug()<<"boutton ajouter personne appuye";
}

void MainWindow::on_pushButton_2_clicked()
{
   qDebug()<<"boutton afficher personne appuye";
}
*/
void MainWindow::on_pb_ajouter_clicked()
{
    int cin=ui->le_cin->text().toInt();

    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString date_naiss = ui->dateEdit->dateTime().toString("dd/MM/yyyy");
    QString etat_civil = ui->Box_etat->currentText();
    QString sexe = ui->comboBox_s1->currentText();
    QString role = ui->comboBox_r1->currentText();
    QString email=ui->le_mail->text();
     int num_tel=ui->le_num->text().toInt();
     int num_aff=ui->le_aff->text().toInt();
     int matricule=ui->le_mat->text().toInt();


    Employes E(cin,nom,prenom,email,num_tel,num_aff,matricule,role,etat_civil,sexe,date_naiss);
    bool test=E.ajouter();
    if(test)
    {
        ui->tableView_1->setModel(Emp.afficher());
         ui->tableView_mod->setModel(Emp.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

        ui->le_cin->clear();
        ui->le_nom->clear();
        ui->le_prenom->clear();
        ui->le_mail->clear();
        ui->dateEdit->clear();
        ui->le_num->clear();
        ui->le_aff->clear();
        ui->le_mat->clear();
        ui->Box_etat->clear();
        ui->comboBox_s1->clear();
        ui->comboBox_r1->clear();

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Ajouter non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

qDebug()<<QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
}

void MainWindow::on_pb_supprimer_clicked()
{
    int cin=ui->le_cins->text().toInt();
    bool test1=Emp.supprimer(cin);


        QModelIndex index=ui->tableView_1->currentIndex();
        int i;
        i=index.row();
        QModelIndex in=index.sibling(i,0);
        QString val=ui->tableView_1->model()->data(in).toString();

        //int CIN=ui->le_CINs->text().toInt();
        bool test2=Emp.supprimer2(val);


            if(test1)
            {
                ui->tableView_1->setModel(Emp.afficher());
                ui->tableView_mod->setModel(Emp.afficher());
                QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

            }
            else
                if(!test1)
                QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Suppression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

           else
            if(test2)

           {
            ui->tableView_1->setModel(Emp.afficher());
            ui->tableView_mod->setModel(Emp.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
           }
           else
            QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Suppression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_clicked()
{

    int cin=ui->le_cin_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString email=ui->le_email_2->text();
    QString date_naiss = ui->dateEdit->dateTime().toString("dd/MM/yyyy");
     int num_tel=ui->le_num_2->text().toInt();
     int num_aff=ui->le_aff_2->text().toInt();
     int matricule=ui->le_mat_2->text().toInt();
     QString etat_civil = ui->Box_etat_mod->currentText();
     QString sexe = ui->comboBox_s3->currentText();
      QString role = ui->comboBox_r3->currentText();


    Employes E(cin,nom,prenom,email,num_tel,num_aff,matricule,role,etat_civil,sexe,date_naiss);
    bool test=E.modifier(cin);

    ui->tableView_mod->setModel(Emp.afficher());
 if(test){

    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
          /*  ui->le_cin_2->clear();
            ui->le_nom_2->clear();
            ui->le_prenom_2->clear();
            ui->le_email_2->clear();
            ui->dateEdit->clear();
            ui->le_num_2->clear();
            ui->le_aff_2->clear();
            ui->le_mat_2->clear();
            ui->Box_etat_mod->clear();
            ui->comboBox_s3->clear();
            ui->comboBox_r3->clear();*/
}else{
     QMessageBox::information(nullptr,QObject::tr("Not oK"),
                              QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


 }
}


void MainWindow::on_tableView_mod_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_mod->model()->data(index).toString();

            QSqlQuery qry;
            qry.prepare("select * from emp where CIN='"+val+"' or nom='"+val+"' or prenom='"+val+"' or num_tel='"+val+"' or email='"+val+"' or num_aff='"+val+"' " );

            if(qry.exec())
            {
                while(qry.next())
                {
                    ui->le_cin_2->setText(qry.value(0).toString());
                    ui->le_nom_2->setText(qry.value(2).toString());
                    ui->le_prenom_2->setText(qry.value(3).toString());
                    ui->le_email_2->setText(qry.value(8).toString());
                    ui->le_num_2->setText(qry.value(9).toString());
                    ui->le_aff_2->setText(qry.value(10).toString());
                    ui->le_mat_2->setText(qry.value(1).toString());

                     ui->Box_etat_mod->setCurrentText(qry.value(6).toString());
                     ui->comboBox_s3->setCurrentText(qry.value(5).toString());
                      ui->comboBox_r3->setCurrentText(qry.value(7).toString());
                }
        }
}

void MainWindow::on_tableView_1_clicked(const QModelIndex &index)
{
    int i;
        i=index.row();
        QModelIndex in=index.sibling(i,0);
        QString val=ui->tableView_1->model()->data(in).toString();

    //QString val=ui->tableView_1->model()->data(index).toString();

            QSqlQuery qry;
            qry.prepare("select * from emp where CIN='"+val+"' or nom='"+val+"' or prenom='"+val+"' or num_tel='"+val+"' or email='"+val+"' or num_aff='"+val+"' "  );

            if(qry.exec())
            {
                while(qry.next())
                {
                    ui->le_cin_3->setText(qry.value(0).toString());
                    ui->le_nom_3->setText(qry.value(2).toString());
                    ui->le_prenom_3->setText(qry.value(3).toString());
                    ui->le_mail_3->setText(qry.value(8).toString());
                    ui->le_num_3->setText(qry.value(9).toString());
                    ui->le_aff_3->setText(qry.value(10).toString());
                    ui->le_mat_3->setText(qry.value(1).toString());

                    ui->Box_etat_mod->setCurrentText(qry.value(6).toString());
                    ui->comboBox_s1->setCurrentText(qry.value(5).toString());
                    ui->comboBox_r1->setCurrentText(qry.value(7).toString());
                }
        }
}



void MainWindow::on_pb_aff_clicked()
{
     ui->tableView_1->setModel(Emp.afficher());
     ui->tableView_mod->setModel(Emp.afficher());
     ui->tableView->setModel(Emp.afficher_paie());

}

void MainWindow::on_Button_emp_clicked()
{
    ui->tabWidget_2->show();

    ui->tableView_1->setModel(Emp.afficher());
    ui->tableView_mod->setModel(Emp.afficher());
     ui->tabWidget_3->hide();
    ui->tabWidget->hide();
    ui->tabWidget_6->hide();
      ui->tabWidget_5->hide();
      ui->Le_Num_vol->hide();
}

void MainWindow::on_Button_log_clicked()
{
      ui->tabWidget_2->hide();
      ui->tabWidget->show();
    ui->tabWidget_3->hide();
    ui->tabWidget_6->hide();
     ui->tabWidget_5->hide();
     ui->Le_Num_vol->hide();
}

void MainWindow::on_Button_voy_clicked()
{
       ui->tabWidget_2->hide();
        ui->tabWidget->hide();
         ui->tabWidget_3->hide();
          ui->tabWidget_5->show();
         ui->tabWidget_6->hide();
         ui->Le_Num_vol->hide();

         QChart *c=Voyageur().stat();
         QChartView *chartview = new QChartView(c,ui->widget_2);
         chartview->resize(500,400);
         chartview->setRenderHint(QPainter::Antialiasing);
         chartview->show();
}

void MainWindow::on_Button_four_clicked()
{
     ui->tabWidget_2->hide();
         ui->tabWidget->hide();
     ui->tabWidget_3->show();
     ui->tabWidget_6->hide();
      ui->tabWidget_5->hide();
      ui->Le_Num_vol->hide();
}

void MainWindow::on_Button_free_clicked()
{
     ui->tabWidget_2->hide();
         ui->tabWidget->hide();
          ui->tabWidget_3->hide();
          ui->tabWidget_6->show();
           ui->tabWidget_5->hide();
           ui->Le_Num_vol->hide();
}

void MainWindow::on_Button_trans_clicked()
{
     ui->tabWidget_2->hide();
         ui->tabWidget->hide();
          ui->tabWidget_3->hide();
          ui->tabWidget_6->hide();
           ui->tabWidget_5->hide();
           ui->Le_Num_vol->show();
}


//recherche dynamique
void MainWindow::on_le_cins_textChanged(const QString &arg1)
{
    QSqlQueryModel * modal= new QSqlQueryModel ();
            QSqlQuery*qry=new QSqlQuery();
            QString CIN=ui->le_cins->text();


            if(CIN.isEmpty())
            {
                ui->tableView_1->setModel(Emp.afficher());

            }
            else
            {
                //
                qry->prepare ("SELECT * from emp where ( CIN LIKE'%"+CIN+"%' OR nom LIKE'%"+CIN+"%' OR prenom LIKE'%"+CIN+"%'OR matricule LIKE'%"+CIN+"%') ");
                qry->exec();
                modal->setQuery(*qry);
                ui->tableView_1->setModel(modal);
}
}


//tri
void MainWindow::on_triBox_currentTextChanged(const QString &arg1)
{
    QSqlQueryModel * model= new QSqlQueryModel ();
            QSqlQuery*qry=new QSqlQuery();
            QString type=ui->triBox->currentText();
            if (type=="Par defaut")
            {
                qry->prepare("select * from Emp");
                qry->exec();
                model->setQuery(*qry);
                ui->tableView_1->setModel(model);
            }
                else if (type=="CIN"){
               qry->prepare("select * from Emp order by CIN");

                qry->exec();
                model->setQuery(*qry);

                    ui->tableView_1->setModel(model);


                }
                else if (type=="MATRICULE"){
                qry->prepare("select * from Emp order by Matricule");
                qry->exec();
                model->setQuery(*qry);

                    ui->tableView_1->setModel(model);


                }
                else if (type=="NOM"){
                qry->prepare("select * from Emp order by nom");
                qry->exec();
                model->setQuery(*qry);

                    ui->tableView_1->setModel(model);
                }
            else if (type=="PRENOM"){
            qry->prepare("select * from Emp order by prenom");
            qry->exec();
            model->setQuery(*qry);

                ui->tableView_1->setModel(model);
            }
}
//PDF
void MainWindow::on_pb_imprimer_clicked()
{

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("col1")
        <<  "</head>\n"
        "<body bgcolor=#D6EBEE link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=1>\n";

    // headers
    out << "<thead><tr bgcolor=#018ABE>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_1->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_1->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_1->isColumnHidden(column)) {
                QString data = ui->tableView_1->model()->data(ui->tableView_1->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;


}

//Mail
void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("zeineb.boussaidi@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("zeineb.boussaidi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("zeineb.boussaidi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}




void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}




void MainWindow::on_pb_aj_paie_clicked()
{
    int cin=ui->cin->text().toInt();
    QString nom=ui->le_nom_4->text();
    QString prenom=ui->le_prenom_4->text();
    QString email=ui->email->text();
    QString date_naiss = ui->dateEdit->dateTime().toString("dd/MM/yyyy");
     int num_tel=ui->num->text().toInt();
     int num_aff=ui->aff->text().toInt();
     int matricule=ui->le_mat_4->text().toInt();
     QString etat_civil = ui->Box_etat->currentText();
     QString sexe = ui->comboBox_6->currentText();
      QString date_1 = ui->dateEdit_4->dateTime().toString("dd/MM/yyyy");
      QString date_2 = ui->dateEdit_5->dateTime().toString("dd/MM/yyyy");
      QString role = ui->comboBox_r1_2->currentText();
      double s_base=ui->le_sbase->text().toDouble();
      double s_brute=ui->le_sbrute->text().toDouble();
      double cnss=ui->le_cnss->text().toDouble();
      QString etat_path=ui->le_path->text();
    Employes E( cin, matricule, nom, prenom, role, email, num_tel, num_aff, etat_civil, sexe, date_naiss, date_1, date_2, s_base, s_brute, cnss,etat_path);
    bool test=E.modifier2(matricule);

     ui->tableView->setModel(Emp.afficher_paie());

 if(test){

    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
   /* ui->le_mat_4->clear();
    ui->le_nom_4->clear();
    ui->le_prenom_4->clear();
    ui->comboBox_r1_2->clear();
    ui->le_sbase->clear();
    ui->le_sbrute->clear();
    ui->le_cnss->clear();*/

}else{
     QMessageBox::information(nullptr,QObject::tr("Not oK"),
                              QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


 }


}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString val=ui->tableView_mod->model()->data(index).toString();

            QSqlQuery qry;
            qry.prepare("select * from emp where CIN='"+val+"' or nom='"+val+"' or prenom='"+val+"' or num_tel='"+val+"' or email='"+val+"' or num_aff='"+val+"' " );

            if(qry.exec())
            {
                while(qry.next())
                {
                    ui->cin->setText(qry.value(0).toString());
                    ui->le_nom_4->setText(qry.value(2).toString());
                    ui->le_prenom_4->setText(qry.value(3).toString());
                    ui->email->setText(qry.value(8).toString());
                    ui->num->setText(qry.value(9).toString());
                    ui->aff->setText(qry.value(10).toString());
                    ui->le_mat_4->setText(qry.value(1).toString());

                     ui->Box_etat->setCurrentText(qry.value(6).toString());
                     ui->comboBox_6->setCurrentText(qry.value(5).toString());
                     ui->comboBox_r1_2->setCurrentText(qry.value(7).toString());
                     ui->le_sbase->setText(qry.value(11).toString());
                     ui->le_sbrute->setText(qry.value(12).toString());
                     ui->le_cnss->setText(qry.value(13).toString());

                }
        }
}
//excel
void MainWindow::on_pb_exportexcel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "bulletin de paie", ui->tableView_1);

        //colums to export
        obj.addField(0, "CIN", "char(30)");
        obj.addField(1, "Matricule", "char(30)");
        obj.addField(2, "Nom", "char(30)");
        obj.addField(3, "Prenom", "char(30)");
        obj.addField(5, "Sexe", "char(30)");
        obj.addField(6, "Etat", "char(30)");
        obj.addField(7, "Role", "char(30)");
        obj.addField(8, "Email", "char(30)");
        obj.addField(9, "Tel", "char(30)");
        obj.addField(10, "Aff", "char(30)");
        obj.addField(11, "S_base", "char(30)");
        obj.addField(12, "S_brute", "char(30)");
        obj.addField(13, "CNSS", "char(30)");
        obj.addField(14, "Couverture", "char(30)");
        obj.addField(15, "Imposable", "char(30)");



        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }

}
//post of the day
void MainWindow::on_pb_impnews_clicked()
{
    {
            QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.png)");

              QFileInfo info(imageFile);
            QFileInfo  filename = info.fileName(); //path de l'image

            QPixmap image (imageFile);
              ui->label_news->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
              int w_new1=ui->label_news->width();
              int h_new1=ui->label_news->height();
              image = image.scaled(w_new1,h_new1,Qt::IgnoreAspectRatio,Qt::FastTransformation);
              ui->label_news->setPixmap(image);
              ui->label_news->show();

              ui->label_news_2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
              int w_new2=ui->label_news_2->width();
              int h_new2=ui->label_news_2->height();
              image = image.scaled(w_new2,h_new2,Qt::IgnoreAspectRatio,Qt::FastTransformation);
              ui->label_news_2->setPixmap(image);
              ui->label_news_2->show();
             // qDebug() << image <<endl << imageFile <<endl<<info.fileName();
        qDebug()<<QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();

}
}
//announcment of the day
void MainWindow::on_pb_imnews_2_clicked()
{
      QString ch=ui->plainTextEdit_3->toPlainText();
      ui->plainTextEdit_2->appendPlainText(ch);
}

//stat
void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    QSqlQuery q1,q2,q3,q4,q5,q6;
                        qreal tot=0,c1=0,c2=0,c3=0,c4=0,c5=0;


                        q2.prepare("SELECT * FROM Emp WHERE Role='RH'");
                        q2.exec();

                        q3.prepare("SELECT * FROM Emp WHERE Role='res_voyageurs'");
                        q3.exec();

                        q4.prepare("SELECT * FROM Emp WHERE Role='res_fourniss' ");
                        q4.exec();

                        q5.prepare("SELECT * FROM Emp WHERE Role='res_free-shop' ");
                        q5.exec();
                        q6.prepare("SELECT * FROM Emp WHERE Role='res_tranport' ");
                        q6.exec();


                        while (q2.next()){c1++;}
                        while (q3.next()){c2++;}
                        while (q4.next()){c3++;}
                        while (q5.next()){c4++;}
                        while (q6.next()){c5++;}
                       QPieSeries *series=new QPieSeries();


                        series->append("RH",c1);
                        series->append("res_voyageurs",c2);
                        series->append("res_fourniss",c3);
                        series->append("res_free-shop",c4);
                        series->append("res_tranport",c5);


                        tot = c1+c2+c3+c4+c5;
                QString t=QString::number(c1+c2+c3+c4+c5);
                QString p1=QString::number(c1/tot*100, 'f', 2)+"%";
                QString p2=QString::number(c2/tot*100, 'f', 2)+"%";
                QString p3=QString::number(c3/tot*100, 'f', 2)+"%";
                QString p4=QString::number(c4/tot*100, 'f', 2)+"%";
                QString p5=QString::number(c5/tot*100, 'f', 2)+"%";
                ui->lineEdit_p1->setText(p1);
                ui->lineEdit_p2->setText(p2);
                ui->lineEdit_p3->setText(p3);
                ui->lineEdit_p4->setText(p4);
                ui->lineEdit_p5->setText(p5);
                ui->lineEdit_tot->setText(t);

                    int i;
                 if(c1<c2 && c1<c3 && c1<c4 && c1<c5 )
                  {
                       i=0;
                  }
                  else
                  if(c2<c1 && c2<c3 && c2<c4 && c2<c5 )
                  {
                       i=1;
                  }
                  else
                  if(c3<c1 && c3<c2 && c3<c4 && c3<c5 )
                  {
                       i=2;
                  }
                  else
                  if(c4<c1 && c4<c3 && c4<c2 && c4<c5 )
                  {
                       i=3;
                  }
                  else
                  {
                       i=4;
                  }


                    QPieSlice *slice = series->slices().at(i);
                    slice->setExploded(true);


                        QChart *chart =new QChart();

                        chart->addSeries(series);

                        chart->setTitle("Repartition des employes selon leur role ");
                        QChartView *chartView=new QChartView(chart);


                        chartView = new QChartView(chart,ui->horizontalFrame);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        chartView->setMinimumSize(900,520);


                        ui->tableView_1->setModel(Emp.afficher());
                        ui->tableView_mod->setModel(Emp.afficher());
                        ui->tableView->setModel(Emp.afficher_paie());



}
//arduino
void MainWindow::update_label()
{
   Employes e;
    data=A.read_from_arduino();

    if(data=="1")
    {

        QPixmap pixard("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/capfull.PNG");
        int ward=ui->label->width();
        int hard=ui->label->height();
        ui->label->setPixmap(pixard.scaled(ward,hard,Qt::KeepAspectRatio));

        e.modifierEtat("full");

        ui->tableView_mod->setModel(e.afficher_paie());

    }
    else if (data=="0")
    {

        QPixmap pixard("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/capemp.PNG");
        int ward=ui->label->width();
        int hard=ui->label->height();
        ui->label->setPixmap(pixard.scaled(ward,hard,Qt::KeepAspectRatio));

        e.modifierEtat("empty");

        ui->tableView_mod->setModel(e.afficher_paie());
    }


}






void MainWindow::on_pushButton_clicked()
{
    A.write_to_arduino("1");
}

void MainWindow::on_pushButton_2_clicked()
{
    A.write_to_arduino("0");
}







//**********************fournisseur*********************************

void MainWindow::on_ajout_clicked()
{
    //fournisseur F1;
            int id=ui->line_id->text().toInt();
            QString nom=ui->line_nom->text();
            QString prenom=ui->line_prenom->text();
            int num_tel=ui->line_tel->text().toInt();
            QString email=ui->line_email->text();
            QString type_equip=ui->line_equip->text();
            QString type_paiem=ui->line_email->text();
            int nb_equip=ui->line_nbre_ajout->text().toInt();
            int prix=ui->prix_line_ajout->text().toInt();

            fournisseur F1(id,nom,prenom,num_tel,email,type_equip,type_paiem,nb_equip,prix);
            bool test=F1.ajouter();
            if (test)
            {
                //refresh (actualiser)
                ui->tableViewf->setModel(fourn.afficher());
                ui->tableView_f2->setModel(fourn.afficher());
                //ui->tableView_3->setModel(fourn.afficher());



                QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("Ajout effectuee.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                ui->line_id->clear();
                ui->line_nom->clear();
                ui->line_prenom->clear();
                ui->line_email->clear();
                ui->line_tel->clear();
                ui->line_equip->clear();
                ui->line_paiem->clear();
                ui->prix_line_ajout->clear();
                ui->line_nbre_ajout->clear();
            }
            else
                QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                            QObject::tr("Ajout non effectuee.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            ui->line_id->clear();
            ui->line_nom->clear();
            ui->line_prenom->clear();
            ui->line_email->clear();
            ui->line_tel->clear();
            ui->line_equip->clear();
            ui->line_paiem->clear();
            ui->prix_line_ajout->clear();
            ui->line_nbre_ajout->clear();

}

void MainWindow::on_supprimer_clicked()
{
    //fournisseur F;
        int id=ui->id_supp->text().toInt();
        bool test=fourn.supprimer(id);
        if (test)
        {
            //refresh
            ui->tableViewf->setModel(fourn.afficher());
            //ui->tableView_2->setModel(fourn.afficher());
            ui->tableView_f3->setModel(fourn.afficher());



            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("suppression effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->id_supp->clear();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("suppression non effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->id_supp->clear();
}

void MainWindow::on_update_clicked()
{
    //fournisseur F2;
                int     id=ui->Id_pred->text().toInt();
                QString nom=ui->nom_pred->text();
                QString prenom=ui->prenom_pred->text();
                QString email=ui->mail_pred->text();
                int num_tel=ui->tel_pred->text().toInt();
                QString type_equip=ui->equip_line->text();
                QString type_paiem=ui->paiem_line->text();
                QString reclam=ui->lineModif_rec->text();
                int nb_equip=ui->equip_modifier->text().toInt();
                int prix=ui->modif_prix->text().toInt();
                fournisseur F2(id,nom,prenom,num_tel,email,type_equip,type_paiem,nb_equip,prix);

                bool test=F2.modifier(id);

                ui->tableViewf->setModel(fourn.afficher());
                ui->tableView_f2->setModel(fourn.afficher());

             if(test){

                QMessageBox::information(nullptr,QObject::tr("OK"),
                                         QObject::tr("modification effectuee \n""Click Cancel to exit"),QMessageBox::Cancel);
                ui->Id_pred->clear();
                ui->nom_pred->clear();
                ui->prenom_pred->clear();
                ui->mail_pred->clear();
                ui->tel_pred->clear();
                ui->equip_modifier->clear();
                ui->paiem_line->clear();
                ui->modif_prix->clear();
                ui->equip_line->clear();
                ui->lineModif_rec->clear();

            }else
             {
                 QMessageBox::critical(nullptr,QObject::tr("Not oK"),
                                          QObject::tr("modification non effectuee \n""Click Cancel to exit"),QMessageBox::Cancel);
    }
}

void MainWindow::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{
    fournisseur f ;
               QString inputValue,filtrerChecked;
                       inputValue=ui->lineEdit_2->text();
                       ui->tableViewf->setModel(f.rechercherdynamique(inputValue,"nom"));

}

void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    fournisseur f1;
        QString inputValue,filtrerChecked;
        inputValue=ui->lineEdit->text();
        ui->tableViewf->setModel(f1.rechercherdynamique(inputValue,"prenom"));

}

void MainWindow::on_pushButton_pdf_clicked()
{

            QString strStream;
                QTextStream out(&strStream);

                 const int rowCount = ui->tableViewf->model()->rowCount();
                 const int columnCount = ui->tableViewf->model()->columnCount();
                out <<  "<html>\n"
                "<head>\n"
                                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                 <<  QString("<title>%1</title>\n").arg("strTitle")
                                 <<  "</head>\n"
                                 "<body bgcolor=#ffffff link=#5000A0>\n"

                                //     "<align='right'> " << datefich << "</align>"
                                 "<center> <H1>Liste des Fournisseurs </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                             // headers
                             out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                             for (int column = 0; column < columnCount; column++)
                                 if (!ui->tableViewf->isColumnHidden(column))
                                     out << QString("<th>%1</th>").arg(ui->tableViewf->model()->headerData(column, Qt::Horizontal).toString());
                             out << "</tr></thead>\n";

                             // data table
                             for (int row = 0; row < rowCount; row++) {
                                 out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                 for (int column = 0; column < columnCount; column++) {
                                     if (!ui->tableViewf->isColumnHidden(column)) {
                                         QString data = ui->tableViewf->model()->data(ui->tableViewf->model()->index(row, column)).toString().simplified();
                                         out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                     }
                                 }
                                 out << "</tr>\n";
                             }
                             out <<  "</table> </center>\n"
                                 "</body>\n"
                                 "</html>\n";

                       QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                         if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                        QPrinter printer (QPrinter::PrinterResolution);
                         printer.setOutputFormat(QPrinter::PdfFormat);
                        printer.setPaperSize(QPrinter::A4);
                       printer.setOutputFileName(fileName);

                        QTextDocument doc;
                         doc.setHtml(strStream);
                         doc.setPageSize(printer.pageRect().size());
                         doc.print(&printer);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableViewf->setModel(fourn.afficher());
}


void MainWindow::on_comboBox_activated(const QString &arg1)
{
    fournisseur f;
       QSqlQueryModel * modal = new QSqlQueryModel();
       QSqlQuery * qry = new QSqlQuery();
       if (arg1=="Id et nom et prenom")
       {
        qry->prepare("Select * from GEST_FOURN order by id,nom,prenom ");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableViewf->setModel(modal);
        ui->tableViewf->show();
       }
      else if (arg1=="id")
       {
        qry->prepare("Select * from GEST_FOURN order by id");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableViewf->setModel(modal);
        ui->tableViewf->show();
       }

       else if (arg1=="nom")
       {
        qry->prepare("Select * from GEST_FOURN order by nom ");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableViewf->setModel(modal);
        ui->tableViewf->show();
       }else if(arg1=="prenom")
       {
           qry->prepare("Select * from GEST_FOURN order by prenom ");
           qry->exec();
           modal->setQuery(*qry);
           ui->tableViewf->setModel(modal);
           ui->tableViewf->show();
       }
}

void MainWindow::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{
    fournisseur f3;
       QString inputValue,filtrerChecked;
       inputValue=ui->lineEdit_3->text();
       ui->tableViewf->setModel(f3.rechercherdynamique(inputValue,"id"));
}

void MainWindow::makePlot_Type()
{
    QVector<double> x3(fourn.dist_prix()), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot2->xAxis, ui->customPlot2->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique_Type());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot2->replot();


    // move bars above graphs and grid below bars:
    ui->customPlot2->addLayer("abovemain", ui->customPlot2->layer("main"), QCustomPlot::limAbove);
    ui->customPlot2->addLayer("belowmain", ui->customPlot2->layer("main"), QCustomPlot::limBelow);
    ui->customPlot2->xAxis->grid()->setLayer("belowmain");  //khtout mtaa les abs wl ordonn
    ui->customPlot2->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks; // (les valeurs des prix)
    for (int j=1;j<fourn.dist_prix()+1;j++){
        Ticks<<j;

    }
    QVector<QString> labels; //nbre des prix
    for (int i=0;i<fourn.dist_prix();i++){
        labels<<fourn.count_prix()[i];
    }
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot2->xAxis->setTicker(textTicker);
    ui->customPlot2->xAxis->setSubTicks(false);
    ui->customPlot2->xAxis->setTickLength(0,4);
    ui->customPlot2->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot2->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot2->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot2->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot2->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot2->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot2->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot2->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot2->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot2->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot2->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot2->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot2->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot2->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot2->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot2->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot2->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot2->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot2->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot2->axisRect()->setBackground(axisRectGradient);

    ui->customPlot2->rescaleAxes();
    ui->customPlot2->xAxis->setRange(0, 7);
    ui->customPlot2->yAxis->setRange(0, 10);
}
QVector<double> MainWindow::Statistique_Type()
{
    QSqlQuery q;
    QVector<double> stat(fourn.dist_prix());

//stat mtaa kol prix
    q.prepare("SELECT prix FROM GEST_FOURN");
    q.exec();
    while (q.next())
    {
        for (int i=0;i<fourn.dist_prix();i++){
        if (q.value(0)==fourn.count_prix()[i]){ //value(0) heya l valeur eli bch traj3heli requete
            stat[i]++;
        }
       }
    }

    return stat;
}


void MainWindow::on_excel_button_clicked()
{
    //exportation
      QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel Oumaima "), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                EXCEL obj(fileName, "GEST_FOURN", ui->tableViewf);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "ID",    "number");
                obj.addField(1, "NOM", "char(20)");
                obj.addField(2, "PRENOM", "char(20)");
                obj.addField(3, "NUM_TEL", "char(20)");
                obj.addField(4, "EMAIL", "char(20)");
                obj.addField(5, "TYPE_EQUIP", "char(20)");
                obj.addField(6, "TYPE_PAIEM", "char(20)");
                obj.addField(7, "RECLAM", "char(20)");
                obj.addField(8, "NB_EQUIP", "number");
                obj.addField(9, "PRIX", "number");
                obj.addField(10, "FACTURE", "number");



                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportées!")).arg(retVal)
                                             );
                }
}

void MainWindow::on_stat_button_clicked()
{
     MainWindow::makePlot_Type();
}




void MainWindow::on_reclam_butt_ajouter_clicked()
{
    int id_r=ui->Id_recl_4->text().toInt();
                   int id_f=ui->Id_recl->text().toInt();
                   QString reclam=ui->textEditf->toPlainText();


                   bool test=fourn.ajouterReclam(id_r,id_f,reclam);

                if(test){

                   QMessageBox::information(nullptr,QObject::tr("OK"),
                                            QObject::tr("Ajout reclamation effectuee \n""Click Cancel to exit"),QMessageBox::Cancel);
                   ui->textEditf->clear();
                   ui->Id_recl->clear();
                   ui->Id_recl_4->clear();
               }else
                {
                    QMessageBox::warning(nullptr,QObject::tr("Not oK"),
                                             QObject::tr("Ajout reclamation non effectuee \n""Click Cancel to exit"),QMessageBox::Cancel);
       }
}

void MainWindow::on_afficher_reclam_clicked()
{
    int idd = ui->Id_recl_3->text().toInt();
       ui->listView->setModel(fourn.afficherReclam(idd));

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableViewf->setModel(fourn.afficher());

}

//voyageur

void MainWindow::on_pb_ajouter_3_clicked()
{
    int id=ui->le_id_v->text().toInt();
        QString nom=ui->le_nom_v->text();
        QString prenom=ui->le_prenom_v->text();
        QString mois=ui->lineEdit_moisv->text();
        QString date=ui->date_av->text();
    Voyageur V(id,nom,prenom,mois,date);
    bool test=V.ajouter();
    if(test)
    {     ui->tableView_v3->setModel(V.afficher());

        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Ajouter non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer_2_clicked()
{
    Voyageur V1; V1.setid(ui->le_ids_v->text().toInt());
      bool test=V1.supprimer(V1.getID());
      if(test)
      {
          QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suprression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
          ui->tableView_v3->setModel(V.afficher());


      }
      else
          QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Supression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_2_clicked()
{

    int id=ui->le_id_4v->text().toInt();
    QString nom=ui->le_nom_4v->text();
    QString prenom=ui->le_prenom_4v->text();
    QString mois=ui->moisv->text();
    QString date=ui->datev->text();

    Voyageur V(id,nom,prenom,mois,date);
    bool test=V.modifier(id);
    ui->tableView_v3->setModel(V.afficher());
 if(test){

    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
}else{
     QMessageBox::information(nullptr,QObject::tr("Not oK"),
                              QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


 }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->tableView_v2->setModel(Voyageur().historique());
    ui->tableView_v3->setModel(Voyageur().afficher());

}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView_v3->setModel( V.sortid());

}

void MainWindow::on_pushButton_7_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                             "/home",
                                                             QFileDialog::ShowDirsOnly
                                                             | QFileDialog::DontResolveSymlinks);
                 qDebug()<<dir;
                 QPdfWriter pdf(dir+"/PdfList.pdf");
                                        QPainter painter(&pdf);
                                       int i = 4000;

                                       painter.drawPixmap(QRect(100,100,2000,2000),QPixmap("C:/Users/Admin/Desktop/logo.png"));
                                           //painter.drawText(900,650,"Tiny hues");

                                            //painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Users/Admin/Desktop/logo.png"));

                                            painter.setPen(Qt::red);
                                            painter.setFont(QFont("Time New Roman", 25));
                                            painter.drawText(3000,1450,"Liste Des Voyageurs");
                                            painter.setPen(Qt::black);
                                            painter.setFont(QFont("Time New Roman", 15));
                                            painter.drawRect(100,100,9400,2500);
                                            painter.drawRect(100,3000,9400,500);
                                            painter.setFont(QFont("Time New Roman", 10));
                                            painter.drawText(300,3300,"Code");
                                            painter.drawText(3000,3300,"Nom");
                                            painter.drawText(5600,3300,"Prenom");
                                            painter.drawText(8300,3300,"Prix");

                                            painter.drawRect(100,3000,9400,10700);


                                            QTextDocument previewDoc;
                                            QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");


                                            QTextCursor cursor(&previewDoc);



                                            QSqlQuery query;
                                            query.prepare("select * from voyageur");
                                            query.exec();
                                            while (query.next())
                                            {
                                                painter.drawText(300,i,query.value(0).toString());
                                                painter.drawText(3000,i,query.value(1).toString());
                                                painter.drawText(5600,i,query.value(2).toString());
                                                painter.drawText(8300,i,query.value(3).toString());


                                               i = i +500;
                                            }
                                            int reponse = QMessageBox::question(this, "Générer PDF", " PDF Enregistré ! Voulez Vous Affichez Le PDF ?",
                                                                                QMessageBox::Yes|QMessageBox::No);
                                                if (reponse == QMessageBox::Yes)
                                                {
                                                    QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                                    painter.end();
                                                }
                                                else
                                                {
                                                     painter.end();
                                                 }
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->tableView_v2->setModel(Voyageur().historique());
    ui->tableView_v3->setModel(Voyageur().afficher());
}

void MainWindow::on_pushButton_15_clicked()
{

}

void MainWindow::on_pushButton_17_clicked()
{
     ui->tableView_v2->setModel(Voyageur().Notification());
}

void MainWindow::on_pushButton_8_clicked()
{
    QSqlQuery q1,q2,q3;
   fstream f;
   f.open("D:/fichier.txt",ios::out);
   if (f)
   {q1.prepare("Select * from voyageur where datee< sysdate");
       q1.exec();
       while(q1.next())
       {
           string d=q1.value(4).toString().toStdString().substr(0,10);
           f << q1.value(0).toString().toStdString() << " | " << q1.value(1).toString().toStdString() << " | " << q1.value(2).toString().toStdString() << " | " << q1.value(3).toString().toStdString() << " | " << d << endl   ;

   d="";

       }

       }
       else {
           qDebug()<< "Impossible";
       }
}

void MainWindow::on_pushButton_9_clicked()
{
   ui->tableView_v3->setModel( V.sortid2());
}

void MainWindow::on_pushButton_14_clicked()
{
     ui->tableView_v3->setModel( V.sortid3());
}
//arduino
/*void MainWindow::on_pushButton_18_clicked()
{
    QSqlQuery q;
       int x= rand()%1000;
       q.prepare("INSERT INTO ALARM (id,datee) values (:id , sysdate)");
       q.bindValue(":id",x);
       q.exec();
       ar.write_to_arduino("1");
}
*/




//free_shop
void MainWindow::on_pushButton_afficherfs_clicked()
{
    ui->tableView_2fs->setModel(p.afficherproduit());

}

void MainWindow::on_pushButton_Ajouterfs_clicked()
{
    int id_magasin=ui->lineEdit_idmagasin->text().toInt(); //convertir en entier
          QString nom_magasin=ui->lineEdit_nommagasin->text();
          int num_article=ui->lineEdit_NumArticel->text().toInt();
          QString nom_article=ui->lineEdit_nomarticle->text();
          int prix_article=ui->lineEdit_prixarticle->text().toInt();
          int nombre_article=ui->lineEdit_nmbrarticle->text().toInt();
          produit p(id_magasin,nom_magasin,num_article,nom_article,prix_article,nombre_article);
              bool test=p.ajouterproduit();
              if(test)
                    {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                                  QObject::tr("ajout successful.\n"
                                                              "Click Cancel to exit."), QMessageBox::Cancel);
                                   ui->tableView_2fs->setModel(p.afficherproduit()); //mise a jour tableau automatique
                    }
                                  else
                                      QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                                  QObject::tr("ajout failed.\n"
                                                              "Click Cancel to exit."), QMessageBox::Cancel);

               // case vide
                   ui->lineEdit_idmagasin->clear();
                   ui->lineEdit_nommagasin->clear();
                   ui->lineEdit_NumArticel->clear();
                   ui->lineEdit_nomarticle->clear();
                   ui->lineEdit_prixarticle->clear();
                   ui->lineEdit_nmbrarticle->clear();
}

void MainWindow::on_pushButton_supprimerfs_clicked()
{
    produit p1;
        p1.setidmagasin(ui->lineEdit_idmagasin->text().toInt());
        bool test=p1.supprimerproduit(p1.getidmagasin());
        QMessageBox msgBox;
        if (ui->lineEdit_idmagasin->text()=="")
        {
            QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                               QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de CIN"), QMessageBox::Cancel);
        }
        else if (test)
        {
            QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                               QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
            ui->tableView_2fs->setModel(p.afficherproduit());
        }

           ui->lineEdit_idmagasin->clear();
           ui->lineEdit_nommagasin->clear();
           ui->lineEdit_NumArticel->clear();
           ui->lineEdit_nomarticle->clear();
           ui->lineEdit_prixarticle->clear();
           ui->lineEdit_nmbrarticle->clear();
 }


void MainWindow::on_pushButton_modifierfs_clicked()
{
    int id_magasin=ui->lineEdit_idmagasin->text().toInt(); //convertir en entier
          QString nom_magasin=ui->lineEdit_nommagasin->text();
          int num_article=ui->lineEdit_NumArticel->text().toInt();
          QString nom_article=ui->lineEdit_nomarticle->text();
          int prix_article=ui->lineEdit_prixarticle->text().toInt();
          int nombre_article=ui->lineEdit_nmbrarticle->text().toInt();
          produit p(id_magasin,nom_magasin,num_article,nom_article,prix_article,nombre_article);

          bool test=p.modifierEmploye(p.getidmagasin(),p.getnommagasin(),p.getnumarticle(),p.getnomarticle(),p.getprixarticle(),p.getnombrearticle());

          QMessageBox msgBox;

          if (test)
          {

              QMessageBox::information(this, QObject::tr("Modification Succes"),
                                 QObject::tr("Modifications avec Succes"), QMessageBox::Cancel);
              ui->tableView_2fs->setModel(p.afficherproduit());

          }
          else
          {

              QMessageBox::critical(this, QObject::tr("Modification Errer"),
                                 QObject::tr("Echec de Modification!!!\n""Veuillez remplir tous le champs"), QMessageBox::Cancel);
          }


          ui->lineEdit_idmagasin->clear();
          ui->lineEdit_nommagasin->clear();
          ui->lineEdit_NumArticel->clear();
          ui->lineEdit_nomarticle->clear();
          ui->lineEdit_prixarticle->clear();
          ui->lineEdit_nmbrarticle->clear();

}

void MainWindow::on_lineEdit_recherche_cursorPositionChanged(int arg1, int arg2)
{
    QString rech=ui->lineEdit_recherche->text();
        ui->tableView_2fs->setModel(p.RechercheArticle(rech));

}

void MainWindow::on_comboBox_fs_activated(const QString &arg1)
{
    if(ui->comboBox_fs->currentText()=="Tri par Num Article")
           {
               ui->tableView_2fs->setModel(p.trierProduitparnumArticle());

           }else if(ui->comboBox_fs->currentText()=="Tri par Nom Article")
           {
               ui->tableView_2fs->setModel(p.trierProduitparnomArticle());

           }else
           {
               ui->tableView_2fs->setModel(p.trierProduitparprixArticle());
           }
}

void MainWindow::on_pushButton_statestique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                           model->setQuery("select * from PRODUIT where prix_article < 100 ");
                           float age=model->rowCount();
                           model->setQuery("select * from PRODUIT where prix_article  between 100 and 1000 ");
                           float agee=model->rowCount();
                           model->setQuery("select * from PRODUIT where prix_article >1000 ");
                           float ageee=model->rowCount();
                           float total=age+agee+ageee;
                           QString a=QString("moins de 100 DT "+QString::number((age*100)/total,'f',2)+"%" );
                           QString b=QString("entre 100 et 1000 DT "+QString::number((agee*100)/total,'f',2)+"%" );
                           QString c=QString("+1000 DT"+QString::number((ageee*100)/total,'f',2)+"%" );
                           QPieSeries *series = new QPieSeries();
                           series->append(a,age);
                           series->append(b,agee);
                           series->append(c,ageee);
                   if (age!=0)
                   {QPieSlice *slice = series->slices().at(0);
                    slice->setLabelVisible();
                    slice->setPen(QPen());}
                   if ( agee!=0)
                   {
                            // Add label, explode and define brush for 2nd slice
                            QPieSlice *slice1 = series->slices().at(1);
                            //slice1->setExploded();
                            slice1->setLabelVisible();
                   }
                   if(ageee!=0)
                   {
                            // Add labels to rest of slices
                            QPieSlice *slice2 = series->slices().at(2);
                            //slice1->setExploded();
                            slice2->setLabelVisible();
                   }
                           // Create the chart widget
                           QChart *chart = new QChart();
                           // Add data to chart with title and hide legend
                           chart->addSeries(series);
                           chart->setTitle("Pourcentage Par Age :Nombre Des Aimaux "+ QString::number(total));
                           chart->legend()->hide();
                           // Used to display the chart
                           QChartView *chartView = new QChartView(chart);
                           chartView->setRenderHint(QPainter::Antialiasing);
                           chartView->resize(1000,500);
                           chartView->show();


}


void MainWindow::on_pushButton_PDF_clicked()
{
    QPdfWriter pdf("C:\\Users\\octanet\\Desktop\\gestion_freeshop\\PDF_Article.pdf");

          QPainter painter(&pdf);
          int i = 4000;
                 painter.setPen(Qt::red);
                 painter.setFont(QFont("Time New Roman", 25));
                 painter.drawText(3000,1400,"Liste Des Article");
                 painter.setPen(Qt::black);
                 painter.setFont(QFont("Time New Roman", 15));
                 painter.drawRect(100,3000,9400,500);
                 painter.setFont(QFont("Time New Roman", 9));
                 painter.drawText(400,3300,"Id Magasin");
                 painter.drawText(1350,3300,"Nom Magasin");
                 painter.drawText(2600,3300,"Num Article");
                 painter.drawText(3800,3300,"Nom Article");
                 painter.drawText(4900,3300,"Prix Article");
                 painter.drawText(6200,3300,"Nombre Article");
                 painter.drawRect(100,3000,9400,9000);

                 QSqlQuery query;
                 query.prepare("select * from PRODUIT");
                 query.exec();
                 while (query.next())
                 {
                     painter.drawText(400,i,query.value(0).toString());
                     painter.drawText(1450,i,query.value(1).toString());
                     painter.drawText(2800,i,query.value(2).toString());
                     painter.drawText(4000,i,query.value(3).toString());
                     painter.drawText(5100,i,query.value(4).toString());
                     painter.drawText(6400,i,query.value(5).toString());


                    i = i + 350;
                 }
                 QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                 QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_tableView_2fs_clicked(const QModelIndex &index)
{

       ui->lineEdit_idmagasin->setText(ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(index.row(),0)).toString());
       ui->lineEdit_nommagasin->setText(ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(index.row(),1)).toString());
       ui->lineEdit_NumArticel->setText(ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(index.row(),2)).toString());
       ui->lineEdit_nomarticle->setText(ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(index.row(),3)).toString());
       ui->lineEdit_prixarticle->setText(ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(index.row(),4)).toString());
       ui->lineEdit_nmbrarticle->setText(ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(index.row(),5)).toString());
 }

void MainWindow::on_pushButton_19_clicked()
{
         mSocket->write(ui->lineEdit_1fs->text().toLatin1().data(),ui->lineEdit_1fs->text().size());

         ui->plainTextEdit_2fs->appendPlainText(ui->lineEdit_1fs->text());

         ui->lineEdit_1fs->clear();
}

void MainWindow::on_pushButton_20_clicked()
{
           mSocket->write(ui->lineEdit_2fs->text().toLatin1().data(),ui->lineEdit_2fs->text().size());

           ui->plainTextEditfs->appendPlainText(ui->lineEdit_2fs->text());

           ui->lineEdit_2fs->clear();
}

void MainWindow::on_pushButton_QRcode_clicked()
{
    QString text ="Articles details :"+ ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(ui->tableView_2fs->currentIndex().row(),1)).toString()
                               +" "+ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(ui->tableView_2fs->currentIndex().row(),2)).toString()
                               +" "+ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(ui->tableView_2fs->currentIndex().row(),3)).toString()
                               +" "+ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(ui->tableView_2fs->currentIndex().row(),4)).toString()
                               +" "+ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(ui->tableView_2fs->currentIndex().row(),5)).toString()
                               +" "+ui->tableView_2fs->model()->data(ui->tableView_2fs->model()->index(ui->tableView_2fs->currentIndex().row(),6)).toString();
                       //text="user data";
                       using namespace qrcodegen;
                         // Create the QR Code object
                         QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );
                         qint32 sz = qr.getSize();
                         QImage im(sz,sz, QImage::Format_RGB32);
                           QRgb black = qRgb(  0,  0,  0);
                           QRgb white = qRgb(255,255,255);
                         for (int y = 0; y < sz; y++)
                           for (int x = 0; x < sz; x++)
                             im.setPixel(x,y,qr.getModule(x, y) ? black : white );
                         ui->qr_code->setPixmap( QPixmap::fromImage(im.scaled(256,256,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );

}

//heni
void MainWindow::on_pb_supprimer_3_clicked()
{
   // a.write_to_arduino(0);


            vol v;
            v.setNUM_VOL(ui->le_NUM_VOL_2->text().toInt());
            bool test =v.supprimer(v.getNUM_VOL());
            if(test )
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("supprimer successful.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
               ui->tableView_vol->setModel(v.afficher());

            //a.write_to_arduino("1");

            }
            else{
                QMessageBox::information(nullptr, QObject::tr("database is not open"),
                            QObject::tr("supprimer failed.\n"

                              "Click Cancel to exit."), QMessageBox::Cancel);
                //a.write_to_arduino("1");
            }
}

void MainWindow::on_pb_ajouter_4_clicked()
{
    int NUM_VOL=ui->le_NUM_VOL_2->text().toInt();
          int NBR_place=ui->le_NBR_place->text().toInt();
          QString DESTINATION=ui->le_DESTINATION->text();
          QString Date_arrive=ui->le_Date_arrive->text();
          QString Date_Depart=ui->le_Date_Depart->text();
          QString nom_compagnie=ui->le_nom_compagnie->text();
          ui->tableView_vol->setModel(v.afficher());
          vol v ;
          bool test=v.ajouter();
          if(test)
          {
              QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
              ui->tableView_vol->setModel(v.afficher());
          }
          else
              QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effectué.\n" "Click Cancel to exit."));

}

void MainWindow::on_pb_modifier_3_clicked()
{
    int NUM_VOL=ui->le_NUM_VOL_2->text().toInt();
        QString DESTINATION=ui->le_DESTINATION->text();
        QString Date_arrive=ui->le_Date_arrive->text();
        QString Date_Depart=ui->le_Date_Depart->text();
        QString NBR_place=ui->le_NBR_place->text();
        QString nom_compagnie=ui->le_nom_compagnie->text();
                          vol v;//( NUM_VOL,DESTINATION,Date_Depart,Date_arrive,NBR_place,nom_compagnie);




                          bool test =v.modifier();
                          if(test )
                          {
                              QMessageBox::information(nullptr, QObject::tr("database is open"),
                                          QObject::tr("modifier successful.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tableView_vol->setModel(v.afficher());

                          }
                          else{
                              QMessageBox::information(nullptr, QObject::tr("database is not open"),
                                          QObject::tr("modifier failed.\n"

                                            "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_22_clicked()
{
     ui->tableView_vol->setModel(v.trier());
}

void MainWindow::on_pushButton_24_clicked()
{
    QString nom_compagnie=ui->le_chercher->text();
        if(nom_compagnie=="")
        {
            QMessageBox::information(nullptr,QObject::tr("Champ vide"),QObject::tr("Veuiller insérer un NOM!"),QMessageBox::Cancel);
            ui->table_chercher->setModel(v.afficher());
        }
        else
        {
            ui->table_chercher->setModel(v.chercher(nom_compagnie));
        }

}

void MainWindow::on_pb_pdf_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                                     "/home",
                                                                     QFileDialog::ShowDirsOnly
                                                                     | QFileDialog::DontResolveSymlinks);
          qDebug()<<dir;
          QPdfWriter pdf(dir+"/PdfList.pdf");
          QPainter painter(&pdf);
          int i = 4000;

          painter.setPen(Qt::blue);
          painter.setFont(QFont("Time New Roman", 25));
          painter.drawText(3000,1400,"Liste Des vols");
          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          painter.drawRect(100,100,9400,2500);
          painter.drawRect(100,3000,9400,500);
          painter.setFont(QFont("Time New Roman", 9));
          painter.drawText(300,3300,"NUM_VOL");
          painter.drawText(2300,3300,"DESTINATION");
          painter.drawText(4300,3300,"Date_Depart");
          painter.drawText(6300,3300,"nDate_arrive");
          painter.drawText(7500,3300,"NBR_place");
          painter.drawText(8500,3300,"nom_compagnie");
          painter.drawRect(100,3000,9400,10700);
          QTextDocument previewDoc;
          QTextCursor cursor(&previewDoc);
          QSqlQuery query;
          query.prepare("select * from vol");
          query.exec();
          while (query.next())
          {
          painter.drawText(300,i,query.value(0).toString());
          painter.drawText(2300,i,query.value(1).toString());
          painter.drawText(4300,i,query.value(2).toString());
          painter.drawText(6300,i,query.value(3).toString());
          painter.drawText(7500,i,query.value(4).toString());
          painter.drawText(8500,i,query.value(4).toString());
          i = i +500;
          }
          int reponse = QMessageBox::question(this, "Générer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                                     QMessageBox::Yes|QMessageBox::No);
          if (reponse == QMessageBox::Yes)
          {
          QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

          painter.end();
          //a.write_to_arduino(0);

          }
          else
          {
              painter.end();
          }

}

void MainWindow::on_pb_mail_clicked()
{
    QString link="https://www.google.com/intl/fr/gmail/about/";
                  QDesktopServices::openUrl(link);
}

