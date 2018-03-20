#include "mybutton.h"
#include <QDebug>
MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}
MyButton::~MyButton()
{
    qDebug()<<"自动调用析构函数";
}
