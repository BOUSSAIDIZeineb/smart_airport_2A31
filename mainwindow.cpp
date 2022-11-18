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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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

   //pics
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

    ui->tabWidget->hide();
}

void MainWindow::on_Button_log_clicked()
{
      ui->tabWidget_2->hide();
      ui->tabWidget->show();

}

void MainWindow::on_Button_voy_clicked()
{
    ui->tabWidget_2->hide();
        ui->tabWidget->hide();
}

void MainWindow::on_Button_four_clicked()
{
     ui->tabWidget_2->hide();
         ui->tabWidget->hide();
}

void MainWindow::on_Button_free_clicked()
{
     ui->tabWidget_2->hide();
         ui->tabWidget->hide();
}

void MainWindow::on_Button_trans_clicked()
{
     ui->tabWidget_2->hide();
         ui->tabWidget->hide();
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

    Employes E( cin, matricule, nom, prenom, role, email, num_tel, num_aff, etat_civil, sexe, date_naiss, date_1, date_2, s_base, s_brute, cnss);
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
