#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mybutton.h"
class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();
private:
    MyButton *myButton;
};

#endif // MYWIDGET_H
