#include "resultwindow.h"
#include "ui_resultwindow.h"

ResultWindow::ResultWindow(QWidget *parent, int _time, int _speed, long long _mistakes) :
    MyWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    initButtons();

    QString time = MyItoa(_time/1000);
    time += " секунд";
    ui->labelTime->setText(time);
    QString speed = MyItoa(_speed);
    speed += " символов в минуту";
    ui->labelSpeed->setText(speed);
    QString mistakes = (MyItoa(_mistakes));
    mistakes += " ошибок";
    ui->labelMistakes->setText(mistakes);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::initButtons()
{
    MyButton* button1 = button1->createMyButton(this,"назад");
    buttons.push_back(button1);
    connect(button1, SIGNAL (released()), this, SLOT (button1Released()));

    for(int i = 0; i < buttons.size(); i++)
        ui->layout->addWidget(buttons[i]);
}

void ResultWindow::button1Released() // назад
{
    this->close();
    ((QWidget*)this->parent())->show();
    ((TestWindow*)this->parent())->restart();
}
