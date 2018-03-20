#include "mymainwindow.h"

#include <QDebug>
#include <QPushButton>

#include <QMenuBar>     //菜单栏
#include <QMenu>        //菜单
#include <QAction>      //动作
#include <QToolBar>     //工具栏
#include <QStatusBar>   //状态栏
#include <QLabel>       //标签
#include <QTextEdit>    //文本编辑区
#include <QDockWidget>  //浮动窗口

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,400);
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
    QStatusBar *sBar = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("abcdefg");
    sBar->addWidget(label);

        //addWidget是从左往右添加
    sBar->addWidget(new QLabel("123",this));

         //addPermanentWidget是从右往做左添加
    sBar->addPermanentWidget(new QLabel("654",this));

    //核心控件(空白区域是文本编辑区)
    QTextEdit *textEdit = new QTextEdit();
    setCentralWidget(textEdit);//设置主要控件

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    QTextEdit *tEdit = new QTextEdit();
    dock->setWidget(tEdit);

}

MyMainWindow::~MyMainWindow()
{

}
