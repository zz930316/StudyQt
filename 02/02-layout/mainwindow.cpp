#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap( QPixmap(":/new/prefix1/im/yyyy.jpg"));
    ui->label->setScaledContents(true);


    ui->label_2->setText("用户名");
    ui->label_3->setText("密码");



    ui->pushButton->setText("登录");
    ui->pushButton_2->setText("关闭");

    /*将自定义的控件添加到程序时，
     * 1）要提升的类和被提升的基类要相同
     * 2）在ui中选择要提升的类，右击->提升为->在提升的类名称中要填写自定义的控件类名 ->全局包含->添加->提升
    */



}

MainWindow::~MainWindow()
{
    delete ui;
}
