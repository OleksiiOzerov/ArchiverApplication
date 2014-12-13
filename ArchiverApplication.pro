QT       += gui

QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE    = app

SOURCES += \
    main.cpp \
    ArchiveView/MainWindow.cpp \
    ArchiveView/FileViewModel.cpp

HEADERS += \
    ArchiveView/MainWindow.hpp \
    ArchiveView/FileViewModel.hpp
