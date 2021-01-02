#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "field.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化变量列表
    manager = new VariableManager{this, ui->varList, ui->matrixView, ui->matrixList};

    // 初始化子窗口
    addvar = new AddVariable(this, manager);
    edivar = new EditVariable(this, manager);

    // 初始化运算符
    initComputaion();

    // 初始化历史记录
    history = new QStandardItemModel(this);


    // 设置光标
    ui->InputLine->setFocus();

    // 测试变量列表
    Var b1{"A", MATRIX_TYPE, RATIONAL_NUM}, b2{"B", MATRIX_TYPE, RATIONAL_NUM}, b3{"C",MATRIX_TYPE, REAL_NUM},b4{"D", MATRIX_TYPE, REAL_NUM};
    manager->add(b1);
    manager->add(b2);
    manager->add(b3);
    manager->add(b4);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Num_1_clicked()
{
    ui->InputLine->insert("1");
}

void MainWindow::on_Num_2_clicked()
{
    ui->InputLine->insert("2");
}

void MainWindow::on_Num_3_clicked()
{
    ui->InputLine->insert("3");
}

void MainWindow::on_Num_4_clicked()
{
    ui->InputLine->insert("4");
}

void MainWindow::on_Num_5_clicked()
{
    ui->InputLine->insert("5");
}

void MainWindow::on_Num_6_clicked()
{
    ui->InputLine->insert("6");
}

void MainWindow::on_Num_7_clicked()
{
    ui->InputLine->insert("7");
}

void MainWindow::on_Num_8_clicked()
{
    ui->InputLine->insert("8");
}

void MainWindow::on_Num_9_clicked()
{
    ui->InputLine->insert("9");
}

void MainWindow::on_Num_0_clicked()
{
    ui->InputLine->insert("0");
}

void MainWindow::on_BackSpace_clicked()
{
    ui->InputLine->backspace();
}

void MainWindow::on_Num_Point_clicked()
{
    ui->InputLine->insert(".");
}

void MainWindow::on_Plus_clicked()
{
    ui->InputLine->insert("+");
}

void MainWindow::on_Subtract_clicked()
{
    ui->InputLine->insert("-");
}

void MainWindow::on_Multiply_clicked()
{
    ui->InputLine->insert("*");
}

void MainWindow::on_Divide_clicked()
{
    ui->InputLine->insert("/");
}

void MainWindow::on_left_bracket_clicked()
{
    ui->InputLine->insert("(");
}

void MainWindow::on_right_bracket_clicked()
{
    ui->InputLine->insert(")");
}

void MainWindow::on_A_clicked()
{
    ui->InputLine->insert("A");
}

void MainWindow::on_B_clicked()
{
    ui->InputLine->insert("B");
}

void MainWindow::on_C_clicked()
{
    ui->InputLine->insert("C");
}

void MainWindow::on_D_clicked()
{
    ui->InputLine->insert("D");
}

void MainWindow::on_Equal_clicked()
{
    QString result;
    QStringList strlist;
    QString expression{ui->InputLine->text()};
    expression.remove(QChar(' '));
    if(expression == ""){
        ui->InputLine->clear();
        return;
    }
    strlist = split(expression);
    strlist = sort_elems(strlist);
    if(caculate(strlist, manager, result)){
        ui->InputLine->setText(result);
    }
    else{
        ui->InputLine->setText(result);
        return;
    }
    QStandardItem* expr = new QStandardItem{expression + "=" + result};
    history->appendRow(expr);
    ui->History->setModel(history);

    Var b;
    ui->matrixView->clear();
    manager->get(result, &b);
    manager->setCurrentMatrix(result);
    ui->matrixList->setCurrentText(b.name);
}

void MainWindow::on_Clear_clicked()
{
    ui->InputLine->clear();
}

void MainWindow::on_addVariable_clicked()
{
    addvar->show();
}

void MainWindow::on_editVariable_clicked()
{
    edivar->show();
    Var old=manager->getCurrent();
    edivar->init(old);

}

void MainWindow::on_deleteVariable_clicked()
{
    int result = QMessageBox::warning(this, "警告", "确定要删除吗？",
                                QStringLiteral("确定"), QStringLiteral("取消"));
    switch (result) {
    case 0:
        manager->del();
        break;
    case 1:
        qDebug() << "No";
        break;
    default:
        break;
    }
}

void MainWindow::on_varList_pressed(const QModelIndex &index)
{
    manager->setCursor(index.row());
}


void MainWindow::on_find_clicked()
{
    QRegularExpression re{ui->findName->text()};
    if(!manager->find_next(re)){
        QMessageBox::warning(this, "警告", "找不到对应的变量",
                            QStringLiteral("确定"));
    }
}
//改变当前索引
void MainWindow::on_matrixList_currentIndexChanged(const QString &arg1)
{
    Var b;
    int row=0, column=0;
    ui->matrixView->clear();
    manager->get(arg1, &b);
    manager->setCurrentMatrix(arg1);
    if(b.numType == RATIONAL_NUM){
        row = b.val.mRational.row;
        column = b.val.mRational.column;
    }
    else if(b.numType == REAL_NUM){
        row = b.val.mReal.row;
        column = b.val.mReal.column;
    }
    ui->matrixView->setRowCount(row);
    ui->matrixView->setColumnCount(column);
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(b.numType == RATIONAL_NUM){
                try{
                    ui->matrixView->setItem(i, j, new QTableWidgetItem{ toQstring(b.val.mRational.element[i+1][j+1]) } );
                }
                catch(const char* s){
                    qDebug() << s;
                }
            }
            else if(b.numType == REAL_NUM){
                ui->matrixView->setItem(i, j, new QTableWidgetItem{QString::number(b.val.mReal.element[i+1][j+1].value)});
            }
        }
    }
}

void MainWindow::on_matrixView_itemChanged(QTableWidgetItem *item)
{
    if(!pattern_num.match(item->text()).hasMatch()){
        item->setText("0");
        manager->setMatrixElemValue(item->row()+1, item->column()+1, "0");
        return;
    }
    manager->setMatrixElemValue(item->row()+1, item->column()+1, item->text());
}

void MainWindow::on_Inv_clicked()
{
    ui->InputLine->insert("Inv()");
}

void MainWindow::on_MRef_clicked()
{
     ui->InputLine->insert("MRef()");
}

void MainWindow::on_LRef_clicked()
{
    ui->InputLine->insert("LRef()");
}


void MainWindow::on_In_clicked()
{
    ui->InputLine->insert("I()");
}

void MainWindow::on_copy_clicked()
{
    manager->copy();
}

void MainWindow::on_paste_clicked()
{
    manager->paste();
}

void MainWindow::on_Det_clicked()
{
    ui->InputLine->insert("Det()");
}

void MainWindow::on_varList_doubleClicked(const QModelIndex &index)
{
   Var v = manager->getCurrent();
   manager->showMatrix(v.name);
}
