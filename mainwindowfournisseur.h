#ifndef MAINWINDOWFOURNISSEUR_H
#define MAINWINDOWFOURNISSEUR_H

#include <QMainWindow>

namespace Ui {
class MainWindowfournisseur;
}

class MainWindowfournisseur : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowfournisseur(QWidget *parent = nullptr);
    ~MainWindowfournisseur();

private:
    Ui::MainWindowfournisseur *ui;
};

#endif // MAINWINDOWFOURNISSEUR_H
