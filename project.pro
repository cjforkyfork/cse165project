QT       += core gui\
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Button.cpp \
    Enemy.cpp \
    Enemy2.cpp \
    Enemy_2.cpp \
    Game.cpp \
    Health.cpp \
    MyRect.cpp \
    Player.cpp \
    Score.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Bullet.h \
    Button.h \
    Enemy.h \
    Enemy2.h \
    Game.h \
    Health.h \
    Player.h \
    Score.h \
    dialog.h \
    mainwindow.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    bg.jpg \
    bg.png \
    bgsound.mp3 \
    bomb.png \
    bullet.mp3 \
    bullet.png \
    enemy.png \
    oc.mp3 \
    player.png
