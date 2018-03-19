#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
this->setWindowTitle("子窗口");
    b.setText("切换到主窗口");
    b.setParent(this);
    connect(&b,&QPushButton::clicked,this,&SubWidget::sendSlot);

    this->resize(400,300);
}

void SubWidget::sendSlot()
{
    emit mySignal();//发送子窗口的信号给主窗口
    emit mySignal(200,"我是子窗口");
}
