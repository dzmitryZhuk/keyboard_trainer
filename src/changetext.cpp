#include "changetext.h"
#include "ui_changetext.h"

ChangeText::ChangeText(QWidget *parent) :
    MyWindow(parent),
    ui(new Ui::ChangeText)
{
    ui->setupUi(this);
    initButtons();
    initTheme();
}

void ChangeText::initButtons()
{
    MyButton* button1 = button1->createMyButton(this,"назад");
    buttons.push_back(button1);
    MyButton* button2 = button2->createMyButton(this,"применить");
    buttons.push_back(button2);
    connect(button1, SIGNAL (released()), this, SLOT (button1Released()));
    connect(button2, SIGNAL (released()), this, SLOT (button2Released()));

    for(int i = 0; i < buttons.size(); i++)
        ui->layout->addWidget(buttons[i]);
}

void ChangeText::initTheme()
{
    if(((MainWindow*)((TestWindow*)parent())->parent())->isLightTheme)
    {
        setLightTheme();
    }
    else
    {
        setDarkTheme();
    }
}

void ChangeText::button1Released() //назад
{
    this->close();
    ((QWidget*)parent())->show();
    ((TestWindow*)this->parent())->restart();
}

void ChangeText::button2Released() //применить
{
    this->close();
    ((QWidget*)parent())->show();
    ((TestWindow*)this->parent())->setText(ui->textEdit->toPlainText());
}

ChangeText::~ChangeText()
{
    delete ui;
}

void ChangeText::setLightTheme()
{
    qApp->setStyle(QStyleFactory::create("Fusion1"));

    QPalette lightPalette;
    lightPalette.setColor(QPalette::Window, QColor(240,240,240));
    lightPalette.setColor(QPalette::WindowText, Qt::black);
    lightPalette.setColor(QPalette::Base, Qt::black);
    lightPalette.setColor(QPalette::AlternateBase, Qt::lightGray);
    lightPalette.setColor(QPalette::ToolTipBase, Qt::black);
    lightPalette.setColor(QPalette::ToolTipText, Qt::black);
    lightPalette.setColor(QPalette::Text, Qt::black);
    for(int i = 0; i < buttons.size(); i++)
        buttons[i]->lightStyleSheet();
    lightPalette.setColor(QPalette::BrightText, Qt::red);
    lightPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    lightPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    lightPalette.setColor(QPalette::HighlightedText, Qt::white);

    ui->textEdit->setStyleSheet("QTextEdit{"
                                "background-color: white;"
                                "background-attachment: scroll;"
                                "}");

    qApp->setPalette(lightPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}

void ChangeText::setDarkTheme()
{
    qApp->setStyle(QStyleFactory::create("Fusion"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    for(int i = 0; i < buttons.size(); i++)
        buttons[i]->darkStyleSheet();
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    ui->textEdit->setStyleSheet("QTextEdit{"
                                "background-color: black;"
                                "background-attachment: scroll;"
                                "}");

    qApp->setPalette(darkPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}
