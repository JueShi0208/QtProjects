QT       += core gui
CONFIG   += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
TARGET = svgaplayer

DEPENDPATH += .
INCLUDEPATH += .
INCLUDEPATH += ../include

#INCLUDEPATH += D:/Qt5.12.9/MyProjects/SVGAPlayer-Qt-master/3rd/zlib-1.2.11/include
#INCLUDEPATH += D:/Qt5.12.9/MyProjects/SVGAPlayer-Qt-master/3rd/protobuf-3.3.0/include


#LIBS += D:/Qt5.12.9/MyProjects/SVGAPlayer-Qt-master/3rd/zlib-1.2.11/lib/zlibstatic.lib
#LIBS += D:/Qt5.12.9/MyProjects/SVGAPlayer-Qt-master/3rd/protobuf-3.3.0/lib/libprotobuf.lib

INCLUDEPATH += ../3rd/zlib-1.2.11/include
INCLUDEPATH += ../3rd/protobuf-3.3.0/include


#LIBS += ../3rd/zlib-1.2.11/lib/zlibstatic.lib
#LIBS += ../3rd/protobuf-3.3.0/lib/libprotobuf.lib

CharacterSet = 1

DEFINES += BUILD_SVGA
DEFINES += UNICODE
DEFINES += _WINDOWS
DEFINES += WIN32

HEADERS += stable.h
HEADERS += zip/unzipex.h \
    jsoncpp/autolink.h \
    jsoncpp/config.h \
    jsoncpp/features.h \
    jsoncpp/forwards.h \
    jsoncpp/json.h \
    jsoncpp/json_batchallocator.h \
    jsoncpp/json_internalarray.hpp \
    jsoncpp/json_internalmap.hpp \
    jsoncpp/json_tool.h \
    jsoncpp/json_valueiterator.hpp \
    jsoncpp/reader.h \
    jsoncpp/value.h \
    jsoncpp/writer.h
SOURCES += zip/unzipex.cpp \
    jsoncpp/json_reader.cpp \
    jsoncpp/json_value.cpp \
    jsoncpp/json_writer.cpp

HEADERS += proto/svga.pb.h
SOURCES += proto/svga.pb.cc

HEADERS += svgaplayer.h
SOURCES += svgaplayer.cpp
HEADERS += svgaresource.h
SOURCES += svgaresource.cpp
HEADERS += svgavideoentity.h
SOURCES += svgavideoentity.cpp
HEADERS += svgavideospriteentity.h
SOURCES += svgavideospriteentity.cpp
HEADERS += svgavideospriteframeentity.h
SOURCES += svgavideospriteframeentity.cpp
HEADERS += svgapath.h
SOURCES += svgapath.cpp
HEADERS += svgagdicanvas.h
SOURCES += svgagdicanvas.cpp
