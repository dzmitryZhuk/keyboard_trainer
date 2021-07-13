#ifndef CHANGETEXT_H
#define CHANGETEXT_H

#include "libs.h"
#include "mywindow.h"

namespace Ui {
class ChangeText;
}

class ChangeText : public MyWindow
{
    Q_OBJECT

public:
    explicit ChangeText(QWidget *parent = nullptr);
    ~ChangeText();

private:
    Ui::ChangeText *ui;
    QVector <MyButton*>buttons;
    void initButtons();
    void initTheme();
    void setLightTheme();
    void setDarkTheme();
private slots:
        void button1Released(); // назад
        void button2Released(); // применить
};

#endif // CHANGETEXT_H
