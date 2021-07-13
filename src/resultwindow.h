#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include "libs.h"
#include "mywindow.h"

namespace Ui {
class ResultWindow;
}

class ResultWindow : public MyWindow
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent, int time, int speed, long long mistakes);
    ~ResultWindow();

private:
    Ui::ResultWindow *ui;
    void initButtons();
    QVector<MyButton*>buttons;

private slots:
        void button1Released();    // назад
};

#endif // RESULTWINDOW_H
