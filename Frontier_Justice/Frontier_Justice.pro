TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    maths_funcs.cpp \
    Shader.cpp \
    ResourceManager.cpp \
    Texture.cpp \


HEADERS += maths_funcs.h \
    Shader.h \
    ResourceManager.h \
    Texture.h \



DISTFILES += \
    phong_vs.glsl \
    phong_fs.glsl

INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include
INCLUDEPATH += $$PWD/../../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../../usr/lib/x86_64-linux-gnu
INCLUDEPATH += $$PWD/../../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../../usr/local/include

unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lSDL2
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libSDL2.a
unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lGLEW
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libGLEW.a
unix:!macx: LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/ -lGL
unix:!macx: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lSOIL
unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../usr/local/lib/libSOIL.a

DESTDIR=../build
OBJECTS_DIR=../build/.obj
MAKEFILE=../build/Makefile
