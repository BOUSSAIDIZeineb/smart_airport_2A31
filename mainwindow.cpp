#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include <QIntValidator>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QtDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
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
#include "notif.h"
QT_CHARTS_USE_NAMESPACE
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->le_id_3->setValidator(new QIntValidator(0,99999999,this));
    ui->le_ids_2->setValidator(new QIntValidator(0,99999999,this));
    ui->le_id_4->setValidator(new QIntValidator(0,99999999,this));



    ui->tableView_3->setModel(V.afficher());
    QPixmap pix3("C:/Users/Borhe/OneDrive/Desktop/avion.png");
        int w2=ui->piclab1->width();
        int h2=ui->piclab1->height();
        ui->piclab1->setPixmap(pix3.scaled(w2,h2,Qt::KeepAspectRatio));


        QPixmap pix4("C:/Users/Borhe/OneDrive/Desktop/avion.png");
            int w3=ui->piclab->width();
            int h3=ui->piclab->height();
            ui->piclab->setPixmap(pix4.scaled(w3,h3,Qt::KeepAspectRatio));


            QPixmap pix5("C:/Users/Borhe/OneDrive/Desktop/avion.png");
                int w4=ui->piclab2->width();
                int h4=ui->piclab2->height();
                ui->piclab2->setPixmap(pix5.scaled(w4,h4,Qt::KeepAspectRatio));


                QPixmap pix6("C:/Users/Borhe/OneDrive/Desktop/avion.png");
                    int w5=ui->piclab3->width();
                    int h5=ui->piclab3->height();
                    ui->piclab3->setPixmap(pix6.scaled(w5,h5,Qt::KeepAspectRatio));
ui->tableView->setModel(Voyageur().historique());
QChart *c=Voyageur().stat();
QChartView *chartview = new QChartView(c,ui->widget);
chartview->resize(500,400);
chartview->setRenderHint(QPainter::Antialiasing);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_3_clicked()
{
    int id=ui->le_id_3->text().toInt();
    QString nom=ui->le_nom_3->text();
    QString prenom=ui->le_prenom_3->text();
    QString mois=ui->lineEdit_mois->text();
    QString date=ui->date_a->text();
Voyageur V(id,nom,prenom,mois,date);
bool test=V.ajouter();
if(test)
{     ui->tableView_3->setModel(V.afficher());

    QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Ajouter non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

}





void MainWindow::on_pb_supprimer_2_clicked()
{
    Voyageur V1; V1.setid(ui->le_ids_2->text().toInt());
    bool test=V1.supprimer(V1.getID());
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suprression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
        ui->tableView_3->setModel(V.afficher());


    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Supression non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

    }


void MainWindow::on_pb_modifier_2_clicked()
{

    int id=ui->le_id_4->text().toInt();
    QString nom=ui->le_nom_4->text();
    QString prenom=ui->le_prenom_4->text();
    QString mois=ui->mois->text();
    QString date=ui->date->text();

    Voyageur V(id,nom,prenom,mois,date);
    bool test=V.modifier(id);
    ui->tableView_3->setModel(V.afficher());
 if(test){

    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
}else{
     QMessageBox::information(nullptr,QObject::tr("Not oK"),
                              QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


 }
}


void MainWindow::on_pushButton_clicked()
{
    int code ;
         QSqlQueryModel *model;
         code = ui->lineEdit_rech->text().toInt() ;
          model =VO->chercher (code);
          ui->tableView_3->show() ;
          ui->tableView_3->setModel(model);

}

void MainWindow::on_pushButton_2_clicked()
{

        ui->tableView_3->setModel( V.sortid());

}

void MainWindow::on_pushButton_3_clicked()
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



void MainWindow::on_pushButton_4_clicked()
{

}

void MainWindow::on_pushButton_5_clicked()
{
ui->tableView->setModel(Voyageur().historique());
ui->tableView_3->setModel(Voyageur().afficher());
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->tableView_2->setModel(Voyageur().Notification());
}

void MainWindow::on_pushButton_7_clicked()
{
    notif m("Voyageur","Notification Voyageur");
        m.afficher();
}
