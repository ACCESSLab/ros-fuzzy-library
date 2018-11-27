#-------------------------------------------------
#
# Project created by QtCreator 2017-07-26T11:29:32
#
#-------------------------------------------------

QT       += core gui xml sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FLS_Library_Gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    inputdialog.cpp \
    outputdialog.cpp \
    ruledialog.cpp \
    inmfsdialog.cpp \
    outmfsdialog.cpp \
    addrulesdialog.cpp \
    intabledialog.cpp \
    outtabledialog.cpp \
    XMLReader.cpp \
    XMLWriter.cpp \
    MetaRecord.cpp

HEADERS  += mainwindow.h \
    inputdialog.h \
    outputdialog.h \
    ruledialog.h \
    inmfsdialog.h \
    outmfsdialog.h \
    addrulesdialog.h \
    intabledialog.h \
    outtabledialog.h \
    commondef.h \
    XMLReader.h \
    XMLWriter.h \
    MetaRecord.h

FORMS    += mainwindow.ui \
    inputdialog.ui \
    outputdialog.ui \
    ruledialog.ui \
    inmfsdialog.ui \
    outmfsdialog.ui \
    addrulesdialog.ui \
    intabledialog.ui \
    outtabledialog.ui
