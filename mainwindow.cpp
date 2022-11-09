#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "connection.h"
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
        QString reclam=ui->line_reclam->text();

        fournisseur F1(id,nom,prenom,num_tel,email,type_equip,type_paiem,reclam);
        bool test=F1.ajouter();
        if (test)
        {
            //refresh (actualiser)
            ui->tableView->setModel(fourn.afficher());

            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Ajout effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("Ajout non effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

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

        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("suppression effectuee.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("suppression non effectuee.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
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
            QString reclam=ui->reclam_line->text();
            fournisseur F2(id,nom,prenom,num_tel,email,type_equip,type_paiem,reclam);

            bool test=F2.modifier(id);

            ui->tableView->setModel(fourn.afficher());
         if(test){

            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("modification effectuee \n""Click Cancel to exit"),QMessageBox::Cancel);
        }else
         {
             QMessageBox::information(nullptr,QObject::tr("Not oK"),
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

void MainWindow::on_lineEdit_cursorPositionChanged(int , int )
{
    fournisseur f1;
    QString inputValue,filtrerChecked;
    inputValue=ui->lineEdit->text();
    ui->tableView->setModel(f1.rechercherdynamique(inputValue,"prenom"));

}

void MainWindow::on_pushButton_clicked()
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
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
             doc.print(&printer);
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


void MainWindow::on_lineEdit_3_cursorPositionChanged(int , int )
{
    fournisseur f3;
    QString inputValue,filtrerChecked;
    inputValue=ui->lineEdit_3->text();
    ui->tableView->setModel(f3.rechercherdynamique(inputValue,"id"));
}
