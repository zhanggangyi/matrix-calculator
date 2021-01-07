#include "addvariable.h"
#include "ui_addvariable.h"

AddVariable::AddVariable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddVariable)
{
    ui->setupUi(this);
}

AddVariable::AddVariable(QWidget *parent, VariableManager *manager_) :
    QDialog(parent),
    ui(new Ui::AddVariable)
{
    ui->setupUi(this);
    manager = manager_;
    // 将按钮分组
    type_group.addButton(ui->type_number, NUM_TYPE);
    type_group.addButton(ui->type_matrix, MATRIX_TYPE);
    num_group.addButton(ui->num_Q, RATIONAL_NUM);
    num_group.addButton(ui->num_R, REAL_NUM);
    // 设置默认按下的按钮
    ui->type_number->click();
    ui->num_Q->click();
}

AddVariable::~AddVariable()
{
    delete ui;
}

void AddVariable::on_confirm_clicked()
{
    QString name, value;
    DataType data_type;
    NumType num_type;
    name = ui->variable_name->text();
    // 检测名称是否合法
    if(!pattern_variable.match(name).hasMatch()){
        QMessageBox::warning(this, "警告", "变量名不合法", QStringLiteral("确定"));
        ui->variable_name->clear();
        return;
    }
    data_type = (DataType)type_group.checkedId();
    num_type = (NumType)num_group.checkedId();
    value = ui->variable_value->text();
    Var box{name, data_type, num_type};
    // 检测是否输入数字
    if(ui->variable_value->isEnabled()){
        if(num_type == RATIONAL_NUM)
            box.val.nRational = toRational(ui->variable_value->text());
        else
            box.val.nReal.value = ui->variable_value->text().toDouble();
    }
    // 检测行数列数输入是否合法
    if(ui->Row->isEnabled()){
        QRegularExpression pattern_int{"^[1-9][0-9]*$"};
        if(!pattern_int.match(ui->Row->text()).hasMatch() || !pattern_int.match(ui->Column->text()).hasMatch()){
            QMessageBox::warning(this, "警告", "行列必须为大于0的整数", QStringLiteral("确定"));
            ui->Row->clear();
            ui->Column->clear();
            return;
        }
        else{
            // 设置矩阵参数
            if(box.numType == RATIONAL_NUM){
                Matrix<Qnum> m;
                m.row = ui->Row->text().toInt();
                m.column = ui->Column->text().toInt();
                box.val.mRational = m;
            }
            else if(box.numType == REAL_NUM){
                Matrix<Double> m;
                m.row = ui->Row->text().toInt();
                m.column = ui->Column->text().toInt();
                box.val.mReal= m;
            }
        }
    }
    // 检测变量是否重复
    if(!manager->add(box))
    {
        QMessageBox::warning(this, "警告", "变量名不能与已有变量名重复", QStringLiteral("确定"));
        ui->variable_name->clear();
    }
    else
    {
        this->clear();
        if(data_type=MATRIX_TYPE)
        {
            manager->showMatrix(box.name);
        }
        this->close();
    }
}

void AddVariable::on_cancel_clicked()
{
    this->close();
}


void AddVariable::on_type_matrix_clicked()
{
    ui->variable_value->setEnabled(false);
    ui->Row->setEnabled(true);
    ui->Column->setEnabled(true);
}

void AddVariable::on_type_number_clicked()
{
    ui->variable_value->setEnabled(true);
    ui->Row->setEnabled(false);
    ui->Column->setEnabled(false);
}

void AddVariable::clear()
{
    ui->variable_name->clear();
    ui->type_number->click();
    ui->num_Q->click();
    ui->variable_value->clear();
    ui->Row->clear();
    ui->Column->clear();
}

void AddVariable::display_matrix()
{
    //这里还没做
}
