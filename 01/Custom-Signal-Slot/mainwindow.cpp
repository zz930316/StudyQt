#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
   this->resize(400,300);//设置窗口大小

    b1.setParent(this);
    b1.setText("关闭1");
    b1.setGeometry(0,60,80,30);/*改变控件的位置和大小，
                                 第一个参数是按钮位置的纵坐标
                                 第二个参数是按钮位置的横坐标
                                 第三个参数是按钮的宽度
                                 第四个参数是按钮的高度*/

    b2=new QPushButton(this);//通过构造函数指定父对象
    b2->setText("按钮改名，并且隐藏按钮一");
    b2->resize(200,30);
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
    b3.setGeometry(200,0,150,30);

    //显示子窗口
    connect(&b3,&QPushButton::pressed,this,&MainWindow::Show1);

    //处理子窗口的信号
    /*因为subWidget中的mySignal函数重载了，所有用指针区分*/
    void (SubWidget::*p)()=&SubWidget::mySignal;//创建指向信号的指针;和指向函数的指针用法一样
    connect(&subWid, p, this , &MainWindow::dealSub);

    /*信号出现重载时不可以这样写
     *connect(&subWid,&SubWidget::mySignal,this,&MainWindow::deaSlot);*/
    void (SubWidget::*p2)(int ,QString) = &SubWidget::mySignal;//创建指向信号的指针;和指向函数的指针用法一样

    connect(&subWid,p2,this,&MainWindow::deaSlot);

    /*Qt4信号连接
     * Qt4槽函数必须有Slots关键字来修饰
    */
//    connect(&subWid,SIGNAL(mySignal()),this,SLOT(dealSub()));

//    connect(&subWid,SIGNAL(mySignal(int,QString)),this,SLOT(dealSlot(int,QString)));
        //SIGNAL  SLOT 是两个宏， 将函数名字 转换成 字符串   不进行错误检查
        //当宏内函数写写错时，编译也可以通过，只有运行出错，不利于查找错误

//------------------------------------------------------
     //Lambda表达式  ,匿名函数对象
     //C++增加的新特性，  项目文件中添加 ： CONFIG += C++11
     //Qt配合信号一起使用，非常方便
   QPushButton *b4=new QPushButton(this);
   b4->setText("Lambda表达式");
   b4->move(150,150);
   int aa=10,bb=100;
   connect(b4,&QPushButton::pressed,
           /* = ：把外部所有局部变量、类中所有成员以值传递方式传进去
            * this : 类中所有成员以值传递方式
            * & ： 把外部所有局部变量，不包括类成员，当按钮是动态分配的空间时，用&会出现内存问题，此时用=可以   引用符号，
            * 一般用 =

        */
           [=]() mutable    //不加 mutable 关键字时，函数体中的变量都是不能被修改的；
             {
              b4->setText("abc");
              qDebug()<<"aaaaaa";
              qDebug()<<aa<<bb;
              bb=99;        //因为加了 mutable 关键字，所以bb可以修改值；
              qDebug()<<aa<<bb;
              }
           );
}

MainWindow::~MainWindow()
{

}

void MainWindow::deaSlot(int a,QString str)
{
    static int b=0;
    a+=b++;
    qDebug()<<a<<str;
    //如果显示汉字不成功需要转换
    //将Qt中的 QString 转换成C语言中的 char* 的方法
    //str.toUtf8() 转换成 字节数组QByteArray
    //...data() 转换成 QByteArray -> char *
    qDebug()<<a<<str.toUtf8().data();
}
void MainWindow::dealSub()
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
