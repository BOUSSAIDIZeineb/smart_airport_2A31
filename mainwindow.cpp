#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "connection.h"
#include "qcustomplot.h"
#include "excel.h"
#include<QMessageBox>
#include<QtDebug>
#include <QLabel>
#include <QPixmap>
#include<QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    ui->tableView->setModel(fourn.afficher());
    ui->tableView_2->setModel(fourn.afficher());
    ui->tableView_3->setModel(fourn.afficher());
    QPixmap pix0("C:/Users/21629/Desktop/background.png");
       int w0=ui->label_b1->width();
       int h0=ui->label_b1->height();
       ui->label_b1->setPixmap(pix0.scaled(w0,h0,Qt::KeepAspectRatio));
       QPixmap pix1("C:/Users/21629/Desktop/background.png");
          int w1=ui->label_b2->width();
          int h1=ui->label_b2->height();
          ui->label_b2->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
          QPixmap pix2("C:/Users/21629/Desktop/background.png");
             int w2=ui->label_b3->width();
             int h2=ui->label_b3->height();
             ui->label_b3->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
             QPixmap pix3("C:/Users/21629/Desktop/background.png");
                int w3=ui->label_b5->width();
                int h3=ui->label_b5->height();
                ui->label_b5->setPixmap(pix3.scaled(w3,h3,Qt::KeepAspectRatio));
                QPixmap pix4("C:/Users/21629/Desktop/background.png");
                   int w4=ui->label_b4->width();
                   int h4=ui->label_b4->height();
                   ui->label_b4->setPixmap(pix4.scaled(w4,h4,Qt::KeepAspectRatio));
                   QPixmap pix8("C:/Users/21629/Desktop/background.png");
                      int w8=ui->label_b8->width();
                      int h8=ui->label_b8->height();
                      ui->label_b8->setPixmap(pix8.scaled(w8,h8,Qt::KeepAspectRatio));
                      QPixmap pix9("C:/Users/21629/Desktop/background.png");
                         int w9=ui->label_b2->width();
                         int h9=ui->label_b2->height();
                         ui->label_b2->setPixmap(pix9.scaled(w9,h9,Qt::KeepAspectRatio));
                         QPixmap pix6("C:/Users/21629/Desktop/background.png");
                            int w6=ui->label_b6->width();
                            int h6=ui->label_b6->height();
                            ui->label_b6->setPixmap(pix6.scaled(w6,h6,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
            ui->tableView->setModel(fourn.afficher());
            ui->tableView_2->setModel(fourn.afficher());
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
        ui->tableView->setModel(fourn.afficher());
        //ui->tableView_2->setModel(fourn.afficher());
        ui->tableView_3->setModel(fourn.afficher());



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

            ui->tableView->setModel(fourn.afficher());
            ui->tableView_2->setModel(fourn.afficher());

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

void MainWindow::on_lineEdit_2_cursorPositionChanged(int , int ) //chercher par nom
{
    fournisseur f ;
             QString inputValue,filtrerChecked;
                     inputValue=ui->lineEdit_2->text();
                     ui->tableView->setModel(f.rechercherdynamique(inputValue,"nom"));

}

void MainWindow::on_lineEdit_cursorPositionChanged(int , int ) //chercher par prenom
{
    fournisseur f1;
    QString inputValue,filtrerChecked;
    inputValue=ui->lineEdit->text();
    ui->tableView->setModel(f1.rechercherdynamique(inputValue,"prenom"));

}

void MainWindow::on_pushButton_clicked() //pdf
{
    QString strStream;
    QTextStream out(&strStream);

     const int rowCount = ui->tableView->model()->rowCount();
     const int columnCount = ui->tableView->model()->columnCount();
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
                     if (!ui->tableView->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tableView->isColumnHidden(column)) {
                             QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_comboBox_activated(const QString &arg1) //tri
{
    fournisseur f;
   QSqlQueryModel * modal = new QSqlQueryModel();
   QSqlQuery * qry = new QSqlQuery();
   if (arg1=="Id et nom et prenom")
   {
    qry->prepare("Select * from GEST_FOURN order by id,nom,prenom ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }
  else if (arg1=="id")
   {
    qry->prepare("Select * from GEST_FOURN order by id");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }

   else if (arg1=="nom")
   {
    qry->prepare("Select * from GEST_FOURN order by nom ");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    ui->tableView->show();
   }else if(arg1=="prenom")
   {
       qry->prepare("Select * from GEST_FOURN order by prenom ");
       qry->exec();
       modal->setQuery(*qry);
       ui->tableView->setModel(modal);
       ui->tableView->show();
   }
}


void MainWindow::on_lineEdit_3_cursorPositionChanged(int , int ) //chercher par id
{
    fournisseur f3;
    QString inputValue,filtrerChecked;
    inputValue=ui->lineEdit_3->text();
    ui->tableView->setModel(f3.rechercherdynamique(inputValue,"id"));
}
/*
void MainWindow::on_pushButton_2_clicked()//login
{
    ui->logi_line->text();
    ui->pass_line->text();
}*/
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

              EXCEL obj(fileName, "GEST_FOURN", ui->tableView);

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
                QString reclam=ui->textEdit->toPlainText();


                bool test=fourn.ajouterReclam(id_r,id_f,reclam);

             if(test){

                QMessageBox::information(nullptr,QObject::tr("OK"),
                                         QObject::tr("Ajout reclamation effectuee \n""Click Cancel to exit"),QMessageBox::Cancel);
                ui->textEdit->clear();
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

void MainWindow::on_pushButton_3_clicked() //refresh
{
    ui->tableView->setModel(fourn.afficher());

}


// ********************arduino*****************










