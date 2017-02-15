TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    frontier_justice.cpp \
    FJ_Engine/fj_engine.cpp \
    FJ_Engine/Render_Engine/game_window.cpp \
    FJ_Engine/input_manager.cpp

HEADERS += \
    frontier_justice.h \
    FJ_Engine/fj_engine.h \
    FJ_Engine/Render_Engine/game_window.h \
    FJ_Engine/input_manager.h

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lSDL2

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libSDL2.a

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lGLEW

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libGLEW.a

unix:!macx: LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/ -lGL

INCLUDEPATH += $$PWD/../../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../../usr/lib/x86_64-linux-gnu
