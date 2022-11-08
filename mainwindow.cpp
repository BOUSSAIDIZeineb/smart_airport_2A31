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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->tableView_2->setModel(Emp.afficher());
    //show_table;

    QObject::connect(ui->le_cins,&QLineEdit::textChanged,this,&MainWindow::on_le_cins_textChanged);

    QObject::connect(ui->pb_aff,&QPushButton::clicked,this,&MainWindow::on_pb_aff_clicked);


    QPixmap pix0("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/tayaa.PNG");
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
    ui->label_bg2->setPixmap(pix1.scaled(w2,h2,Qt::KeepAspectRatio));

    QPixmap pix3("C:/Users/zeineb/OneDrive/Pictures/Captures d’écran/atc.PNG");
    int w3=ui->label_bg3->width();
    int h3=ui->label_bg3->height();
    ui->label_bg3->setPixmap(pix1.scaled(w3,h3,Qt::KeepAspectRatio));


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
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),QObject::tr("Ajouter non effectué\n""Click Cancel to exit."),QMessageBox::Cancel);
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
}

void MainWindow::on_Button_emp_clicked()
{
    ui->tabWidget_2->show();

    ui->tableView_1->setModel(Emp.afficher());
    ui->tableView_mod->setModel(Emp.afficher());
}

void MainWindow::on_Button_log_clicked()
{
      ui->tabWidget_2->hide();
}

void MainWindow::on_Button_voy_clicked()
{
    ui->tabWidget_2->hide();
}

void MainWindow::on_Button_four_clicked()
{
     ui->tabWidget_2->hide();
}

void MainWindow::on_Button_free_clicked()
{
     ui->tabWidget_2->hide();
}

void MainWindow::on_Button_trans_clicked()
{
     ui->tabWidget_2->hide();
}






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

void MainWindow::on_pb_imprimer_clicked()
{

    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tableView_1->model()->rowCount();
    const int columnCount = ui->tableView_1->model()->columnCount();

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














/*
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
    mailing* mailing = new mailing("zeineb.boussaidi@esprit.tn",ui->mail_pass->text(), "mailing.gmail.com");
    connect(mailing, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        mailing->sendMail("zeineb.boussaidi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        mailing->sendMail("zeineb.boussaidi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple mailing client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}
*/

