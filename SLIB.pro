TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Exception.cpp \
    Object.cpp

HEADERS += \
    Exception.h \
    Object.h \
    SmartPointer.hpp \
    List.hpp \
    SeqList.hpp \
    DynamicList.hpp \
    StaticList.hpp \
    Array.hpp \
    StaticArray.hpp \
    DynamicArray.hpp \
    LinkList.hpp
