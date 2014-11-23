#-------------------------------------------------
#
# Project created by QtCreator 2014-11-17T23:13:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    character.cpp \
    scene/scene.cpp \
    scene/initscene.cpp \
    qneed.cpp \
    scene/logoscene.cpp \
    scene/choicescene.cpp \
    scene/ingamescene.cpp \
    scene/endgamescene.cpp \
    unit.cpp \
    map.cpp

HEADERS  += mainwindow.h \
    character.h \
    Types.h \
    scene/scene.h \
    scene/initscene.h \
    qneed.h \
    scene/logoscene.h \
    scene/choicescene.h \
    scene/ingamescene.h \
    scene/endgamescene.h \
    unit.h \
    map.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    images/logo/logo_background.png \
    images/logo/logo.png \
    images/init/start2button.png \
    images/init/init_button_play4.png \
    images/init/init_button_play3.png \
    images/init/init_button_play2.png \
    images/init/init_button_play1.png \
    images/init/init_button_play.png \
    images/init/init_button_creator3.png \
    images/init/init_button_creator2.png \
    images/init/init_button_creator1.png \
    images/init/init_button_creator.png \
    images/init/init_background2.png \
    images/init/init_background1.png \
    images/init/init_background.png \
    images/ingame/ingame_background.png \
    images/ingame/map/map_soju.png \
    images/ingame/map/map_breakable.png \
    images/ingame/map/map_block.png \
    images/ingame/map/map_background.png \
    images/ingame/character/rich_postech.png \
    images/ingame/character/rich_kaist.png \
    images/ingame/character/liar_postech.png \
    images/ingame/character/liar_kaist.png \
    images/ingame/character/alchoholic_postech.png \
    images/ingame/character/alchoholic_kaist.png \
    images/choice/choice_map_clicked2.png \
    images/choice/choice_map_clicked1.png \
    images/choice/choice_map_clicked0.png \
    images/choice/choice_map2.png \
    images/choice/choice_map1.png \
    images/choice/choice_map0.png \
    images/choice/choice_character_clicked5.png \
    images/choice/choice_character_clicked4.png \
    images/choice/choice_character_clicked3.png \
    images/choice/choice_character_clicked2.png \
    images/choice/choice_character_clicked1.png \
    images/choice/choice_character_clicked0.png \
    images/choice/choice_character5.png \
    images/choice/choice_character4.png \
    images/choice/choice_character3.png \
    images/choice/choice_character2.png \
    images/choice/choice_character1.png \
    images/choice/choice_character0.png \
    images/choice/choice_button_go.png \
    images/choice/choice_background1.png \
    images/choice/choice_background.png
