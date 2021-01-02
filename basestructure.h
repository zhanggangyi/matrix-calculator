#ifndef BASESTRUCTURE_H
#define BASESTRUCTURE_H

#include <QMap>
#include <QString>
#include <QVector>
#include <QStringList>
#include <QRegularExpression>
#include "matrix.h"
#include "field.h"

using namespace std;

// 定义三种类型：数据，数字，操作符
enum DataType {NONE_TYPE, NUM_TYPE, VECTOR_TYPE, MATRIX_TYPE, QPOLY_TYPE,RPOLY_TYPE};
enum NumType {RATIONAL_NUM, REAL_NUM};
// INV 逆 REF 化简 NOR 法式 TRS 转置 DET 行列式 EIG 特征多项式
enum ComputationType {ADD, SUB, MUL, DIV, INV, MREF, LREF, NOR, TRS, DET, EIG};

// 定义用于显示的类型名及数值名称
const QStringList typeName {"空类型", "数", "向量", "矩阵", "多项式"};
const QStringList numName {"有理数", "实数"};

// 定义字典，将运算符字符串转化为运算类型
const QMap<QString, ComputationType> s2c {{"+", ADD}, {"-", SUB}, {"*", MUL}, {"/", DIV},
                                         {"Inv", INV}, {"MRef", MREF}, {"LRef", LREF},{"Nor", NOR}, {"Trs", TRS},
                                         {"Det", DET}, {"Eig", EIG}};

// 匹配整数
const QRegularExpression type_int{"^\\d+$"};
// 匹配实数
const QRegularExpression type_real{"^\\d+\\.\\d*$"};
// 匹配变量
const QRegularExpression type_var{"[\u4e00-\u9fa5a-zA-Z]+"};

struct Val{
    Qnum nRational;
    Double nReal;
    Matrix<Qnum> mRational;
    Matrix<Double> mReal;
};

struct Var{
    QString name;
    DataType dataType;
    NumType numType;
    Val val;

    Var();

    // 变量声明时使用
    Var(QString name, DataType dataType_, NumType numType_);
    // 解析字符串至任意类型 s为整数或变量名
    Var(QString s);
    // 数字类型的直接生成
    Var(int n);
    Var(Double n);
    Var(Qnum n);

    // 转化至字符串
    QString toString();
    // 清除变量
    void clear();
};

extern QVector<Var> vars;
extern Var clipboard;

#endif // BASESTRUCTURE_H
