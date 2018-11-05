/********************************************************************************
** Form generated from reading UI file 'video_browser.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_BROWSER_H
#define UI_VIDEO_BROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QTreeView *treeView_video;
    QPushButton *pushButton_Stop;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_CurrentTime;
    QSlider *horizontalSlider_VideoProgress;
    QLabel *label_TotalTime;
    QPushButton *pushButton_Play;
    QLabel *label_Screen;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(728, 359);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 310, 681, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        treeView_video = new QTreeView(Dialog);
        treeView_video->setObjectName(QStringLiteral("treeView_video"));
        treeView_video->setGeometry(QRect(10, 10, 371, 301));
        pushButton_Stop = new QPushButton(Dialog);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));
        pushButton_Stop->setGeometry(QRect(630, 220, 80, 22));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(390, 220, 152, 17));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_CurrentTime = new QLabel(layoutWidget);
        label_CurrentTime->setObjectName(QStringLiteral("label_CurrentTime"));

        horizontalLayout->addWidget(label_CurrentTime);

        horizontalSlider_VideoProgress = new QSlider(layoutWidget);
        horizontalSlider_VideoProgress->setObjectName(QStringLiteral("horizontalSlider_VideoProgress"));
        horizontalSlider_VideoProgress->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_VideoProgress);

        label_TotalTime = new QLabel(layoutWidget);
        label_TotalTime->setObjectName(QStringLiteral("label_TotalTime"));

        horizontalLayout->addWidget(label_TotalTime);

        pushButton_Play = new QPushButton(Dialog);
        pushButton_Play->setObjectName(QStringLiteral("pushButton_Play"));
        pushButton_Play->setGeometry(QRect(544, 220, 80, 22));
        label_Screen = new QLabel(Dialog);
        label_Screen->setObjectName(QStringLiteral("label_Screen"));
        label_Screen->setGeometry(QRect(390, 20, 321, 192));
        label_Screen->setStyleSheet(QStringLiteral("background-color: #000"));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        pushButton_Stop->setText(QApplication::translate("Dialog", "Stop", 0));
        label_CurrentTime->setText(QApplication::translate("Dialog", "0:00", 0));
        label_TotalTime->setText(QApplication::translate("Dialog", "0:00", 0));
        pushButton_Play->setText(QApplication::translate("Dialog", "Play", 0));
        label_Screen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_BROWSER_H
