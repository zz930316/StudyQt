#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QCompleter>   //模型      设定提示
#include <QStringList>  //字符串链表
#include <QMovie>       //动画类
#include <QDesktopServices>
#include <QUrl>
#include <QLCDNumber>   //数码管



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
    ui->lineEdit->setText("删除打H");

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

    //QLabel
        //设定文字
    ui->pushButton_8->setText("切换显示");
    ui->label_1->setText("显示文字");
        //设定图片
    ui->label_2->setPixmap(QPixmap("://im/yyyy.jpg"));  //QPixmap是图像类绘图会接触
            //设定图片自动适应窗口大小
    ui->label_2->setScaledContents(true);

        //QMovie 设定动画
            //创建动画；QMovie动画类
   QMovie *myMovie = new QMovie("://im/timg.gif");
            //设定动画和label关联
   ui->label_3->setMovie(myMovie);
            //启动动画
   myMovie->start();
   ui->label_3->setScaledContents(true);

        //设置html链接
   ui->label_4->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
            /*   "<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>
                网址的写法"<h1><a href=\"要打开的链接\">显示文字</a></h1>
                        */
            //设置点击就会打开这个链接
    ui->label_4->setOpenExternalLinks(true);//setOpenExternalLinks设置  打开 外部 链接

    //如果不写 setOpenExternalLinks(true);那么另外写一个槽函数去
   ui->label_5->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
   connect(ui->label_5,&QLabel::linkActivated,this,&MainWindow::slotOpenUrl);

    //QLCDNumber  数码管
        //设置数码管显示值
    ui->lcdNumber->display(123);

    //    进度条
    ui->progressBar->setMinimum(0);     //设置最小值
    ui->progressBar->setMaximum(100);   //设置最大值
    ui->progressBar->setValue(40);      //设置当前值







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotOpenUrl(const QString & link)
{
    //使用QDesktopServices要加头文件QDesktopServices
    QDesktopServices::openUrl(QUrl(link));

}


void MainWindow::on_pushButton_5_clicked()
{
    //切换按钮控制容器换页

    static int i=0;
    //setCurrentIndex（）设置当前页索引
    ui->stackedWidget->setCurrentIndex(++i%3);
}

void MainWindow::on_pushButton_8_clicked()
{
    static int p=0;
    //setCurrentIndex（）设置当前页索引
    ui->stackedWidget_2->setCurrentIndex(++p%4);
}
