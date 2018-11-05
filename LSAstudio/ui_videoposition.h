/********************************************************************************
** Form generated from reading UI file 'videoposition.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOPOSITION_H
#define UI_VIDEOPOSITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VideoPosition
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_done;
    QPushButton *pushButton_cancel;
    QLabel *label;

    void setupUi(QDialog *VideoPosition)
    {
        if (VideoPosition->objectName().isEmpty())
            VideoPosition->setObjectName(QStringLiteral("VideoPosition"));
        VideoPosition->resize(208, 164);
        gridLayout = new QGridLayout(VideoPosition);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(VideoPosition);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_done = new QPushButton(groupBox);
        pushButton_done->setObjectName(QStringLiteral("pushButton_done"));

        gridLayout_2->addWidget(pushButton_done, 1, 1, 1, 1);

        pushButton_cancel = new QPushButton(groupBox);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        gridLayout_2->addWidget(pushButton_cancel, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        label = new QLabel(VideoPosition);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(VideoPosition);

        QMetaObject::connectSlotsByName(VideoPosition);
    } // setupUi

    void retranslateUi(QDialog *VideoPosition)
    {
        VideoPosition->setWindowTitle(QApplication::translate("VideoPosition", "Dialog", 0));
        groupBox->setTitle(QString());
        pushButton_done->setText(QApplication::translate("VideoPosition", "Done", 0));
        pushButton_cancel->setText(QApplication::translate("VideoPosition", "Cancel", 0));
        label->setText(QApplication::translate("VideoPosition", "Move videoplayer scroll bar to desired position", 0));
    } // retranslateUi

};

namespace Ui {
    class VideoPosition: public Ui_VideoPosition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOPOSITION_H
