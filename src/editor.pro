QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Components/io.cpp \
    Dialogs/createblockdialog.cpp \
    Dialogs/createcategorydialog.cpp \
    Dialogs/createiodialog.cpp \
    Dialogs/editcategorydialog.cpp \
    Components/block.cpp \
    Components/line.cpp \
    Dialogs/newdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    scene.cpp \
    storage.cpp \
    view.cpp

HEADERS += \
    Components/io.h \
    Dialogs/createblockdialog.h \
    Dialogs/createcategorydialog.h \
    Dialogs/createiodialog.h \
    Dialogs/editcategorydialog.h \
    Components/block.h \
    Components/line.h \
    Dialogs/newdialog.h \
    mainwindow.h \
    scene.h \
    storage.h \
    view.h

FORMS += \
    Dialogs/createblockdialog.ui \
    Dialogs/createcategorydialog.ui \
    Dialogs/createiodialog.ui \
    Dialogs/editcategorydialog.ui \
    Dialogs/newdialog.ui \
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
