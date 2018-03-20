#include "myqpushbutton.h"
#include <QDebug>

MyQPushButton::MyQPushButton(QWidget *parent) : QPushButton(parent)
{

}
MyQPushButton::~MyQPushButton()
{
    qDebug()<<"调用析构";
}
