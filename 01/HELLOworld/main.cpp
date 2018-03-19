#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>//按钮
#include <QLabel>//文本
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    w.setWindowTitle(QString("标题"));//设置窗口标题

    /*指定父对象的两种方法
    1、ssetParent()
    2、通过构造函数传参
    指定父对象，只需要父对象显示，子对象自动显示*/
    QPushButton b;
    b.setText("- -");//设置按钮名字
    b.setParent(&w);//通过ssetParent函数指定父对象
    b.resize(40,30);


    QPushButton b1(&w);//构造函数指定父对象
    b1.setText("abc");
    b1.move(100,100);//移动坐标

    QLabel label("Hello,world");
    label.setParent(&w);
    label.setGeometry(50,50,80,80);//改变标签的位置和大小，前两个是位置，后两个是大小


    w.show();
    w.resize(500,500);
    return app.exec();
}
