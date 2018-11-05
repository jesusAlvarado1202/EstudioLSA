/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QListWidget *listWidget_main;
    QStackedWidget *stackedWidget_main;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QTreeView *treeView_project;
    QTableView *tableView_project;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_open_project;
    QPushButton *pushButton_new_project;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_load;
    QWidget *page_2;
    QGridLayout *gridLayout_10;
    QListWidget *listWidget_class_rec;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_9;
    QPushButton *pushButton_add_rec;
    QPushButton *pushButton_clear_rec;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_classname_rec;
    QLabel *label_6;
    QPushButton *pushButton_load_rec;
    QPushButton *pushButton_start_rec;
    QProgressBar *progressBar_rec;
    QPushButton *pushButton_ready_rec;
    QPushButton *pushButton_save_rec;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_rec_item_selected;
    QListWidget *listWidget_rec;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_11;
    QPushButton *pushButton_remove_class;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_8;
    QTimeEdit *timeEdit_end_rec;
    QLabel *label_5;
    QPushButton *pushButton_set_start_rec;
    QPushButton *pushButton_set_end_rec;
    QTimeEdit *timeEdit_start_rec;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_4;
    QWidget *page_3;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_code;
    QGridLayout *gridLayout_6;
    QTimeEdit *timeEdit_start_code;
    QLabel *label_elapse_time;
    QPushButton *pushButton_set_start_code;
    QLabel *label;
    QPushButton *pushButton_set_end_code;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_code;
    QLabel *label_3;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButton;
    QProgressBar *progressBar_code;
    QTimeEdit *timeEdit_end_code;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QCustomPlot *barPlot;
    QScrollBar *horizontalScrollBar_plot;
    QWidget *tab_2;
    QGridLayout *gridLayout_7;
    QTableView *tableView_code;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *spinBox_filter;
    QPushButton *pushButton_export;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_slider;
    QPushButton *pushButton_minus;
    QLabel *label_CurrentTime;
    QSlider *horizontalSlider;
    QLabel *label_TotalTime;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_Play;
    QLabel *label_Screen;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1231, 599);
        MainWindow->setStyleSheet(QLatin1String("\n"
"background: rgba(31,31,31, 255);\n"
"\n"
"\n"
"font-weight: bold;\n"
"font-size:12px;\n"
"color: rgb(245, 245, 245);\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listWidget_main = new QListWidget(centralWidget);
        new QListWidgetItem(listWidget_main);
        new QListWidgetItem(listWidget_main);
        new QListWidgetItem(listWidget_main);
        new QListWidgetItem(listWidget_main);
        listWidget_main->setObjectName(QStringLiteral("listWidget_main"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget_main->sizePolicy().hasHeightForWidth());
        listWidget_main->setSizePolicy(sizePolicy);
        listWidget_main->setMaximumSize(QSize(100, 16777215));
        listWidget_main->setStyleSheet(QLatin1String("QListWidget \n"
"{ \n"
"background-color: rgb(51,51,51);\n"
"border: none;\n"
"font-family: Dosis;\n"
"font-weight: bold;\n"
"font-size:15px;\n"
"}\n"
"\n"
""));
        listWidget_main->setProperty("isWrapping", QVariant(true));
        listWidget_main->setSpacing(2);
        listWidget_main->setWordWrap(true);

        gridLayout_2->addWidget(listWidget_main, 0, 0, 1, 1);

        stackedWidget_main = new QStackedWidget(centralWidget);
        stackedWidget_main->setObjectName(QStringLiteral("stackedWidget_main"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        treeView_project = new QTreeView(page);
        treeView_project->setObjectName(QStringLiteral("treeView_project"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeView_project->sizePolicy().hasHeightForWidth());
        treeView_project->setSizePolicy(sizePolicy1);
        treeView_project->setStyleSheet(QStringLiteral("background-color: rgb(51,51,51);"));

        gridLayout_3->addWidget(treeView_project, 0, 0, 1, 1);

        tableView_project = new QTableView(page);
        tableView_project->setObjectName(QStringLiteral("tableView_project"));
        tableView_project->setStyleSheet(QStringLiteral("background-color: rgb(51,51,51);"));

        gridLayout_3->addWidget(tableView_project, 0, 1, 3, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_open_project = new QPushButton(page);
        pushButton_open_project->setObjectName(QStringLiteral("pushButton_open_project"));
        pushButton_open_project->setStyleSheet(QLatin1String("background-color: rgb(51,51,51);\n"
"\n"
""));

        horizontalLayout_3->addWidget(pushButton_open_project);

        pushButton_new_project = new QPushButton(page);
        pushButton_new_project->setObjectName(QStringLiteral("pushButton_new_project"));
        pushButton_new_project->setStyleSheet(QLatin1String("background-color: rgb(51,51,51);\n"
""));

        horizontalLayout_3->addWidget(pushButton_new_project);


        gridLayout_3->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_load = new QPushButton(page);
        pushButton_load->setObjectName(QStringLiteral("pushButton_load"));
        pushButton_load->setStyleSheet(QLatin1String("background-color: rgb(51,51,51);\n"
""));

        horizontalLayout_2->addWidget(pushButton_load);


        gridLayout_3->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        stackedWidget_main->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_10 = new QGridLayout(page_2);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        listWidget_class_rec = new QListWidget(page_2);
        listWidget_class_rec->setObjectName(QStringLiteral("listWidget_class_rec"));
        listWidget_class_rec->setMaximumSize(QSize(140, 16777215));

        gridLayout_10->addWidget(listWidget_class_rec, 0, 1, 3, 1);

        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 65));
        gridLayout_9 = new QGridLayout(groupBox_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        pushButton_add_rec = new QPushButton(groupBox_2);
        pushButton_add_rec->setObjectName(QStringLiteral("pushButton_add_rec"));

        gridLayout_9->addWidget(pushButton_add_rec, 0, 8, 1, 1);

        pushButton_clear_rec = new QPushButton(groupBox_2);
        pushButton_clear_rec->setObjectName(QStringLiteral("pushButton_clear_rec"));

        gridLayout_9->addWidget(pushButton_clear_rec, 0, 9, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_6, 0, 2, 1, 1);

        lineEdit_classname_rec = new QLineEdit(groupBox_2);
        lineEdit_classname_rec->setObjectName(QStringLiteral("lineEdit_classname_rec"));

        gridLayout_9->addWidget(lineEdit_classname_rec, 0, 7, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_9->addWidget(label_6, 0, 6, 1, 1);

        pushButton_load_rec = new QPushButton(groupBox_2);
        pushButton_load_rec->setObjectName(QStringLiteral("pushButton_load_rec"));

        gridLayout_9->addWidget(pushButton_load_rec, 0, 12, 1, 1);

        pushButton_start_rec = new QPushButton(groupBox_2);
        pushButton_start_rec->setObjectName(QStringLiteral("pushButton_start_rec"));

        gridLayout_9->addWidget(pushButton_start_rec, 0, 0, 1, 1);

        progressBar_rec = new QProgressBar(groupBox_2);
        progressBar_rec->setObjectName(QStringLiteral("progressBar_rec"));
        progressBar_rec->setValue(24);

        gridLayout_9->addWidget(progressBar_rec, 0, 1, 1, 1);

        pushButton_ready_rec = new QPushButton(groupBox_2);
        pushButton_ready_rec->setObjectName(QStringLiteral("pushButton_ready_rec"));

        gridLayout_9->addWidget(pushButton_ready_rec, 0, 10, 1, 1);

        pushButton_save_rec = new QPushButton(groupBox_2);
        pushButton_save_rec->setObjectName(QStringLiteral("pushButton_save_rec"));

        gridLayout_9->addWidget(pushButton_save_rec, 0, 11, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_9->addWidget(label_2, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 0, 4, 1, 1);

        label_rec_item_selected = new QLabel(groupBox_2);
        label_rec_item_selected->setObjectName(QStringLiteral("label_rec_item_selected"));

        gridLayout_9->addWidget(label_rec_item_selected, 0, 5, 1, 1);


        gridLayout_10->addWidget(groupBox_2, 1, 0, 1, 1);

        listWidget_rec = new QListWidget(page_2);
        listWidget_rec->setObjectName(QStringLiteral("listWidget_rec"));

        gridLayout_10->addWidget(listWidget_rec, 2, 0, 2, 1);

        groupBox_3 = new QGroupBox(page_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(140, 65));
        gridLayout_11 = new QGridLayout(groupBox_3);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        pushButton_remove_class = new QPushButton(groupBox_3);
        pushButton_remove_class->setObjectName(QStringLiteral("pushButton_remove_class"));

        gridLayout_11->addWidget(pushButton_remove_class, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_7, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_3, 3, 1, 1, 1);

        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 65));
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        timeEdit_end_rec = new QTimeEdit(groupBox);
        timeEdit_end_rec->setObjectName(QStringLiteral("timeEdit_end_rec"));

        gridLayout_8->addWidget(timeEdit_end_rec, 0, 6, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_8->addWidget(label_5, 0, 5, 1, 1);

        pushButton_set_start_rec = new QPushButton(groupBox);
        pushButton_set_start_rec->setObjectName(QStringLiteral("pushButton_set_start_rec"));

        gridLayout_8->addWidget(pushButton_set_start_rec, 0, 0, 1, 1);

        pushButton_set_end_rec = new QPushButton(groupBox);
        pushButton_set_end_rec->setObjectName(QStringLiteral("pushButton_set_end_rec"));

        gridLayout_8->addWidget(pushButton_set_end_rec, 0, 4, 1, 1);

        timeEdit_start_rec = new QTimeEdit(groupBox);
        timeEdit_start_rec->setObjectName(QStringLiteral("timeEdit_start_rec"));

        gridLayout_8->addWidget(timeEdit_start_rec, 0, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_8, 0, 3, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_8->addWidget(label_4, 0, 1, 1, 1);


        gridLayout_10->addWidget(groupBox, 0, 0, 1, 1);

        stackedWidget_main->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_4 = new QGridLayout(page_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_code = new QGroupBox(page_3);
        groupBox_code->setObjectName(QStringLiteral("groupBox_code"));
        groupBox_code->setMinimumSize(QSize(0, 80));
        gridLayout_6 = new QGridLayout(groupBox_code);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        timeEdit_start_code = new QTimeEdit(groupBox_code);
        timeEdit_start_code->setObjectName(QStringLiteral("timeEdit_start_code"));

        gridLayout_6->addWidget(timeEdit_start_code, 0, 2, 1, 1);

        label_elapse_time = new QLabel(groupBox_code);
        label_elapse_time->setObjectName(QStringLiteral("label_elapse_time"));
        label_elapse_time->setMinimumSize(QSize(80, 0));

        gridLayout_6->addWidget(label_elapse_time, 0, 12, 1, 1);

        pushButton_set_start_code = new QPushButton(groupBox_code);
        pushButton_set_start_code->setObjectName(QStringLiteral("pushButton_set_start_code"));

        gridLayout_6->addWidget(pushButton_set_start_code, 0, 0, 1, 1);

        label = new QLabel(groupBox_code);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_6->addWidget(label, 0, 1, 1, 1);

        pushButton_set_end_code = new QPushButton(groupBox_code);
        pushButton_set_end_code->setObjectName(QStringLiteral("pushButton_set_end_code"));

        gridLayout_6->addWidget(pushButton_set_end_code, 0, 4, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_9, 0, 3, 1, 1);

        pushButton_code = new QPushButton(groupBox_code);
        pushButton_code->setObjectName(QStringLiteral("pushButton_code"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_code->sizePolicy().hasHeightForWidth());
        pushButton_code->setSizePolicy(sizePolicy2);
        pushButton_code->setCheckable(true);

        gridLayout_6->addWidget(pushButton_code, 0, 9, 1, 1);

        label_3 = new QLabel(groupBox_code);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_6->addWidget(label_3, 0, 11, 1, 1);

        label_7 = new QLabel(groupBox_code);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 0, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 0, 7, 1, 1);

        radioButton = new QRadioButton(groupBox_code);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout_6->addWidget(radioButton, 0, 13, 1, 1);

        progressBar_code = new QProgressBar(groupBox_code);
        progressBar_code->setObjectName(QStringLiteral("progressBar_code"));
        progressBar_code->setValue(0);

        gridLayout_6->addWidget(progressBar_code, 0, 10, 1, 1);

        timeEdit_end_code = new QTimeEdit(groupBox_code);
        timeEdit_end_code->setObjectName(QStringLiteral("timeEdit_end_code"));

        gridLayout_6->addWidget(timeEdit_end_code, 0, 6, 1, 1);


        gridLayout_4->addWidget(groupBox_code, 0, 0, 1, 1);

        tabWidget = new QTabWidget(page_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 80));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        barPlot = new QCustomPlot(tab);
        barPlot->setObjectName(QStringLiteral("barPlot"));

        gridLayout_5->addWidget(barPlot, 0, 0, 1, 1);

        horizontalScrollBar_plot = new QScrollBar(tab);
        horizontalScrollBar_plot->setObjectName(QStringLiteral("horizontalScrollBar_plot"));
        horizontalScrollBar_plot->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(horizontalScrollBar_plot, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_7 = new QGridLayout(tab_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        tableView_code = new QTableView(tab_2);
        tableView_code->setObjectName(QStringLiteral("tableView_code"));

        gridLayout_7->addWidget(tableView_code, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_4->addWidget(tabWidget, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        spinBox_filter = new QSpinBox(page_3);
        spinBox_filter->setObjectName(QStringLiteral("spinBox_filter"));
        spinBox_filter->setMinimumSize(QSize(80, 0));

        horizontalLayout_5->addWidget(spinBox_filter);

        pushButton_export = new QPushButton(page_3);
        pushButton_export->setObjectName(QStringLiteral("pushButton_export"));
        pushButton_export->setMinimumSize(QSize(0, 22));

        horizontalLayout_5->addWidget(pushButton_export);


        gridLayout_4->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        stackedWidget_main->addWidget(page_3);

        gridLayout_2->addWidget(stackedWidget_main, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1231, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy3);
        dockWidget->setMinimumSize(QSize(324, 83));
        dockWidget->setFloating(true);
        dockWidget->setFeatures(QDockWidget::DockWidgetFloatable);
        dockWidget->setAllowedAreas(Qt::NoDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_slider = new QHBoxLayout();
        horizontalLayout_slider->setSpacing(6);
        horizontalLayout_slider->setObjectName(QStringLiteral("horizontalLayout_slider"));
        pushButton_minus = new QPushButton(dockWidgetContents);
        pushButton_minus->setObjectName(QStringLiteral("pushButton_minus"));
        pushButton_minus->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_slider->addWidget(pushButton_minus);

        label_CurrentTime = new QLabel(dockWidgetContents);
        label_CurrentTime->setObjectName(QStringLiteral("label_CurrentTime"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_CurrentTime->sizePolicy().hasHeightForWidth());
        label_CurrentTime->setSizePolicy(sizePolicy4);
        label_CurrentTime->setMaximumSize(QSize(16777215, 15));

        horizontalLayout_slider->addWidget(label_CurrentTime);

        horizontalSlider = new QSlider(dockWidgetContents);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(16777215, 15));
        horizontalSlider->setStyleSheet(QStringLiteral("background-color: rgb(51,51,51);"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_slider->addWidget(horizontalSlider);

        label_TotalTime = new QLabel(dockWidgetContents);
        label_TotalTime->setObjectName(QStringLiteral("label_TotalTime"));
        sizePolicy4.setHeightForWidth(label_TotalTime->sizePolicy().hasHeightForWidth());
        label_TotalTime->setSizePolicy(sizePolicy4);
        label_TotalTime->setMaximumSize(QSize(16777215, 15));

        horizontalLayout_slider->addWidget(label_TotalTime);


        horizontalLayout->addLayout(horizontalLayout_slider);

        pushButton_plus = new QPushButton(dockWidgetContents);
        pushButton_plus->setObjectName(QStringLiteral("pushButton_plus"));
        pushButton_plus->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(pushButton_plus);

        pushButton_Play = new QPushButton(dockWidgetContents);
        pushButton_Play->setObjectName(QStringLiteral("pushButton_Play"));
        pushButton_Play->setStyleSheet(QLatin1String("background-color: rgb(51,51,51);\n"
"\n"
"\n"
""));

        horizontalLayout->addWidget(pushButton_Play);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        label_Screen = new QLabel(dockWidgetContents);
        label_Screen->setObjectName(QStringLiteral("label_Screen"));
        label_Screen->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_Screen->sizePolicy().hasHeightForWidth());
        label_Screen->setSizePolicy(sizePolicy5);
        label_Screen->setMinimumSize(QSize(0, 0));
        label_Screen->setStyleSheet(QStringLiteral("background-color: #000"));

        gridLayout->addWidget(label_Screen, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget);

        retranslateUi(MainWindow);

        listWidget_main->setCurrentRow(0);
        stackedWidget_main->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));

        const bool __sortingEnabled = listWidget_main->isSortingEnabled();
        listWidget_main->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_main->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "HOME", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_main->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "VISUAL PROCESS", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_main->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "CODING", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_main->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "ANALYSIS", 0));
        listWidget_main->setSortingEnabled(__sortingEnabled);

        pushButton_open_project->setText(QApplication::translate("MainWindow", "Open", 0));
        pushButton_new_project->setText(QApplication::translate("MainWindow", "New", 0));
        pushButton_load->setText(QApplication::translate("MainWindow", "Load ", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Recognition", 0));
        pushButton_add_rec->setText(QApplication::translate("MainWindow", "Add", 0));
        pushButton_clear_rec->setText(QApplication::translate("MainWindow", "Clear All", 0));
        label_6->setText(QApplication::translate("MainWindow", "Class Name", 0));
        pushButton_load_rec->setText(QApplication::translate("MainWindow", "Load", 0));
        pushButton_start_rec->setText(QApplication::translate("MainWindow", "start", 0));
        pushButton_ready_rec->setText(QApplication::translate("MainWindow", "Ready", 0));
        pushButton_save_rec->setText(QApplication::translate("MainWindow", "save", 0));
        label_2->setText(QApplication::translate("MainWindow", "selected Items:", 0));
        label_rec_item_selected->setText(QApplication::translate("MainWindow", "0", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Class", 0));
        pushButton_remove_class->setText(QApplication::translate("MainWindow", "Remove", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Video sample", 0));
        timeEdit_end_rec->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", 0));
        label_5->setText(QApplication::translate("MainWindow", "End", 0));
        pushButton_set_start_rec->setText(QApplication::translate("MainWindow", "set", 0));
        pushButton_set_end_rec->setText(QApplication::translate("MainWindow", "set", 0));
        timeEdit_start_rec->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", 0));
        label_4->setText(QApplication::translate("MainWindow", "Start", 0));
        groupBox_code->setTitle(QApplication::translate("MainWindow", "Code", 0));
        timeEdit_start_code->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", 0));
        label_elapse_time->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton_set_start_code->setText(QApplication::translate("MainWindow", "set", 0));
        label->setText(QApplication::translate("MainWindow", "Start at", 0));
        pushButton_set_end_code->setText(QApplication::translate("MainWindow", "set", 0));
        pushButton_code->setText(QApplication::translate("MainWindow", "Start", 0));
        label_3->setText(QApplication::translate("MainWindow", "Elapsed time:", 0));
        label_7->setText(QApplication::translate("MainWindow", "End at", 0));
        radioButton->setText(QApplication::translate("MainWindow", "Show Points", 0));
        timeEdit_end_code->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Plot", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Table", 0));
        pushButton_export->setText(QApplication::translate("MainWindow", "Export", 0));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "VIDEO PLAYER", 0));
        pushButton_minus->setText(QApplication::translate("MainWindow", "-", 0));
        label_CurrentTime->setText(QApplication::translate("MainWindow", "0:00", 0));
        label_TotalTime->setText(QApplication::translate("MainWindow", "0:00", 0));
        pushButton_plus->setText(QApplication::translate("MainWindow", "+", 0));
        pushButton_Play->setText(QApplication::translate("MainWindow", "Play", 0));
        label_Screen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
