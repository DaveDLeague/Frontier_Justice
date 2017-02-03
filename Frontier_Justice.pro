TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include(shaders/shaders.pri)

SOURCES += main.cpp \
    frontier_justice.cpp \
    game_time.cpp \
    game_window.cpp \
    game.cpp \
    input_manager.cpp \
    render_utility.cpp \
    mesh_manager.cpp \
    shader.cpp

HEADERS += \
    frontier_justice.h \
    game_window.h \
    game_time.h \
    game.h \
    input_manager.h \
    game_math.h \
    render_utility.h \
    mesh_manager.h \
    shader.h

unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/ -lSDL2

INCLUDEPATH += $$PWD/../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../usr/lib/x86_64-linux-gnu

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/lib/x86_64-linux-gnu/libSDL2.a

mac: LIBS += -F$$PWD/../../Library/Frameworks/ -framework SDL2

INCLUDEPATH += $$PWD/../../Library/Frameworks
DEPENDPATH += $$PWD/../../Library/Frameworks

unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/ -lGLEW

INCLUDEPATH += $$PWD/../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../usr/lib/x86_64-linux-gnu

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../usr/lib/x86_64-linux-gnu/libGLEW.a

unix:!macx: LIBS += -L$$PWD/../../../../usr/lib/x86_64-linux-gnu/ -lGL

INCLUDEPATH += $$PWD/../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../usr/lib/x86_64-linux-gnu

DESTDIR = ../Frontier_Justice/builds
OBJECTS_DIR = ../Frontier_Justice/builds/.obj

