#include "mywidget.h"
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    /*对于父窗口（主窗口），坐标系统相对于屏幕；
     * 原点 ：相对于屏幕左上角
     * x ；向右递增
     * y ；向下递增
    */
    move(100,100);

    /*子窗口，坐标系统相对于父窗口；
     * 原点 ：相对于父窗口空白区域左上角（不包括边框）
     * x ；向右递增
     * y ；向下递增
    */
    QPushButton *b1=new QPushButton(this);
    b1->setText("0.0");
    b1->resize(200,100);
    b1->move(150,150);

    QPushButton *b2=new QPushButton(b1);
    b2->setText("关闭 ");
    b2->resize(50,30);
    b2->move(0,0);
    connect(b2,&QPushButton::clicked,this,&MyWidget::close);

    //内存回收机制
    myButton=new MyButton(this);
    myButton->setText("123");
    //1）指定父对象后   2）必须是直接或间接继承于QObject
    //子对象如果是动态分配空间的new，不需要手动释放delete
    //系统会自动释放

    resize(400,300);
}

MyWidget::~MyWidget()
{

}
