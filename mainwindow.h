
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"employes.h"
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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

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

    void on_pushButton_22_clicked();

    void on_le_cins_textChanged(const QString &arg1);

    void on_triBox_currentTextChanged(const QString &arg1);

    void on_pb_imprimer_clicked();

private:
    Ui::MainWindow *ui;
    Employes Emp;
};

#endif // MAINWINDOW_H
