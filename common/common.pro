TARGET = common
TEMPLATE = lib

CONFIG += staticlib \
          qdbus

SOURCES += \
        adapter.cpp \
        manager.cpp \
        dummy.cpp \
        observer.cpp

HEADERS += \
        adapter.h \
        manager.h \
        dummy.h \
        observer.h \
        types.h

OTHER_FILES +=
