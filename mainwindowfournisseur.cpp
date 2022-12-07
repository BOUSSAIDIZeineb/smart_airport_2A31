#include "mainwindowfournisseur.h"
#include "ui_mainwindowfournisseur.h"

MainWindowfournisseur::MainWindowfournisseur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowfournisseur)
{
    ui->setupUi(this);
}

MainWindowfournisseur::~MainWindowfournisseur()
{
    delete ui;
}
