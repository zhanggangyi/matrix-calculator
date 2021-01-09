#include "variablemanager.h"
#include "field.h"
VariableManager::VariableManager(QWidget* parent_, QTreeView* view_, QTableWidget* table_, QComboBox* mList_)
{
    view = view_;
    table = table_;
    mList = mList_;
    parent = parent_;
    this->setParent(parent);
    row = 0;
    currentRow = -1;
    currentMatrix = nullptr;
    // 禁止修改
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 显示表头
    list_model = new QStandardItemModel(parent);
    QStringList varProperties{"名称", "数据类型", "数制", "值"};
    list_model->setHorizontalHeaderLabels(varProperties);
    view->show();
}

bool VariableManager::add(Var var)
{
    // 检测有无重名变量
    if(exist(var.name))
        return false;
    vars.push_back(var);
    if(var.dataType == MATRIX_TYPE){
        mList->addItem(var.name);
    }
    // 添加变量
    QStandardItem* name = new QStandardItem{var.name};
    QStandardItem* data_type = new QStandardItem{typeName[var.dataType]};
    QStandardItem* num_type = new QStandardItem{numName[var.numType]};
    QStandardItem* value = new QStandardItem{var.toString()};
    //这里要改一下
    list_model->setItem(row, name);
    list_model->setItem(row, 1, data_type);
    list_model->setItem(row, 2, num_type);
    list_model->setItem(row, 3, value);
    // 设置光标
    setCursor(row);
    ++row;
    // 显示
    view->setModel(list_model);
    view->show();
    if(var.dataType==MATRIX_TYPE)
    {
        int pos = mList->findText(var.name);
        mList->setItemText(pos, var.name);
        this->showMatrix(var.name);
    }
    return true;
}

bool VariableManager::del()
{
    // 未选中任何变量
    if(currentRow == -1)
        return false;
    // 若是矩阵，移除对应名称
    if(vars[currentRow].dataType == MATRIX_TYPE){
        mList->removeItem(mList->findText(vars[currentRow].name));
    }
    // 移除变量
    --row;
    vars.remove(currentRow);
    list_model->removeRow(currentRow);
    // 当列表为空
    if(row == 0)
        currentRow = -1;
    else
        setCursor(0);
    // 显示
    view->setModel(list_model);
    view->show();
    return true;
}

void VariableManager::refresh(Var var)          //在list中刷新变量的值
{
    // 更改变量
    int prvRow=currentRow;
    for(int i=0;i<row;i++)
        if(var.name==vars[i].name)
        {
            currentRow=i;
            break;
        }
    vars[currentRow] = var;
    QStandardItem* name = new QStandardItem{var.name};
    QStandardItem* data_type = new QStandardItem{typeName[var.dataType]};
    QStandardItem* num_type = new QStandardItem{numName[var.numType]};
    QStandardItem* value = new QStandardItem{var.toString()};
    list_model->setItem(currentRow, name);
    list_model->setItem(currentRow, 1, data_type);
    list_model->setItem(currentRow, 2, num_type);
    list_model->setItem(currentRow, 3, value);
    // 显示
    view->setModel(list_model);
    view->show();
    currentRow=prvRow;
}

bool VariableManager::set(QString name_, Var var)       //将名为name的变量值赋为var
{
    Var* ptr;
    if(!exist(name_))
        return false;
    for(auto& item:vars)
        if(item.name == name_)
        {
            ptr=&item;
            break;
        }
    ptr->name=var.name;
    ptr->dataType=var.dataType;
    ptr->numType=var.numType;
    ptr->val=var.val;
    refresh(var);
    // 若是矩阵 刷新矩阵列表
    if(var.dataType == MATRIX_TYPE){
       // 改mList中矩阵的名称
       int pos = mList->findText(name_);
       mList->setItemText(pos, var.name);
       this->showMatrix(var.name);
    }
    return true;
}

bool VariableManager::get(QString name, Var* box)       //寻找名为name的变量
{
    for(Var item: vars){
        if(item.name == name){
            *box = item;
            return true;
        }
    }
    return false;
}

bool VariableManager::exist(QString name)
{
    for(const auto& item:vars){
        if(item.name == name)
            return true;
    }
    return false;
}

Var VariableManager::getCurrent()
{
    return vars[currentRow];
}

void VariableManager::setCursor(int line)
{
    currentRow = line;
    view->setCurrentIndex(list_model->index(line, 0));
}

bool VariableManager::find_next(QRegularExpression &re)
{
    for(int i=currentRow + 1; i < row; i++){
        if(re.match(vars[i].name).hasMatch()){
            setCursor(i);
            return true;
        }
    }
    for(int i=0;i <= currentRow; i++){
        if(re.match(vars[i].name).hasMatch()){
            setCursor(i);
            return true;
        }
    }
    return false;
}

void VariableManager::setMatrixElemValue(int table_row, int table_column, QString value_)
{
    if(currentMatrix == nullptr){
        throw "no matrix selected";
        return;
    }
    if(currentMatrix->numType == RATIONAL_NUM){
        currentMatrix->val.mRational.element[table_row][table_column] = toRational(value_);
        return ;
    }
    else if(currentMatrix->numType == REAL_NUM){
        currentMatrix->val.mReal.element[table_row][table_column].value = value_.toDouble();
    }
}

void VariableManager::setCurrentMatrix(const QString &name)
{
    for(Var& e: vars){
        if(e.name == name){
            currentMatrix = &e;
        }
    }
}

bool VariableManager::copy()
{
    clipboard.clear();
    QString name="clipboard";
    clipboard.name=name;
    Var v=getCurrent();
    clipboard.dataType=v.dataType;
    clipboard.numType=v.numType;
    if(clipboard.dataType==NUM_TYPE&&clipboard.numType==RATIONAL_NUM)
        clipboard.val.nRational=v.val.nRational;
    else if(clipboard.dataType==NUM_TYPE&&clipboard.numType==REAL_NUM)
        clipboard.val.nReal=v.val.nReal;
    else if(clipboard.dataType==MATRIX_TYPE&&clipboard.numType==RATIONAL_NUM)
        clipboard.val.mRational=v.val.mRational;
    else if(clipboard.dataType==MATRIX_TYPE&&clipboard.numType==REAL_NUM)
        clipboard.val.mReal=v.val.mReal;
    return true;
}

bool VariableManager::paste()
{
    Var *p=&vars[currentRow];
    p->clear();

    p->dataType=clipboard.dataType;
    p->numType=clipboard.numType;
    if(clipboard.dataType==NUM_TYPE&&clipboard.numType==RATIONAL_NUM)
        p->val.nRational=clipboard.val.nRational;
    else if(clipboard.dataType==NUM_TYPE&&clipboard.numType==REAL_NUM)
        p->val.nReal=clipboard.val.nReal;
    else if(clipboard.dataType==MATRIX_TYPE&&clipboard.numType==RATIONAL_NUM)
        p->val.mRational=clipboard.val.mRational;
    else if(clipboard.dataType==MATRIX_TYPE&&clipboard.numType==REAL_NUM)
        p->val.mReal=clipboard.val.mReal;
    refresh(*p);
    mList->setCurrentText(p->name);
    return true;
}

void VariableManager::showMatrix(const QString &s)
{
    emit mList->currentIndexChanged(s);
    mList->setCurrentText(s);
}
