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
    QMenuBar *mBar = menuBar();//不是new，menuBar()函数中自动new了

        //添加菜单
    QMenu *pFlie = mBar->addMenu("文件");
    QMenu *pEdit = mBar->addMenu("编辑");

        //添加菜单项，添加动作
    QAction *pNew = pFlie->addAction("新建");
    QAction *pAdd = pEdit->addAction("添加");
    pFlie->addSeparator();//添加分割线
    QAction *pOpen = pFlie->addAction("打开");

    connect(pNew,&QAction::triggered,
            [=]()
    {
       qDebug()<<"新建被按下";
    }
                );

    //工具栏
        //创建工具栏
    QToolBar * toolBar = addToolBar("toolBar");

        //工具栏添加快键键
    toolBar->addAction(pNew);//直接把新建的指针写上去就可以

        //将按钮添加到工具栏，
    QPushButton *b = new QPushButton(this);
    b->setText("点击改名");
        //添加小控件
        //工具栏上添加   工具栏对象->addWidget(添加一个按钮或者别的什么)
    toolBar->addWidget(b);
    connect(b,&QPushButton::clicked,
           [=]()
            {
               b->setText("123");
               qDebug()<<"改名被按下了";
            }
            );


    //状态栏
        //创建状态栏
    QStatusBar *sBar= statusBar();

        //设置标签，并取名
    QLabel *label = new QLabel(this);
    QLabel *label1=new QLabel(this);
    label->setText("打开成功");
    label1->setText(" 123 ");

        //设置添加的方向位置；不设置的话就是在左上角显示了
    sBar->addWidget(label);//从左下角开始往右添加
    sBar->addPermanentWidget(label1);//从右下角向左添加
        //通过构造函数
    sBar->addPermanentWidget(new QLabel(" 构造函数传参 ",this));

    //核心控件
        //创建一个文本编辑区
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);//set 设置 Central 中心 Widget部件

    //浮动窗口
        //创建一个浮动窗口对象
    QDockWidget *dockWidget = new QDockWidget(this);
        /*参数一是浮动窗口的位置
          参数二是浮动窗口对象*/
    addDockWidget(Qt::RightDockWidgetArea,dockWidget);


        // 给浮动窗口添加一个文本编辑区
    QTextEdit *textEdit1 = new QTextEdit(this);
    dockWidget->setWidget(textEdit1);

}

MyMainWindow::~MyMainWindow()
{

}
