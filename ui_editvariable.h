/********************************************************************************
** Form generated from reading UI file 'editvariable.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITVARIABLE_H
#define UI_EDITVARIABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditVariable
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *variable_name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QRadioButton *type_number;
    QRadioButton *type_matrix;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QRadioButton *num_Q;
    QRadioButton *num_R;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *variable_value;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *Row;
    QLabel *label_6;
    QLineEdit *Column;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *EditVariable)
    {
        if (EditVariable->objectName().isEmpty())
            EditVariable->setObjectName(QStringLiteral("EditVariable"));
        EditVariable->resize(411, 312);
        verticalLayoutWidget = new QWidget(EditVariable);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 411, 311));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 0));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        variable_name = new QLineEdit(verticalLayoutWidget);
        variable_name->setObjectName(QStringLiteral("variable_name"));

        horizontalLayout->addWidget(variable_name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        type_number = new QRadioButton(verticalLayoutWidget);
        type_number->setObjectName(QStringLiteral("type_number"));
        type_number->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        horizontalLayout_3->addWidget(type_number);

        type_matrix = new QRadioButton(verticalLayoutWidget);
        type_matrix->setObjectName(QStringLiteral("type_matrix"));
        type_matrix->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        horizontalLayout_3->addWidget(type_matrix);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_3->setTextFormat(Qt::AutoText);
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_3);

        num_Q = new QRadioButton(verticalLayoutWidget);
        num_Q->setObjectName(QStringLiteral("num_Q"));
        num_Q->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        horizontalLayout_2->addWidget(num_Q);

        num_R = new QRadioButton(verticalLayoutWidget);
        num_R->setObjectName(QStringLiteral("num_R"));
        num_R->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        horizontalLayout_2->addWidget(num_R);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_4);

        variable_value = new QLineEdit(verticalLayoutWidget);
        variable_value->setObjectName(QStringLiteral("variable_value"));

        horizontalLayout_5->addWidget(variable_value);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        horizontalLayout_6->addWidget(label_5);

        Row = new QLineEdit(verticalLayoutWidget);
        Row->setObjectName(QStringLiteral("Row"));

        horizontalLayout_6->addWidget(Row);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        horizontalLayout_6->addWidget(label_6);

        Column = new QLineEdit(verticalLayoutWidget);
        Column->setObjectName(QStringLiteral("Column"));

        horizontalLayout_6->addWidget(Column);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        horizontalLayout_6->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(100, -1, -1, -1);
        confirm = new QPushButton(verticalLayoutWidget);
        confirm->setObjectName(QStringLiteral("confirm"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(confirm->sizePolicy().hasHeightForWidth());
        confirm->setSizePolicy(sizePolicy);
        confirm->setMaximumSize(QSize(100, 16777215));
        confirm->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        horizontalLayout_4->addWidget(confirm);

        cancel = new QPushButton(verticalLayoutWidget);
        cancel->setObjectName(QStringLiteral("cancel"));
        sizePolicy.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy);
        cancel->setMaximumSize(QSize(100, 16777215));
        cancel->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        cancel->setFlat(false);

        horizontalLayout_4->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(EditVariable);

        cancel->setDefault(false);


        QMetaObject::connectSlotsByName(EditVariable);
    } // setupUi

    void retranslateUi(QDialog *EditVariable)
    {
        EditVariable->setWindowTitle(QApplication::translate("EditVariable", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("EditVariable", "\345\217\230\351\207\217\345\220\215\347\247\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("EditVariable", "\345\217\230\351\207\217\347\261\273\345\236\213", Q_NULLPTR));
        type_number->setText(QApplication::translate("EditVariable", "\346\225\260\345\255\227", Q_NULLPTR));
        type_matrix->setText(QApplication::translate("EditVariable", "\347\237\251\351\230\265", Q_NULLPTR));
        label_3->setText(QApplication::translate("EditVariable", "\346\225\260\345\210\266", Q_NULLPTR));
        num_Q->setText(QApplication::translate("EditVariable", "\346\234\211\347\220\206\346\225\260Q", Q_NULLPTR));
        num_R->setText(QApplication::translate("EditVariable", "\345\256\236\346\225\260R", Q_NULLPTR));
        label_4->setText(QApplication::translate("EditVariable", "\346\225\260\345\200\274\357\274\210\344\273\205\346\225\260\345\255\227\345\217\257\350\265\213\345\200\274\357\274\211", Q_NULLPTR));
        label_5->setText(QApplication::translate("EditVariable", "\347\237\251\351\230\265\345\244\247\345\260\217", Q_NULLPTR));
        label_6->setText(QApplication::translate("EditVariable", "\350\241\214", Q_NULLPTR));
        label_7->setText(QApplication::translate("EditVariable", "\345\210\227", Q_NULLPTR));
        confirm->setText(QApplication::translate("EditVariable", "\347\241\256\350\256\244", Q_NULLPTR));
        cancel->setText(QApplication::translate("EditVariable", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditVariable: public Ui_EditVariable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITVARIABLE_H
