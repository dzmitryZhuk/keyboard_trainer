#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{

public:
    MyButton(QWidget * parent);
    void setX(int x);
    void setY(int y);
    MyButton* createMyButton(QWidget* parent, QString text);
    void setCoords(int x, int y);
    void lightStyleSheet();
    void darkStyleSheet();
private:
    void initStyleSheet();
    void initSize();
    void initFont();
    const QString FONT_PATH = ":/font/res/font/font.ttf";
    int fontSize = 14;
};

#endif // MYBUTTON_H
