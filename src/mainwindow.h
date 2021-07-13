#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"libs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool isLightTheme;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void initTheme();
    void initButtons();
    void initSizeMainWindow();
    void setLightTheme();
    void setDarkTheme();
    QVector<MyButton*>buttons;
    MyInitFile* file;

private slots:
    void button1Released(); // start
    void button2Released(); // settings
    void button3Released(); // exit
    void button4Released(); // theme light
    void button5Released(); // theme dark
    void button6Released(); // back

protected:
    void resizeEvent(QResizeEvent *event);
};
#endif // MAINWINDOW_H
