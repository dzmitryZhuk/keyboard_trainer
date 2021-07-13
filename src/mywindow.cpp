#include "mywindow.h"

MyWindow::MyWindow()
{
    initWindowFlags();
}

MyWindow::MyWindow(QWidget *parent) : QDialog(parent)
{
    initWindowFlags();
}

void MyWindow::initWindowFlags()
{
    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
}
