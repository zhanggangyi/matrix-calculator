#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <QStack>
#include <QString>
#include <QStringList>
#include <QChar>
#include <QDebug>
#include <QMap>
#include <QRegularExpression>
#include <stdexcept>
#include "basestructure.h"
#include "computation.h"
#include "variablemanager.h"

using namespace std;

// 运算符结构，描述了运算符名称及结合性
struct Manipulator{
    QString name;
    bool binary;
    operator<(const Manipulator& m) const{
        if(name != m.name)
            return name < m.name;
        return binary < m.binary;
    }
};
// 匹配原始字符串中所有表达，运算符，数字，变量
const QRegularExpression pattern{"\\d+(\\.\\d*)?|[\u4e00-\u9fa5a-zA-Z]+|[\\+\\-\\*/\\(\\)÷]"};

// 匹配数字
const QRegularExpression pattern_num{"\\d+(\\.\\d*)?"};

// 匹配变量
const QRegularExpression pattern_variable{"^[\u4e00-\u9fa5a-zA-Z][\u4e00-\u9fa5a-z0-9A-Z]*"};

// 匹配操作符
const QRegularExpression pattern_operator{"[\\+\\-\\*/\\(\\)]|Inv|Ref|Nor|Trs|Det|Eig|MRef|LRef"};

// 定义操作符名称及其优先级
const QMap<Manipulator, int> operator_priority{
        {{.name="+", .binary=true}, 4},
        {{.name="+", .binary=false}, 2},
        {{.name="-", .binary=true}, 4},
        {{.name="-", .binary=false}, 2},
        {{.name="*", .binary=true}, 3},
        {{.name="/", .binary=true}, 3},
        {{.name="Inv", .binary=false}, 2},
        {{.name="Ref", .binary=false}, 2},
        {{.name="Nor", .binary=false}, 2},
        {{.name="Trs", .binary=false}, 2},
        {{.name="Det", .binary=false}, 2},
        {{.name="Eig", .binary=false}, 2},
        {{.name="(", .binary=true}, 999}};
const bool left_composition[10]{true, true, false, true, true, true, true, true, true, true};

// 切分原始表达式为子串
QStringList split(QString input);

// 重新排序元素为后缀表达式
QStringList sort_elems(QStringList expression);

// 计算表达式
bool caculate(QStringList expression, VariableManager* manager, QString& rtv);

// 计算单个运算
void run(Var v1, Var v2, QString oper, Var& result);

#endif // MYALGORITHM_H
