#include "mybutton.h"

MyButton::MyButton(QWidget * parent):QPushButton(parent)
{
    initStyleSheet();
    initSize();
    initFont();
}

void MyButton::setX(int x)
{
    setGeometry(x,y(),width(),height());
}

void MyButton::setY(int y)
{
    setGeometry(x(),y,width(),height());
}

MyButton* MyButton::createMyButton(QWidget *parent, QString text)
{
    MyButton* button = new MyButton(parent);
    button->setText(text);
    button->show();
    return button;
}

void MyButton::setCoords(int x, int y)
{
    setX(x);
    setY(y);
}

void MyButton::initStyleSheet()
{
    darkStyleSheet();
}

void MyButton::initSize()
{
    int initWidth = 200, initHeight = 40;
//    setGeometry(x(),y(),initWidth,initHeight);
    setFixedSize(initWidth,initHeight);
}

void MyButton::initFont()
{
    QFont* buttonFont = new QFont(FONT_PATH,fontSize,QFont::Medium,false);
    this->setFont(*buttonFont);

}

void MyButton::lightStyleSheet()
{
    this->setStyleSheet("QPushButton{"
                        "   color: black;"
                        "   background-color: white;"
                        "   border: 1px solid #828282;"
                        "   border-radius: 6px;"
                        "}"
                        ""
                        "QPushButton:hover{"
                        "   border: 1px solid #828282;"
                        "   background-color: #d5d5d5;"
                        "}"
                        ""
                        "QPushButton:hover:pressed{"
                        "   background-color: gray;"
                        "   color:white;"
                        "}");
}

void MyButton::darkStyleSheet()
{
    this->setStyleSheet("QPushButton{"
                        "   color: #52ffe2;"
                        "   background-color: #666666;"
                        "   border: 1px solid #d5d5d5;"
                        "   border-radius: 6px;"
                        "}"
                        ""
                        "QPushButton:hover{"
                        "   color: #1959d1;"
                        "   border: 1px solid #828282;"
                        "   background-color: #d5d5d5;"
                        "}"
                        ""
                        "QPushButton:hover:pressed{"
                        "   background-color: gray;"
                        "   color:white;"
                        "}");
}
