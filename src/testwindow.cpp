#include "testwindow.h"
#include "ui_testwindow.h"

TestWindow::TestWindow(QWidget *parent) :
    MyWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    initText();
    initButtons();
    initTheme();
    initVars();
}

void TestWindow::initText()
{
    startText = "Hey";
    ui->label->setText(startText);
    ui->progressBar->setRange(0,startText.size());
    ui->progressBar->setValue(0);
    curText = startText;

    ui->label_2->setText("");
    ui->label_3->setText("");
}

void TestWindow::initButtons()
{
    MyButton* button1 = button1->createMyButton(this,"назад");  //  button back
    buttons.push_back(button1);
    MyButton* button2 = button2->createMyButton(this,"изменить текст"); //  button change text
    buttons.push_back(button2);
    MyButton* button3 = button3->createMyButton(this,"начать сначала"); //  button restart
    buttons.push_back(button3);
    connect(button1, SIGNAL (released()), this, SLOT (button1Released()));
    connect(button2, SIGNAL (released()), this, SLOT (button2Released()));
    connect(button3, SIGNAL (released()), this, SLOT (button3Released()));

    int x = this->width() / (buttons.size() + 1) - buttons[0]->width()/2, y = 5;
    for(int i = 0; i < buttons.size(); i++)
    {
        buttons[i]->setCoords(x,y);
        x += this->width() / (buttons.size() + 1);
    }
}

void TestWindow::button1Released() //   button back
{
    this->hide();
    ((QWidget*)this->parent())->show();
    for(int i = 0; i < buttons.length(); i++)
    ui->lineEdit->setFocus();
}

void TestWindow::button2Released() //   button change text
{
    (new ChangeText(this))->show();
    this->hide();
    ui->lineEdit->setFocus();
}

void TestWindow::button3Released() //   button restart
{
    initText();
    ui->lineEdit->setFocus();
}

#include <QDir>
void TestWindow::finish()
{
    (new ResultWindow(this,timeMS,speed,mistakes))->show();
    QMessageBox::information(this," ", QDir::currentPath());
    this->hide();
}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::setLightTheme()
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
    ui->lineEdit->setStyleSheet("QLineEdit:read-only{"
                                "background: grey;");

    ui->progressBar->setStyleSheet("QProgressBar {"
                                   "    border: 2px solid grey;"
                                   "    background-color: #ffffff;"
                                   "    border-radius: 5px;"
                                   "}"
                                   ""
                                   "QProgressBar::chunk {"
                                   "    background-color: #26deff;"
                                   "}");

    ui->lineEdit->setStyleSheet("QLineEdit:read-only{"
                                "background-color: white;"
                                "}");

    ui->label->setStyleSheet("QLabel{"
                             "colorL black;"
                             "border: 2px solid green;"
                             "border-radius: 4px;"
                             "padding: 2px;"
                             "}");

    qApp->setPalette(lightPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}

void TestWindow::setDarkTheme()
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
    ui->label->setStyleSheet("QLabel{"
                             "colorL white;"
                             "border: 2px solid green;"
                             "border-radius: 4px;"
                             "padding: 2px;"
                             "}");

    ui->lineEdit->setStyleSheet("QLineEdit:read-only{"
                                "background-color: #191919;"
                                "}");

    ui->progressBar->setStyleSheet("QProgressBar {"
                                   "    border: 0px solid grey;"
                                   "    border-radius: 3px;"
                                   "}"
                                   ""
                                   "QProgressBar::chunk {"
                                   "    background-color: #2a82da;"
                                   "}");

    qApp->setPalette(darkPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}

void TestWindow::initTheme()
{
    if(((MainWindow*)parent())->isLightTheme)
    {
        setLightTheme();
    }
    else
    {
        setDarkTheme();
    }
}

void TestWindow::keyPressEvent(QKeyEvent *event)
{
    static QTime time;
    if(curText.size())
    {
        clicksNumber++;
        if(clicksNumber == 1)
        {
            time = QTime::currentTime();
        }
        else
        {
            QTime temp = QTime::currentTime();
            timeMS += temp.msecsSinceStartOfDay() - time.msecsSinceStartOfDay();
            time = temp;
            speed = (long long)(clicksNumber * 60000) / timeMS;
            ui->label_3->setText(QString::number(speed));
        }
        if(event->modifiers()&Qt::ShiftModifier)
        {
            if(event->key() == curText[0].unicode())
            {
                 curText.remove(0,1);
                 ui->label->setText(curText);
                 ui->progressBar->setValue(startText.size() - curText.size());
            }
            else
            {
                if(event->key()!=Qt::Key_Shift)
                    mistakes++;
            }
            ui->label_2->setText(QString::number(mistakes));
        }
        else
        {
            if(convertToUnicode(event->key()) == curText[0].unicode())
            {
                 curText.remove(0,1);
                 ui->label->setText(curText);
                 ui->progressBar->setValue(startText.size() - curText.size());
            }
            else
            {
                if(event->key()!=Qt::Key_Shift)
                    mistakes++;
            }
            ui->label_2->setText(QString::number(mistakes));
        }
//        int key = event->key();
//                ui->label_2->setText(MyItoa(key));
//                static int i;
//                ui->label_3->setText(MyItoa(curText.at(i).unicode()));
//                i++;
    }
    else
        finish();
}

void TestWindow::restart()
{
    initVars();

    ui->label->setText(startText);
    ui->progressBar->setRange(0,startText.size());
    ui->progressBar->setValue(0);
    curText = startText;

    ui->label_2->setText("");
    ui->label_3->setText("");
}

void TestWindow::setText(QString text)
{
    initVars();
    startText = text;

    ui->label->setText(startText);
    ui->progressBar->setRange(0,startText.size());
    curText = startText;

    ui->label_2->setText("");
    ui->label_3->setText("");
}

void TestWindow::initVars()
{
    clicksNumber = 0;
    speed = 0;
    mistakes = 0;
    timeMS = 0;
}

int TestWindow::convertToUnicode(int key)
{
    switch (key) {
    case Qt::Key_Space:
        return QChar(' ').unicode();
                                         //english
                                         //1 ряд
    case Qt::Key_Q:
        return QChar('q').unicode();
    case Qt::Key_W:
        return QChar('w').unicode();
    case Qt::Key_E:
        return QChar('e').unicode();
    case Qt::Key_R:
        return QChar('r').unicode();
    case Qt::Key_T:
        return QChar('t').unicode();
    case Qt::Key_Y:
        return QChar('y').unicode();
    case Qt::Key_U:
        return QChar('u').unicode();
    case Qt::Key_I:
        return QChar('i').unicode();
    case Qt::Key_O:
        return QChar('o').unicode();
    case Qt::Key_P:
        return QChar('p').unicode();
                                         //2 ряд
    case Qt::Key_A:
        return QChar('a').unicode();
    case Qt::Key_S:
        return QChar('s').unicode();
    case Qt::Key_D:
        return QChar('d').unicode();
    case Qt::Key_F:
        return QChar('f').unicode();
    case Qt::Key_G:
        return QChar('g').unicode();
    case Qt::Key_H:
        return QChar('h').unicode();
    case Qt::Key_J:
        return QChar('j').unicode();
    case Qt::Key_K:
        return QChar('k').unicode();
    case Qt::Key_L:
        return QChar('l').unicode();
    //3 ряд
    case Qt::Key_Z:
        return QChar('z').unicode();
    case Qt::Key_X:
        return QChar('x').unicode();
    case Qt::Key_C:
        return QChar('c').unicode();
    case Qt::Key_V:
        return QChar('v').unicode();
    case Qt::Key_B:
        return QChar('b').unicode();
    case Qt::Key_N:
        return QChar('n').unicode();
    case Qt::Key_M:
        return QChar('m').unicode();
                                        //russian
    case 1040:
        return 1072;//а
    case 1041:
        return 1073;//б
    case 1042:
        return 1074;//в
    case 1043:
        return 1075;//г
    case 1044:
        return 1076;//д
    case 1045:
        return 1077;//е
    case 1025:
        return 1105;//ё
    case 1046:
        return 1078;//ж
    case 1047:
        return 1079;//з
    case 1048:
        return 1080;//и
    case 1049:
        return 1081;//й
    case 1050:
        return 1082;//к
    case 1051:
        return 1083;//л
    case 1052:
        return 1084;//м
    case 1053:
        return 1085;//н
    case 1054:
        return 1086;//о
    case 1055:
        return 1087;//п
    case 1056:
        return 1088;//р
    case 1057:
        return 1089;//с
    case 1058:
        return 1090;//т
    case 1059:
        return 1091;//у
    case 1060:
        return 1092;//ф
    case 1061:
        return 1093;//х
    case 1062:
        return 1094;//ц
    case 1063:
        return 1095;//ч
    case 1064:
        return 1096;//ш
    case 1065:
        return 1097;//щ
    case 1066:
        return 1098;//ъ
    case 1067:
        return 1099;//ы
    case 1068:
        return 1100;//ь
    case 1069:
        return 1101;//э
    case 1070:
        return 1102;//ю
    case 1071:
        return 1103;//я
    }
}
