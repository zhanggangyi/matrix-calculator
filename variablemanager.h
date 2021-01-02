#ifndef VARIABLEMANAGER_H
#define VARIABLEMANAGER_H

#include "basestructure.h"
#include <QString>
#include <QStringList>
#include <QMap>
#include <QTreeView>
#include <QStandardItemModel>
#include <QVector>
#include <QObject>
#include <QTableView>
#include <QComboBox>
#include <QRegularExpression>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>

class VariableManager: public QObject
{
private:
    QStandardItemModel* list_model;
    QTreeView* view;
    QTableWidget* table;
    QWidget* parent;
    QComboBox* mList;
    int row;
    int currentRow;
    Var* currentMatrix;
public:
    VariableManager(QWidget* parent_, QTreeView* view_, QTableWidget* table_, QComboBox* mList_);
    bool add(Var var);
    bool del();
    void refresh(Var var);
    bool set(QString name, Var var);
    bool get(QString name, Var* box);
    bool exist(QString name);
    Var getCurrent();
    void setCursor(int line);
    void move_up();
    void move_down();
    bool find_next(QRegularExpression &re);
    void setCurrentMatrix(const QString& name);
    void setMatrixElemValue(int table_row, int table_column, QString value_);
    bool copy();
    bool paste();
    void showMatrix(const QString& matrix);
};

#endif // VARIABLEMANAGER_H
