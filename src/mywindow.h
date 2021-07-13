#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QDialog>

class MyWindow : public QDialog
{
public:
    MyWindow();
    MyWindow(QWidget *parent);
private:
    void initWindowFlags();
};

#endif // MYWINDOW_H
