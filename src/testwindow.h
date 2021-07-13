#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include "libs.h"
#include <mainwindow.h>
#include "mywindow.h"

namespace Ui {
class TestWindow;
}

class TestWindow : public MyWindow
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = nullptr);
    void restart();
    void setText(QString text);
    ~TestWindow();

private:
    Ui::TestWindow *ui;
    void initButtons();
    QVector<MyButton*>buttons;
    void setLightTheme();
    void setDarkTheme();
    void initTheme();
    void initText();
    void keyPressEvent(QKeyEvent *event);
    void finish();
    void initVars();               // инициализация переменных
    int convertToUnicode(int key); // для строчных букв
    //////////////////////////////////////////////
    long long clicksNumber, mistakes;
    QString startText, curText;
    int speed;
    int timeMS;                    // полная длительность печати в миллисекундах

private slots:
        void button1Released();    // назад
        void button2Released();    // изменить текст
        void button3Released();    // начать сначала
};

#endif // TESTWINDOW_H
