#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
this->setWindowTitle("子窗口");
    b.setText("切换到主窗口");
    b.setParent(this);
}

