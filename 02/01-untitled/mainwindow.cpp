#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QCompleter>   //模型      设定提示
#include <QStringList>  //字符串链表

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Button->setText("关闭窗口");
//    connect(ui->Button,&QPushButton::clicked,
//            [=]()
//    {
//        qDebug()<<"123";
//    }
//    );

    ui->pushButton_5->setText("切换");

    //QLineEdit
        //获取行编辑栏中的字符并输出
    QString str = ui->lineEdit->text();
    qDebug()<<str;

        //将行编辑栏的字符改值
    ui->lineEdit->setText("123456");

         //设置内容在lineEdit中显示的间距
    ui->lineEdit->setTextMargins(20,0,0,0);

        //设置内容显示方式
            /*设置为密码模式*/
        /*当lineEeit使用了下面的模型之后不可以使用密码模式，否则看不出效果*/
   // ui->lineEdit->setEchoMode(QLineEdit::Password);

    /*设置一个模型*/
        //设置提示；输入一个一个字符后提示相应的内容
    QStringList list;
    list << "hello" << "How" << "hehe";
        /*通过构造函数传参，将list的字符串传进去,并指定父对象*/
    QCompleter *com = new QCompleter(list,this);
        //设置大小写的区别
    com->setCaseSensitivity(Qt::CaseInsensitive);//设置是否区分大小写 0是不区分，1是区分
        //设定谁使用这个模型
    ui->lineEdit->setCompleter(com);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    //切换按钮控制容器换页

    static int i=0;
    //setCurrentIndex（）设置当前页索引
    ui->stackedWidget->setCurrentIndex(++i%3);
}
