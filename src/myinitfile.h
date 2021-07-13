#ifndef MYININTFILE_H
#define MYININTFILE_H

#include <QFile>
#include <QIODevice>
#include <QDataStream>
#include <QMessageBox>
#include <QString>
#include <QSize>

class MyInitFile : public QFile
{
//  structure of the configuration file
//
//  1-2 bytes - width of start widget
//  3-4 bytes - width of start widget
//  5 byte - current theme (0 - light, 1 - dark)
//
public:
    MyInitFile();
    ~MyInitFile();
    void setLightTheme();
    void setDarkTheme();
    qint8 getTheme();
    QSize getSizeOfMainWindow();
    void setSizeOfMainWindow(QSize size);
    void setSizeOfMainWindow(int w, int h);
    const qint8 THEME_LIGHT = 0, THEME_DARK = 1;
private:
    const QString FILE_NAME = "init.conf";
    //  default initialization of the configuration file
    void stdInit();
    QDataStream stream;
    qint16 widgetWidth = 500, widgetHeight = 650;  //  500 x 650 - default widget width and height
    qint8 theme = THEME_LIGHT;
};

#endif // MYININTFILE_H
