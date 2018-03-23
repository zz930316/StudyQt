#include "smallwidget.h"
#include <QSpinBox>     //数字微调
#include <QSlider>      //滑块
#include <QHBoxLayout>  //水平布局管理器

SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    QSpinBox *spinBox = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal,this);

     //把控件添加到布局中
    QHBoxLayout *hLayout = new QHBoxLayout(this);
        /*当指定了父对象是就不需要  setLayout(hLayout);*/

    hLayout->addWidget(spinBox);
    hLayout->addWidget(slider);

    //  setLayout(hLayout);

                    //static_cast<void(QSpinBox::*)(int)>  强制类型转换为int
    connect(spinBox,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider,&QSlider::value);

    connect(slider,&QSlider::valueChanged,spinBox,&QSpinBox::setValue);
}
