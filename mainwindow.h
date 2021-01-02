#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QMessageBox>
#include "myalgorithm.h"
#include "variablemanager.h"
#include "computation.h"

#include "addvariable.h"
#include "editvariable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Num_1_clicked();

    void on_Num_2_clicked();

    void on_Num_3_clicked();

    void on_Num_4_clicked();

    void on_Num_5_clicked();

    void on_Num_6_clicked();

    void on_Num_7_clicked();

    void on_Num_8_clicked();

    void on_Num_9_clicked();

    void on_Num_0_clicked();

    void on_BackSpace_clicked();

    void on_Num_Point_clicked();

    void on_Plus_clicked();

    void on_Subtract_clicked();

    void on_Multiply_clicked();

    void on_Divide_clicked();

    void on_left_bracket_clicked();

    void on_right_bracket_clicked();

    void on_A_clicked();

    void on_B_clicked();

    void on_C_clicked();

    void on_D_clicked();

    void on_Equal_clicked();

    void on_Clear_clicked();

    void on_addVariable_clicked();

    void on_editVariable_clicked();

    void on_deleteVariable_clicked();

    void on_varList_pressed(const QModelIndex &index);

    void on_find_clicked();

    void on_matrixList_currentIndexChanged(const QString &arg1);

    void on_matrixView_itemChanged(QTableWidgetItem *item);

    void on_Inv_clicked();

    void on_LRef_clicked();

    void on_MRef_clicked();

    void on_In_clicked();

    void on_copy_clicked();

    void on_paste_clicked();

    void on_Det_clicked();

    void on_varList_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    AddVariable *addvar;
    EditVariable *edivar;
    QStringList matrixs;
    QStandardItemModel* table, * history;
    VariableManager* manager;
};

#endif // MAINWINDOW_H
