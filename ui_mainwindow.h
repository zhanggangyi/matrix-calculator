/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *readFile;
    QAction *saveFile;
    QAction *action;
    QAction *saveAsFile;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QComboBox *matrixList;
    QTableWidget *matrixView;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *InputLine;
    QFrame *line_4;
    QGridLayout *gridLayout;
    QPushButton *LRef;
    QPushButton *pushButton_12;
    QPushButton *In;
    QPushButton *MRef;
    QPushButton *Det;
    QPushButton *Num_2;
    QPushButton *Nor;
    QPushButton *C;
    QPushButton *pushButton_34;
    QPushButton *BackSpace;
    QPushButton *Clear;
    QPushButton *Divide;
    QPushButton *pushButton_32;
    QPushButton *left_bracket;
    QPushButton *Inv;
    QPushButton *Multiply;
    QPushButton *Num_9;
    QPushButton *A;
    QPushButton *Subtract;
    QPushButton *pushButton_13;
    QPushButton *pushButton_3;
    QPushButton *Equal;
    QPushButton *Num_0;
    QPushButton *Plus;
    QPushButton *Num_6;
    QPushButton *Num_7;
    QPushButton *Num_8;
    QPushButton *Num_1;
    QPushButton *Num_3;
    QPushButton *Num_4;
    QPushButton *Num_5;
    QPushButton *right_bracket;
    QPushButton *D;
    QPushButton *B;
    QPushButton *Num_Point;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QTreeView *varList;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *findName;
    QPushButton *find;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QPushButton *addVariable;
    QPushButton *deleteVariable;
    QPushButton *editVariable;
    QPushButton *pushButton_25;
    QPushButton *copy;
    QPushButton *paste;
    QHBoxLayout *horizontalLayout;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_3;
    QListView *History;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1501, 788);
        readFile = new QAction(MainWindow);
        readFile->setObjectName(QStringLiteral("readFile"));
        saveFile = new QAction(MainWindow);
        saveFile->setObjectName(QStringLiteral("saveFile"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        saveAsFile = new QAction(MainWindow);
        saveAsFile->setObjectName(QStringLiteral("saveAsFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1465, 686));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        verticalLayout_5->addWidget(label_5, 0, Qt::AlignHCenter);

        matrixList = new QComboBox(horizontalLayoutWidget);
        matrixList->setObjectName(QStringLiteral("matrixList"));
        QFont font;
        font.setFamily(QStringLiteral("Yu Gothic UI"));
        font.setPointSize(12);
        matrixList->setFont(font);

        verticalLayout_5->addWidget(matrixList);

        matrixView = new QTableWidget(horizontalLayoutWidget);
        matrixView->setObjectName(QStringLiteral("matrixView"));
        matrixView->setMinimumSize(QSize(600, 600));

        verticalLayout_5->addWidget(matrixView);


        horizontalLayout_3->addLayout(verticalLayout_5);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 32pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        verticalLayout_2->addWidget(label_4, 0, Qt::AlignHCenter);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        InputLine = new QLineEdit(horizontalLayoutWidget);
        InputLine->setObjectName(QStringLiteral("InputLine"));
        InputLine->setStyleSheet(QStringLiteral("font: 12pt \"Yu Gothic UI\";"));

        horizontalLayout_5->addWidget(InputLine);


        verticalLayout_8->addLayout(horizontalLayout_5);

        line_4 = new QFrame(horizontalLayoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_4);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LRef = new QPushButton(horizontalLayoutWidget);
        LRef->setObjectName(QStringLiteral("LRef"));
        LRef->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(LRef, 2, 1, 1, 1);

        pushButton_12 = new QPushButton(horizontalLayoutWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(pushButton_12, 3, 0, 1, 1);

        In = new QPushButton(horizontalLayoutWidget);
        In->setObjectName(QStringLiteral("In"));
        In->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(In, 5, 1, 1, 1);

        MRef = new QPushButton(horizontalLayoutWidget);
        MRef->setObjectName(QStringLiteral("MRef"));
        MRef->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(MRef, 2, 0, 1, 1);

        Det = new QPushButton(horizontalLayoutWidget);
        Det->setObjectName(QStringLiteral("Det"));
        Det->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Det, 1, 1, 1, 1);

        Num_2 = new QPushButton(horizontalLayoutWidget);
        Num_2->setObjectName(QStringLiteral("Num_2"));
        Num_2->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Num_2, 3, 4, 1, 1);

        Nor = new QPushButton(horizontalLayoutWidget);
        Nor->setObjectName(QStringLiteral("Nor"));
        Nor->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Nor, 3, 1, 1, 1);

        C = new QPushButton(horizontalLayoutWidget);
        C->setObjectName(QStringLiteral("C"));
        C->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(C, 2, 2, 1, 1);

        pushButton_34 = new QPushButton(horizontalLayoutWidget);
        pushButton_34->setObjectName(QStringLiteral("pushButton_34"));
        pushButton_34->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(pushButton_34, 0, 3, 1, 1);

        BackSpace = new QPushButton(horizontalLayoutWidget);
        BackSpace->setObjectName(QStringLiteral("BackSpace"));
        BackSpace->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(BackSpace, 0, 5, 1, 1);

        Clear = new QPushButton(horizontalLayoutWidget);
        Clear->setObjectName(QStringLiteral("Clear"));
        Clear->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Clear, 0, 4, 1, 1);

        Divide = new QPushButton(horizontalLayoutWidget);
        Divide->setObjectName(QStringLiteral("Divide"));
        Divide->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Divide, 0, 6, 1, 1);

        pushButton_32 = new QPushButton(horizontalLayoutWidget);
        pushButton_32->setObjectName(QStringLiteral("pushButton_32"));
        pushButton_32->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(pushButton_32, 0, 0, 1, 1);

        left_bracket = new QPushButton(horizontalLayoutWidget);
        left_bracket->setObjectName(QStringLiteral("left_bracket"));
        left_bracket->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(left_bracket, 5, 2, 1, 1);

        Inv = new QPushButton(horizontalLayoutWidget);
        Inv->setObjectName(QStringLiteral("Inv"));
        Inv->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Inv, 0, 1, 1, 1);

        Multiply = new QPushButton(horizontalLayoutWidget);
        Multiply->setObjectName(QStringLiteral("Multiply"));
        Multiply->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Multiply, 1, 6, 1, 1);

        Num_9 = new QPushButton(horizontalLayoutWidget);
        Num_9->setObjectName(QStringLiteral("Num_9"));
        Num_9->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Num_9, 1, 5, 1, 1);

        A = new QPushButton(horizontalLayoutWidget);
        A->setObjectName(QStringLiteral("A"));
        A->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(A, 0, 2, 1, 1);

        Subtract = new QPushButton(horizontalLayoutWidget);
        Subtract->setObjectName(QStringLiteral("Subtract"));
        Subtract->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Subtract, 2, 6, 1, 1);

        pushButton_13 = new QPushButton(horizontalLayoutWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(pushButton_13, 5, 0, 1, 1);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        Equal = new QPushButton(horizontalLayoutWidget);
        Equal->setObjectName(QStringLiteral("Equal"));
        Equal->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Equal, 5, 6, 1, 1);

        Num_0 = new QPushButton(horizontalLayoutWidget);
        Num_0->setObjectName(QStringLiteral("Num_0"));
        Num_0->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Num_0, 5, 4, 1, 1);

        Plus = new QPushButton(horizontalLayoutWidget);
        Plus->setObjectName(QStringLiteral("Plus"));
        Plus->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Plus, 3, 6, 1, 1);

        Num_6 = new QPushButton(horizontalLayoutWidget);
        Num_6->setObjectName(QStringLiteral("Num_6"));
        Num_6->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Num_6, 2, 5, 1, 1);

        Num_7 = new QPushButton(horizontalLayoutWidget);
        Num_7->setObjectName(QStringLiteral("Num_7"));
        Num_7->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Num_7, 1, 3, 1, 1);

        Num_8 = new QPushButton(horizontalLayoutWidget);
        Num_8->setObjectName(QStringLiteral("Num_8"));
        Num_8->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Num_8, 1, 4, 1, 1);

        Num_1 = new QPushButton(horizontalLayoutWidget);
        Num_1->setObjectName(QStringLiteral("Num_1"));
        Num_1->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Num_1, 3, 3, 1, 1);

        Num_3 = new QPushButton(horizontalLayoutWidget);
        Num_3->setObjectName(QStringLiteral("Num_3"));
        Num_3->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Num_3, 3, 5, 1, 1);

        Num_4 = new QPushButton(horizontalLayoutWidget);
        Num_4->setObjectName(QStringLiteral("Num_4"));
        Num_4->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Num_4, 2, 3, 1, 1);

        Num_5 = new QPushButton(horizontalLayoutWidget);
        Num_5->setObjectName(QStringLiteral("Num_5"));
        Num_5->setAutoFillBackground(false);
        Num_5->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(Num_5, 2, 4, 1, 1);

        right_bracket = new QPushButton(horizontalLayoutWidget);
        right_bracket->setObjectName(QStringLiteral("right_bracket"));
        right_bracket->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(right_bracket, 5, 3, 1, 1);

        D = new QPushButton(horizontalLayoutWidget);
        D->setObjectName(QStringLiteral("D"));
        D->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(D, 3, 2, 1, 1);

        B = new QPushButton(horizontalLayoutWidget);
        B->setObjectName(QStringLiteral("B"));
        B->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft YaHei UI Light\";"));

        gridLayout->addWidget(B, 1, 2, 1, 1);

        Num_Point = new QPushButton(horizontalLayoutWidget);
        Num_Point->setObjectName(QStringLiteral("Num_Point"));

        gridLayout->addWidget(Num_Point, 5, 5, 1, 1);


        verticalLayout_8->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout_8);

        line_3 = new QFrame(horizontalLayoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        varList = new QTreeView(horizontalLayoutWidget);
        varList->setObjectName(QStringLiteral("varList"));

        verticalLayout_4->addWidget(varList);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        findName = new QLineEdit(horizontalLayoutWidget);
        findName->setObjectName(QStringLiteral("findName"));

        horizontalLayout_6->addWidget(findName);

        find = new QPushButton(horizontalLayoutWidget);
        find->setObjectName(QStringLiteral("find"));
        find->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        horizontalLayout_6->addWidget(find);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        addVariable = new QPushButton(horizontalLayoutWidget);
        addVariable->setObjectName(QStringLiteral("addVariable"));
        addVariable->setMaximumSize(QSize(100, 16777215));
        addVariable->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        gridLayout_3->addWidget(addVariable, 0, 0, 1, 1);

        deleteVariable = new QPushButton(horizontalLayoutWidget);
        deleteVariable->setObjectName(QStringLiteral("deleteVariable"));
        deleteVariable->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        gridLayout_3->addWidget(deleteVariable, 1, 0, 1, 1);

        editVariable = new QPushButton(horizontalLayoutWidget);
        editVariable->setObjectName(QStringLiteral("editVariable"));
        editVariable->setMaximumSize(QSize(100, 16777215));
        editVariable->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        gridLayout_3->addWidget(editVariable, 0, 1, 1, 1);

        pushButton_25 = new QPushButton(horizontalLayoutWidget);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        gridLayout_3->addWidget(pushButton_25, 1, 1, 1, 1);

        copy = new QPushButton(horizontalLayoutWidget);
        copy->setObjectName(QStringLiteral("copy"));
        copy->setMaximumSize(QSize(100, 16777215));
        copy->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        gridLayout_3->addWidget(copy, 0, 2, 1, 1);

        paste = new QPushButton(horizontalLayoutWidget);
        paste->setObjectName(QStringLiteral("paste"));
        paste->setMaximumSize(QSize(100, 16777215));
        paste->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        gridLayout_3->addWidget(paste, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);


        verticalLayout_4->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_4);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        horizontalLayout_4->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        line_5 = new QFrame(horizontalLayoutWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_5);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 18pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        verticalLayout_10->addWidget(label_3, 0, Qt::AlignHCenter);

        History = new QListView(horizontalLayoutWidget);
        History->setObjectName(QStringLiteral("History"));
        History->setModelColumn(0);

        verticalLayout_10->addWidget(History);


        horizontalLayout_3->addLayout(verticalLayout_10);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1501, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(readFile);
        menu->addAction(saveFile);
        menu->addAction(saveAsFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\237\251\351\230\265\350\256\241\347\256\227\345\231\250", Q_NULLPTR));
        readFile->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        saveFile->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        saveAsFile->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213\347\237\251\351\230\265", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\347\237\251 \351\230\265 \350\256\241 \347\256\227 \345\231\250 v3.0 alpha", Q_NULLPTR));
        LRef->setText(QApplication::translate("MainWindow", "LRef", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        In->setText(QApplication::translate("MainWindow", "In", Q_NULLPTR));
        MRef->setText(QApplication::translate("MainWindow", "MRef", Q_NULLPTR));
        Det->setText(QApplication::translate("MainWindow", "Det", Q_NULLPTR));
        Num_2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        Nor->setText(QApplication::translate("MainWindow", "Nor", Q_NULLPTR));
        C->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        pushButton_34->setText(QApplication::translate("MainWindow", "CE", Q_NULLPTR));
        BackSpace->setText(QApplication::translate("MainWindow", "<-", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        BackSpace->setShortcut(QApplication::translate("MainWindow", "Backspace", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        Clear->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        Divide->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Divide->setShortcut(QApplication::translate("MainWindow", "/", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        pushButton_32->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        left_bracket->setText(QApplication::translate("MainWindow", "(", Q_NULLPTR));
        Inv->setText(QApplication::translate("MainWindow", "Inv", Q_NULLPTR));
        Multiply->setText(QApplication::translate("MainWindow", "*", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Multiply->setShortcut(QApplication::translate("MainWindow", "*", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        Num_9->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        A->setText(QApplication::translate("MainWindow", "A", Q_NULLPTR));
        Subtract->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        Equal->setText(QApplication::translate("MainWindow", "=", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        Equal->setShortcut(QApplication::translate("MainWindow", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        Num_0->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        Plus->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        Num_6->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        Num_7->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        Num_8->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        Num_1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        Num_3->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        Num_4->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        Num_5->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        right_bracket->setText(QApplication::translate("MainWindow", ")", Q_NULLPTR));
        D->setText(QApplication::translate("MainWindow", "D", Q_NULLPTR));
        B->setText(QApplication::translate("MainWindow", "B", Q_NULLPTR));
        Num_Point->setText(QApplication::translate("MainWindow", ".", Q_NULLPTR));
        find->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276", Q_NULLPTR));
        addVariable->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\217\230\351\207\217", Q_NULLPTR));
        deleteVariable->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\217\230\351\207\217", Q_NULLPTR));
        editVariable->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\345\217\230\351\207\217", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("MainWindow", "Nooooo", Q_NULLPTR));
        copy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
        paste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
