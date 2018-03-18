#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QDebug>//输出

 //信号和槽

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
 //第一个例子
    QPushButton button;
    button.setText("例子一 退出");
    button.setParent(&w);   //通过ssetParent函数指定父对象
    QObject::connect(&button,&QPushButton::clicked,&a,&QApplication::quit);
    /*connect() 第一个是发出信号的对象，第二个是发送对象发出的信号，
     * 第三个是接收信号的对象，第四个是接收对象在接收到信号之后所需要调用的函数。
     *   当 button 发出了 clicked（单击） 信号之后， 会自动调用 a 的 quit（关闭） 函数*/


 //第二个例子(这个按钮会覆盖上面例子的按钮)
    QPushButton button2("例子2 打印");
    button2.setParent(&w);      //通过ssetParent函数指定父对象
    QObject::connect(&button2,&QPushButton::clicked,
                     [](bool)
                     {
                        qDebug()<<"鼠标点击";
                     });
  //  使用[](){}要在pro文件中添加： QMAKE_CXXFLAGS += -std=c++0x
    button2.move(500,0);


   //第二个例子Qt4的写法
    QPushButton button3("例子三qt4写法退出");
    button3.setParent(&w);      //通过ssetParent函数指定父对象
    QObject::connect(&button3,SIGNAL(clicked()),&a,SLOT(quit()));
    //SIGNAL 和 SLOT 是两个宏
    button3.move(0,500);

    w.show();
    return a.exec();
}
/*
在Qt4中QObject有三个重载：：详细见《qt学习之路第15页》

bool connect(const QObject *, const char *,const QObject *, const char *,Qt::ConnectionType);

bool connect(const QObject *, const QMetaMethod &,const QObject *, const QMetaMethod &,Qt::ConnectionType);

bool connect(const QObject *, const char *,const char *,Qt::ConnectionType) const

----------------------------------------------------------------
  在Qt5中  QObject::connect() 有五个重载：详细见《qt学习之路第13页》
QMetaObject::Connection connect(const QObject *, const char *,const QObject *, const char *,Qt::ConnectionType);

QMetaObject::Connection connect(const QObject *, const QMetaMethod &,const QObject *, const QMetaMethod &,Qt::ConnectionType);

QMetaObject::Connection connect(const QObject *, const char *,const char *,Qt::ConnectionType) const;

QMetaObject::Connection connect(const QObject *, PointerToMemberFunction,const QObject *, PointerToMemberFunction,Qt::ConnectionType)

QMetaObject::Connection connect(const QObject *, PointerToMemberFunction,Functor);
*/
