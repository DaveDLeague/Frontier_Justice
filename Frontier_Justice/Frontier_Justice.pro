TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    frontier_justice.cpp \
    FJ_Engine/fj_engine.cpp \
    FJ_Engine/Render_Engine/game_window.cpp \
    FJ_Engine/input_manager.cpp \
    FJ_Engine/object_manager.cpp \
    FJ_Engine/component_manager.cpp \
    FJ_Engine/scene_manager.cpp \
    FJ_Engine/Render_Engine/shader.cpp \
    FJ_Engine/Render_Engine/camera.cpp

HEADERS += \
    frontier_justice.h \
    FJ_Engine/fj_engine.h \
    FJ_Engine/Render_Engine/game_window.h \
    FJ_Engine/input_manager.h \
    FJ_Engine/object_manager.h \
    FJ_Engine/component_manager.h \
    FJ_Engine/scene_manager.h \
    FJ_Engine/Render_Engine/shader.h \
    FJ_Engine/fj_math.h \
    FJ_Engine/Render_Engine/camera.h

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lSDL2
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libSDL2.a
unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lGLEW
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libGLEW.a
unix:!macx: LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/ -lGL

INCLUDEPATH += $$PWD/../../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../../usr/lib/x86_64-linux-gnu
INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

DISTFILES += \
    FJ_Engine/Render_Engine/shaders/flat_vert.glsl \
    FJ_Engine/Render_Engine/shaders/flat_frag.glsl \
    FJ_Engine/Render_Engine/shaders/simple_light_vert.glsl \
    FJ_Engine/Render_Engine/shaders/simple_light_frag.glsl \
    ../notes
