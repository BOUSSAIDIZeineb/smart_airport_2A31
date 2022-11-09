#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //fournisseur fourn;

private slots:
    void on_ajout_clicked();

    void on_supprimer_clicked();

    void on_update_clicked();

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_3_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MainWindow *ui;
    fournisseur fourn;
};

#endif // MAINWINDOW_H
