#ifndef ADDVARIABLE_H
#define ADDVARIABLE_H

#include <QDialog>
#include <QButtonGroup>
#include <QMessageBox>
#include "variablemanager.h"
#include "basestructure.h"
#include "myalgorithm.h"
#include "matrix.h"

namespace Ui {
class AddVariable;
}

class AddVariable : public QDialog
{
    Q_OBJECT

public:
    explicit AddVariable(QWidget *parent = 0);
    AddVariable(QWidget *parent, VariableManager* manager_);
    ~AddVariable();
    void clear();
    void display_matrix();
private slots:

    void on_confirm_clicked();

    void on_cancel_clicked();

    void on_type_matrix_clicked();

    void on_type_number_clicked();

private:
    Ui::AddVariable* ui;
    VariableManager* manager;
    QButtonGroup type_group, num_group;

};

#endif // ADDVARIABLE_H
