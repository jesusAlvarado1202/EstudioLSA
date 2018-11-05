#-------------------------------------------------
#
# Project created by QtCreator 2018-01-08T18:33:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = LSAstudio
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    treeitem.cpp \
    treemodel.cpp \
    player.cpp \
    qcustomplot.cpp \
    cvprocess.cpp \
    tablemodel.cpp \
    data.cpp \
    videoposition.cpp \
    findEyeCenter.cpp \
    findEyeCorner.cpp \
    helpers.cpp

HEADERS  += mainwindow.h \
    treeitem.h \
    treemodel.h \
    player.h \
    qcustomplot.h \
    cvprocess.h \
    tablemodel.h \
    data.h \
    videoposition.h \
    constants.h \
    findEyeCenter.h \
    findEyeCorner.h \
    helpers.h

FORMS    += mainwindow.ui \
    videoposition.ui

# Opencv Library
INCLUDEPATH += "/usr/local/include/opencv2"
LIBS += `pkg-config --cflags --libs opencv`

DISTFILES += \
    default.txt \
    data/lbf.model \
    data/res10_300x300_ssd_iter_140000.caffemodel \
    data/default.txt \
    data/deploy.prototxt
