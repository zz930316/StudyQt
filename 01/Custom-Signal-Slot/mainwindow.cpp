#include "mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    b1.setParent(this);
    b1.setText("关闭1");
    b1.setGeometry(0,60,80,30);/*改变标签的位置和大小，
                                 第一个参数是按钮位置的纵坐标
                                 第二个参数是按钮位置的横坐标
                                 第三个参数是按钮的宽度
                                 第四个参数是按钮的高度*/

    b2=new QPushButton(this);//通过构造函数指定父对象
    b2->setText("按钮改名，并且隐藏按钮一");

    connect(&b1,&QPushButton::pressed,this,&MainWindow::close);//对按钮一进行自带的信号与槽

    /*自定义槽，普通函数的用法
     * Qt5:任意的成员函数，普通全局函数，静态函数
     * 槽函数需要和信号一致（参数，返回值）
     * 由于信号都是没有返回值，所以，槽函数一定没有返回值*/

    connect(b2,&QPushButton::released,this,&MainWindow::myslot);//myslot是自定义槽
    connect(b2,&QPushButton::pressed,&b1,&QPushButton::hide);//隐藏按钮1

    this->setWindowTitle("BOSS");
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.setGeometry(150,0,150,30);

    //显示子窗口
    connect(&b3,&QPushButton::pressed,this,&MainWindow::Show1);


}

MainWindow::~MainWindow()
{

}
void MainWindow::Show2()
{
    subWid.hide();//子窗口隐藏
    this->show();//本窗口显示，
}
void MainWindow::Show1()
{
    subWid.show();//子窗口显示，
    this->hide();//本窗口隐藏
}

void MainWindow::myslot()
{
    b2->setText("改名之后");
}
