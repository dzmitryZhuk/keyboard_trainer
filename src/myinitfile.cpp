#include "myinitfile.h"

MyInitFile::MyInitFile()
{
    this->setFileName(FILE_NAME);
    stream.setDevice(this);
    if(!this->open(QIODevice::ReadOnly))
    {
        this->close();
        this->open(QIODevice::ReadWrite);
        stdInit();
    }
    else
    {
        this->close();
        this->open(QIODevice::ReadWrite);
        stream >> widgetWidth >> widgetHeight >> theme;
    }
}

MyInitFile::~MyInitFile()
{
    this->close();
}

void MyInitFile::stdInit()
{
    stream << widgetWidth << widgetHeight;
    stream << theme;
}

void MyInitFile::setLightTheme()
{
    stream.device()->seek(0);
    theme = THEME_LIGHT;
    stream.skipRawData(4);  //  skip widget width and height (4 bytes)
    stream << theme;
}

void MyInitFile::setDarkTheme()
{
    stream.device()->seek(0);
    theme = THEME_DARK;
    stream.skipRawData(4);  //  skip widget width and height (4 bytes)
    stream << theme;        //  then write theme
}

qint8 MyInitFile::getTheme()
{
    stream.device()->seek(0);
    stream.skipRawData(4);  //  skip widget width and height (4 bytes)
    stream >> theme;        //  then read theme
    return theme;
}

QSize MyInitFile::getSizeOfMainWindow()
{
    stream.device()->seek(0);
    stream >> widgetWidth >> widgetHeight;
    QSize size;
    size.setWidth(widgetWidth);
    size.setHeight(widgetHeight);
    return size;
}

void MyInitFile::setSizeOfMainWindow(QSize size)
{
    widgetWidth = size.width();
    widgetHeight = size.height();
    stream.device()->seek(0);
    stream << widgetWidth << widgetHeight;
}

void MyInitFile::setSizeOfMainWindow(int w, int h)
{
    setSizeOfMainWindow(QSize(w,h));
}
