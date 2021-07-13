#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file = new MyInitFile();
    initSizeMainWindow();
    initButtons();
    initTheme();
}

MainWindow::~MainWindow()
{
    delete ui;
    file->setSizeOfMainWindow(this->width(),this->height());
}

void MainWindow::button1Released() //   button start
{
    TestWindow* w = new TestWindow(this);
    w->show();
    this->hide();
}

void MainWindow::button2Released() //   button settings
{
    buttons[0]->hide(); //  button start
    buttons[1]->hide(); //  button settings
    buttons[2]->hide(); //  button exit
    buttons[3]->show(); //  button theme light
    buttons[4]->show(); //  button theme dark
    buttons[5]->show(); //  button back
}

void MainWindow::button3Released() //   button exit
{
    this->close();
}

void MainWindow::button4Released() //   button light theme
{
    setLightTheme();
}

void MainWindow::button5Released() //   button dark theme
{
    setDarkTheme();
}

void MainWindow::button6Released() //   button back
{
    buttons[0]->show(); //  button start
    buttons[1]->show(); //  button settings
    buttons[2]->show(); //  button exit
    buttons[3]->hide(); //  button theme light
    buttons[4]->hide(); //  button theme dark
    buttons[5]->hide(); //  button back
}

void MainWindow::initButtons()
{
    MyButton* button1 = button1->createMyButton(this,"Начать");
    buttons.push_back(button1);
//    int x = (this->width())/2 - (button1->width())/2;
//    int y = (this->height())/3 - (button1->height())/2;
//    button1->setCoords(x,y);
//    y += 2 * button1->height();
    MyButton* button2 = button2->createMyButton(this,"Настройки");
    buttons.push_back(button2);
//    button2->setCoords(x,y);
//    y += 2 * button1->height();
    MyButton* button3 = button3->createMyButton(this,"Выйти");
    buttons.push_back(button3);
//    button3->setCoords(x,y);
    connect(button1, SIGNAL (released()), this, SLOT (button1Released()));
    connect(button2, SIGNAL (released()), this, SLOT (button2Released()));
    connect(button3, SIGNAL (released()), this, SLOT (button3Released()));
    for(int i = 0; i < buttons.size(); i++)
        ui->layout->addWidget(buttons[i], i, 2);


    // кнопки для настроек
    MyButton* button4 = button1->createMyButton(this,"Светлая тема");
    buttons.push_back(button4);
    button4->hide();
//    x = (this->width())/4 - (button1->width())/2;
//    y = (this->height())/3 - (button1->height())/2;
//    button4->setCoords(x,y);
//    x += this->width()/2;
    MyButton* button5 = button1->createMyButton(this,"Темная тема");
    buttons.push_back(button5);
    button5->hide();
//    button5->setCoords(x,y);
    connect(button4, SIGNAL (released()), this, SLOT (button4Released()));
    connect(button5, SIGNAL (released()), this, SLOT (button5Released()));
    for(int i = 3; i < buttons.size(); i++)
        ui->layout->addWidget(buttons[i], 1, 3*i - 9);
    MyButton* button6 = button1->createMyButton(this,"назад");
    button6->setFixedSize(button6->size()*0.7);
    buttons.push_back(button6);
    button6->hide();
    button6->setCoords(20,10);
    connect(button6, SIGNAL (released()), this, SLOT (button6Released()));

}

void MainWindow::initTheme()
{
    if(file->getTheme() == file->THEME_DARK)
    {
        setDarkTheme();
        isLightTheme = false;
    }
    else
    {
        setLightTheme();
        isLightTheme = true;
    }
}

void MainWindow::initSizeMainWindow()
{
    QSize size = file->getSizeOfMainWindow();
    QDesktopWidget screen;
    setGeometry(screen.width()/2 - size.width() / 2, screen.height()/2 - size.height() / 2, size.width(), size.height());
}

void MainWindow::setLightTheme()
{
    file->setLightTheme();
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

    qApp->setPalette(lightPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    file->setLightTheme();
    isLightTheme = true;
}

void MainWindow::setDarkTheme()
{
    file->setDarkTheme();
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

    qApp->setPalette(darkPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    file->setDarkTheme();
    isLightTheme = false;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    file->setSizeOfMainWindow(this->width(),this->height());
}
