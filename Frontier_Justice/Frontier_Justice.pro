TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    frontier_justice.cpp \
    FJ_Engine/Render_Engine/shader.cpp \
    FJ_Engine/Render_Engine/camera.cpp \
    FJ_Engine/Render_Engine/mesh.cpp \
    FJ_Engine/Render_Engine/texture.cpp \
    FJ_Engine/Render_Engine/window.cpp \
    FJ_Engine/Render_Engine/renderer.cpp \
    FJ_Engine/engine.cpp \
    FJ_Engine/Managers/input_manager.cpp \
    FJ_Engine/Managers/object_manager.cpp \
    FJ_Engine/Managers/mesh_manager.cpp \
    FJ_Engine/Managers/texture_manager.cpp \
    FJ_Engine/game_scene.cpp

HEADERS += \
    frontier_justice.h \
    FJ_Engine/Render_Engine/shader.h \
    FJ_Engine/Render_Engine/camera.h \
    FJ_Engine/Render_Engine/mesh.h \
    FJ_Engine/Render_Engine/texture.h \
    FJ_Engine/Render_Engine/window.h \
    FJ_Engine/Render_Engine/renderer.h \
    FJ_Engine/engine.h \
    FJ_Engine/Managers/input_manager.h \
    FJ_Engine/math_util.h \
    FJ_Engine/game_object.h \
    FJ_Engine/game_scene.h \
    FJ_Engine/Managers/object_manager.h \
    FJ_Engine/Managers/mesh_manager.h \
    FJ_Engine/Managers/texture_manager.h

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
    ../notes \
    FJ_Engine/Render_Engine/shaders/light_frag.glsl \
    FJ_Engine/Render_Engine/shaders/light_vert.glsl \
    FJ_Engine/Render_Engine/shaders/flat_tex_frag.glsl \
    FJ_Engine/Render_Engine/shaders/flat_tex_vert.glsl \
    FJ_Engine/Render_Engine/shaders/light_fragV.glsl \
    FJ_Engine/Render_Engine/shaders/light_vertV.glsl

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lSOIL

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libSOIL.a

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lassimp

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libassimp.a
