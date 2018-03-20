#include "mymainwindow.h"

#include <QDebug>
#include <QPushButton>

#include <QMenuBar>     //菜单栏
#include <QMenu>        //菜单
#include <QAction>      //动作
#include <QToolBar>     //工具栏

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(200,200);
   //菜单栏
    QMenuBar *mBar = menuBar();//不是new，
        //添加菜单
    QMenu *pFile =mBar->addMenu("文件");
            //添加菜单项,添加动作
    QAction *pNew = pFile->addAction("新建");
    connect(pNew,&QAction::triggered,
            [=]()
            {
                qDebug()<<"新建被按下";
            });

    pFile->addSeparator();//添加分割线

    QAction *pOpen = pFile->addAction("打开");

    //工具栏，菜单项的快捷方式
    QToolBar *toolBar = addToolBar("toolBar");

        //工具栏添加快捷键
    toolBar->addAction(pNew);//直接把新建的指针写上去就可以

        //将按钮添加到工具栏，
    QPushButton *b = new QPushButton(this);
    b->setText("点击改名");
        //添加小控件
    toolBar->addWidget(b);
    connect(b,&QPushButton::clicked,
            [=]()
            {
                b->setText("+=+");
                qDebug()<<"改名被按下了";
            });

    //状态栏
    //核心控件
    //浮动窗口
}

MyMainWindow::~MyMainWindow()
{

}
