QT       += gui

QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE    = app

SOURCES += \
    main.cpp \
    ArchiveView/MainWindow.cpp \
    ArchiveView/FileViewModel.cpp \
    ArchiverModel/ArchiveReader/ArchiveReader.cpp \
    ArchiverModel/ArchiveWriter/ArchiveWriter.cpp \
    ArchiverModel/FileManager/FileProperties/FileProperties.cpp \
    ArchiverModel/FileManager/FileManager.cpp \
    ArchiverModel/Header/HeaderReader/HeaderReader.cpp \
    ArchiverModel/Header/HeaderWriter/HeaderWriter.cpp \
    ArchiverModel/Header/Header.cpp \
    ArchiverModel/TarArchiver.cpp

HEADERS += \
    ArchiveView/MainWindow.hpp \
    ArchiveView/FileViewModel.hpp \
    ArchiverModel/ArchiveReader/ArchiveReader.hpp \
    ArchiverModel/ArchiveReader/ArchiveReaderException.hpp \
    ArchiverModel/ArchiveWriter/ArchiveWriter.hpp \
    ArchiverModel/FileManager/FileProperties/FileProperties.hpp \
    ArchiverModel/FileManager/FileManager.hpp \
    ArchiverModel/FileManager/FileManagerException.hpp \
    ArchiverModel/Header/HeaderReader/HeaderReader.hpp \
    ArchiverModel/Header/HeaderReader/HeaderReaderException.hpp \
    ArchiverModel/Header/HeaderWriter/HeaderWriter.hpp \
    ArchiverModel/Header/Header.hpp \
    ArchiverModel/TarArchiver.hpp


RESOURCES += archiver.qrc


LIBS += -lboost_filesystem \
        -lboost_system
