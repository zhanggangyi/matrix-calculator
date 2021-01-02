#ifndef EDITVARIABLE_H
#define EDITVARIABLE_H

#include <QDialog>
#include <QButtonGroup>
#include <QMessageBox>
#include <QComboBox>
#include "variablemanager.h"
#include "basestructure.h"
#include "myalgorithm.h"

namespace Ui {
class EditVariable;
}

class EditVariable : public QDialog
{
    Q_OBJECT

public:
    explicit EditVariable(QWidget *parent = 0);
    EditVariable(QWidget *parent, VariableManager* manager_);
    ~EditVariable();
    Ui::EditVariable *ui;
    VariableManager* manager;
    void init(Var old);
    QButtonGroup type_group, num_group;

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

    void on_type_matrix_clicked();

    void on_type_number_clicked();

};

#endif // EDITVARIABLE_H
