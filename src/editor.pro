QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Dialogs/createblockdialog.cpp \
    Dialogs/createcategorydialog.cpp \
    Dialogs/editcategorydialog.cpp \
    Components/block.cpp \
    Components/line.cpp \
    main.cpp \
    mainwindow.cpp \
    scene.cpp \
    storage.cpp

HEADERS += \
    Dialogs/createblockdialog.h \
    Dialogs/createcategorydialog.h \
    Dialogs/editcategorydialog.h \
    Components/block.h \
    Components/line.h \
    mainwindow.h \
    scene.h \
    storage.h

FORMS += \
    Dialogs/createblockdialog.ui \
    Dialogs/createcategorydialog.ui \
    Dialogs/editcategorydialog.ui \
    mainwindow.ui

OTHER_FILES += \
    Storage/categories.json \
    Storage/blocks.json

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/Resources.qrc \
    Storage/Storage.qrc
