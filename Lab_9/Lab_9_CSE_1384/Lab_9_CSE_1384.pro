TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        library.cpp \
        main.cpp

DISTFILES += \
    books.txt

HEADERS += \
    library.h \
    node.h
