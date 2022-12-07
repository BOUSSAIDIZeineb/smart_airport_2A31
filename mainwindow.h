
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employes.h"
#include <QMainWindow>
#include <QPlainTextEdit>
#include"stat_combo.h"
#include "arduino.h"
#include "fournisseur.h"
#include "voyageur.h"
#include"stat.h"
#include "arduino.h"
#include <QMainWindow>
#include<QDebug>
#include <QByteArray>
#include "produit.h"
#include <QTcpSocket>
#include <QSystemTrayIcon>

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


//heni
#include "vol.h"
#include "histo.h"
#include <QMainWindow>
#include<QTableView>
#include<QWidget>
#include <QMessageBox>
#include<QString>
#include<QtWidgets>
#include<QTableView>
#include <QDialog>
#include<QAbstractItemModel>
#include "vol.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //employe
     void update_label();  //arduino
   // void on_pushButton_clicked();

   // void on_pushButton_2_clicked();

    void on_pb_ajouter_clicked();

    //void on_pushButton_3_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_tableView_mod_clicked(const QModelIndex &index);

    void on_tableView_1_clicked(const QModelIndex &index);

    void on_pb_aff_clicked();

    void on_Button_emp_clicked();

    void on_Button_log_clicked();

    void on_Button_voy_clicked();

    void on_Button_four_clicked();

    void on_Button_free_clicked();

    void on_Button_trans_clicked();

   // void on_pushButton_22_clicked();

    void on_le_cins_textChanged(const QString &arg1);

    void on_triBox_currentTextChanged(const QString &arg1);

    void on_pb_imprimer_clicked();

    void  browse();

    void   sendMail();

    void   mailSent(QString status);

    void on_pb_aj_paie_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pb_exportexcel_clicked();

    void on_pb_impnews_clicked();

    void on_pb_imnews_2_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_pushButton_on_clicked();

    void on_pushButton_off_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
  //fournisseur
        void on_ajout_clicked();

        void on_supprimer_clicked();

        void on_update_clicked();

        void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

        void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

        //void on_pushButton_clicked();

        void on_comboBox_activated(const QString &arg1);

        void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

        //void on_pushButton_2_clicked();

        void makePlot_Type();
        QVector<double> Statistique_Type();

        void on_excel_button_clicked();

        void on_stat_button_clicked();

        void on_reclam_butt_ajouter_clicked();

        void on_afficher_reclam_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_pdf_clicked();
     //voyageur

        void on_pb_ajouter_3_clicked();

        void on_pb_supprimer_2_clicked();

        void on_pb_modifier_2_clicked();

        //void on_pushButton_clicked();

        //void on_pushButton_2_clicked();

        //void on_pushButton_3_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_5_clicked();

        void on_pushButton_6_clicked();

        void on_pushButton_7_clicked();

        void on_pushButton_8_clicked();

        void on_pushButton_9_clicked();

        void on_pushButton_10_clicked();

        void on_pushButton_11_clicked();

        void on_pushButton_12_clicked();


        void on_pushButton_16_clicked();

        void on_pushButton_15_clicked();

        void on_pushButton_17_clicked();

        void on_pushButton_14_clicked();

        void on_pushButton_18_clicked();

        //free_shop
        void on_pushButton_afficher_clicked();

        void on_pushButton_Ajouter_clicked();

        void on_pushButton_supprimer_clicked();

        void on_pushButton_modifier_clicked();

        void on_lineEdit_recherche_cursorPositionChanged();

        void on_comboBox_activated();

        void on_pushButton_statestique_clicked();

        void on_pushButton_PDF_clicked();

        //void on_tableView_clicked(const QModelIndex &index);

        //void on_pushButton_clicked();

        //void on_pushButton_2_clicked();

        void on_pushButton_QRcode_clicked();
        void on_pushButton_afficherfs_clicked();

        void on_pushButton_Ajouterfs_clicked();

        void on_pushButton_supprimerfs_clicked();

        void on_pushButton_modifierfs_clicked();

        void on_lineEdit_recherche_cursorPositionChanged(int arg1, int arg2);

        void on_comboBox_fs_activated(const QString &arg1);

        void on_tableView_2fs_clicked(const QModelIndex &index);

        void on_pushButton_19_clicked();

        void on_pushButton_20_clicked();

        void on_pb_supprimer_3_clicked();

        void on_pb_ajouter_4_clicked();

        void on_pb_modifier_3_clicked();

        void on_pushButton_22_clicked();

        void on_pushButton_24_clicked();

        void on_pb_pdf_clicked();

        void on_pb_mail_clicked();

private:
    Ui::MainWindow *ui;
    Employes Emp;
    QStringList files;
     QPlainTextEdit plainTextEdit;
     stat_combo *s;
     QByteArray data;
     fournisseur fourn;
     Voyageur V;
     Voyageur *VO;
    // Arduino ar;
     //***********
     produit p;
     QTcpSocket*mSocket;

       vol v;
        // Arduino a;


     Arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
