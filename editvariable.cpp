#include "editvariable.h"
#include "ui_editvariable.h"
#include "field.h"


EditVariable::EditVariable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditVariable)
{
    ui->setupUi(this);
}

EditVariable::~EditVariable()
{
    delete ui;
}

EditVariable::EditVariable(QWidget *parent, VariableManager* manager_) :
    QDialog(parent),
    ui(new Ui::EditVariable)
{
    ui->setupUi(this);
    manager = manager_;
    // 将按钮分组
    type_group.addButton(ui->type_number, NUM_TYPE);
    type_group.addButton(ui->type_matrix, MATRIX_TYPE);
    num_group.addButton(ui->num_Q, RATIONAL_NUM);
    num_group.addButton(ui->num_R, REAL_NUM);

}

void EditVariable::on_confirm_clicked()
{
    QString name, value;
    DataType data_type;
    NumType num_type;
    name = ui->variable_name->text();
     //检测名称是否合法
    if(!pattern_variable.match(name).hasMatch()){
        QMessageBox::warning(this, "警告", "变量名不合法", QStringLiteral("确定"));
        ui->variable_name->clear();
        return;
    }
    data_type = (DataType)type_group.checkedId();
    num_type = (NumType)num_group.checkedId();
    value = ui->variable_value->text();

    Var box{name, data_type, num_type};         //现在要修改的值
    Var old = manager->getCurrent();            //原来的值
    // 检测是否输入数字
    if(ui->variable_value->isEnabled()){
        if(num_type == RATIONAL_NUM)
        {
            box.val.nRational = toRational(ui->variable_value->text());
        }
        else
            box.val.nReal.value = ui->variable_value->text().toDouble();
    }
    if(ui->Row->isEnabled()){
      //   检测矩阵行数列数输入是否合法
        QRegularExpression pattern_int{"^[1-9][0-9]*$"};
        if(!pattern_int.match(ui->Row->text()).hasMatch() || !pattern_int.match(ui->Column->text()).hasMatch()){
            QMessageBox::warning(this, "警告", "行列必须为大于0的整数", QStringLiteral("确定"));
            ui->Row->clear();
            ui->Column->clear();
            return;
        }
       else{
            // 设置矩阵参数
            if(box.numType == RATIONAL_NUM)
            {
                Matrix<Qnum> m;
                m.row = ui->Row->text().toInt();
                m.column = ui->Column->text().toInt();
                if(old.numType == RATIONAL_NUM)
                {
                    // 填上原始的数值
                    Matrix<Qnum> old_m = old.val.mRational;
                    for(int i=1; i <= min(m.row, old_m.row); i++){
                        for(int j=1; j <= min(m.column, old_m.column); j++){
                            m.element[i][j] = old_m.element[i][j];
                        }
                    }
                }
              else if(old.numType == REAL_NUM)
                {
                    Matrix<Double> old_m ;          //调用构造函数，赋值成0矩阵
                    //需要做一个警告：从实数到有理数的转换
                    QMessageBox::warning(this, "警告", "从实数到有理数的转换会丢失当前值",
                                                    QStringLiteral("确定"));
                    for(int i=1; i <= min(m.row, old_m.row); i++){
                        for(int j=1; j <= min(m.column, old_m.column); j++){
                         m.element[i][j] = Qnum{};

                        }
                    }
                }
                box.val.mRational = m;
            }
            else if(box.numType == REAL_NUM)
            {
                Matrix<Double> m;
                m.row = ui->Row->text().toInt();
                m.column = ui->Column->text().toInt();

                if(old.numType == RATIONAL_NUM){
                    Matrix<Qnum> old_m = old.val.mRational;         //你真的确定吗 old getcur得到的变量有mRational这个数值
                    for(int i=1; i <= min(m.row, old_m.row); i++){
                        for(int j=1; j <= min(m.column, old_m.column); j++){
                           m.element[i][j] = old_m.element[i][j].toDouble();
;
                        }
                    }
                }
                else if(old.numType == REAL_NUM){
                    Matrix<Double> old_m = old.val.mReal;
                    for(int i=1; i <= min(m.row, old_m.row); i++){
                        for(int j=1; j <= min(m.column, old_m.column); j++){
                            m.element[i][j] = old_m.element[i][j];
                        }
                    }
                }
                box.val.mReal= m;
            }
        }
    }
    // 检测变量是否重复
    if(!manager->set(old.name, box)){
            QMessageBox::warning(this, "警告", "变量名不能与已有变量名重复", QStringLiteral("确定"));
            ui->variable_name->clear();
        }
    else{
        this->close();
    }
}

void EditVariable::on_cancel_clicked()
{
    this->close();
}

void EditVariable::on_type_matrix_clicked()
{
    ui->variable_value->setEnabled(false);
    ui->Row->setEnabled(true);
    ui->Column->setEnabled(true);
}

void EditVariable::on_type_number_clicked()
{
    ui->variable_value->setEnabled(true);
    ui->Row->setEnabled(false);
    ui->Column->setEnabled(false);
}

void EditVariable::init(Var old)
{
    ui->variable_name->setText(old.name);
    if(old.dataType==MATRIX_TYPE)
    {
        ui->type_matrix->click();
        if(old.numType==RATIONAL_NUM)
        {
            ui->num_Q->click();
            ui->Row->setText(QString::number(old.val.mRational.row));
            ui->Column->setText(QString::number(old.val.mRational.column));
        }
        else if(old.numType==REAL_NUM)
        {
            ui->num_R->click();
            ui->Row->setText(QString::number(old.val.mReal.row));
            ui->Column->setText(QString::number(old.val.mReal.column));
        }
    }
    else if(old.dataType==NUM_TYPE)
    {
        ui->type_number->click();
        if(old.numType==RATIONAL_NUM)
        {
            ui->num_Q->click();
            ui->variable_value->setText(toQstring(old.val.nRational));
        }
        else if(old.numType==REAL_NUM)
        {
            ui->num_R->click();
            ui->variable_value->setText(QString::number(old.val.nReal.value));
        }
    }
}



