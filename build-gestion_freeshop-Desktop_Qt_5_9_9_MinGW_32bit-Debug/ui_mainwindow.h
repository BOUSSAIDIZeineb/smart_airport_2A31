/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_idmagasin;
    QLineEdit *lineEdit_nommagasin;
    QLineEdit *lineEdit_NumArticel;
    QLineEdit *lineEdit_nomarticle;
    QLineEdit *lineEdit_prixarticle;
    QLineEdit *lineEdit_nmbrarticle;
    QTableView *tableView;
    QPushButton *pushButton_afficher;
    QPushButton *pushButton_Ajouter;
    QPushButton *pushButton_modifier;
    QPushButton *pushButton_supprimer;
    QLineEdit *lineEdit_recherche;
    QLabel *label_7;
    QComboBox *comboBox;
    QPushButton *pushButton_statestique;
    QPushButton *pushButton_PDF;
    QLineEdit *lineEdit;
    QPlainTextEdit *plainTextEdit;
    QLineEdit *lineEdit_2;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_QRcode;
    QLabel *qr_code;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1022, 575);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 80, 14));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 70, 70, 14));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 120, 70, 14));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(300, 20, 70, 14));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(310, 60, 60, 14));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 120, 90, 14));
        lineEdit_idmagasin = new QLineEdit(centralwidget);
        lineEdit_idmagasin->setObjectName(QStringLiteral("lineEdit_idmagasin"));
        lineEdit_idmagasin->setGeometry(QRect(120, 10, 130, 30));
        lineEdit_nommagasin = new QLineEdit(centralwidget);
        lineEdit_nommagasin->setObjectName(QStringLiteral("lineEdit_nommagasin"));
        lineEdit_nommagasin->setGeometry(QRect(120, 60, 130, 30));
        lineEdit_NumArticel = new QLineEdit(centralwidget);
        lineEdit_NumArticel->setObjectName(QStringLiteral("lineEdit_NumArticel"));
        lineEdit_NumArticel->setGeometry(QRect(130, 110, 130, 30));
        lineEdit_nomarticle = new QLineEdit(centralwidget);
        lineEdit_nomarticle->setObjectName(QStringLiteral("lineEdit_nomarticle"));
        lineEdit_nomarticle->setGeometry(QRect(410, 10, 130, 30));
        lineEdit_prixarticle = new QLineEdit(centralwidget);
        lineEdit_prixarticle->setObjectName(QStringLiteral("lineEdit_prixarticle"));
        lineEdit_prixarticle->setGeometry(QRect(410, 60, 130, 30));
        lineEdit_nmbrarticle = new QLineEdit(centralwidget);
        lineEdit_nmbrarticle->setObjectName(QStringLiteral("lineEdit_nmbrarticle"));
        lineEdit_nmbrarticle->setGeometry(QRect(410, 110, 130, 30));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 230, 591, 101));
        pushButton_afficher = new QPushButton(centralwidget);
        pushButton_afficher->setObjectName(QStringLiteral("pushButton_afficher"));
        pushButton_afficher->setGeometry(QRect(610, 10, 100, 30));
        pushButton_Ajouter = new QPushButton(centralwidget);
        pushButton_Ajouter->setObjectName(QStringLiteral("pushButton_Ajouter"));
        pushButton_Ajouter->setGeometry(QRect(610, 50, 100, 30));
        pushButton_modifier = new QPushButton(centralwidget);
        pushButton_modifier->setObjectName(QStringLiteral("pushButton_modifier"));
        pushButton_modifier->setGeometry(QRect(610, 90, 100, 30));
        pushButton_supprimer = new QPushButton(centralwidget);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(610, 130, 100, 30));
        lineEdit_recherche = new QLineEdit(centralwidget);
        lineEdit_recherche->setObjectName(QStringLiteral("lineEdit_recherche"));
        lineEdit_recherche->setGeometry(QRect(60, 190, 120, 30));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 170, 70, 14));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(200, 190, 120, 30));
        pushButton_statestique = new QPushButton(centralwidget);
        pushButton_statestique->setObjectName(QStringLiteral("pushButton_statestique"));
        pushButton_statestique->setGeometry(QRect(350, 190, 110, 30));
        pushButton_PDF = new QPushButton(centralwidget);
        pushButton_PDF->setObjectName(QStringLiteral("pushButton_PDF"));
        pushButton_PDF->setGeometry(QRect(490, 190, 110, 30));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 430, 113, 20));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 350, 231, 61));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(370, 430, 113, 20));
        plainTextEdit_2 = new QPlainTextEdit(centralwidget);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(370, 350, 221, 71));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 430, 75, 23));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 430, 75, 23));
        pushButton_QRcode = new QPushButton(centralwidget);
        pushButton_QRcode->setObjectName(QStringLiteral("pushButton_QRcode"));
        pushButton_QRcode->setGeometry(QRect(620, 190, 110, 30));
        qr_code = new QLabel(centralwidget);
        qr_code->setObjectName(QStringLiteral("qr_code"));
        qr_code->setGeometry(QRect(640, 250, 301, 281));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1022, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "id magasin", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nom Magasin", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Num Article", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Nom Article", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Prix Article", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Nombre Article", Q_NULLPTR));
        lineEdit_idmagasin->setText(QString());
        pushButton_afficher->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        pushButton_Ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Recherche :", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Trier", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Tri par Num Article", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Tri par Nom Article", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Tri par Prix Article", Q_NULLPTR)
        );
        pushButton_statestique->setText(QApplication::translate("MainWindow", "Statestique", Q_NULLPTR));
        pushButton_PDF->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "chat1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "chat2", Q_NULLPTR));
        pushButton_QRcode->setText(QApplication::translate("MainWindow", "QRcode", Q_NULLPTR));
        qr_code->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
