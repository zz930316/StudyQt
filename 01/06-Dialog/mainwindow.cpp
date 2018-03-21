#include "mainwindow.h"
#include <QMenu>     //菜单
#include <QMenuBar>  //菜单栏
#include <QAction>   //动作
#include <QDialog>   //对话框的基类
#include <QDebug>    //输出
#include <QMessageBox>  //<关于对话框，问题对话框>
#include <QFileDialog>  //文件对话框

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(300,400);
    QMenuBar *mBar = menuBar();
        //设定菜单栏
    setMenuBar(mBar);
        //在菜单栏添加一个菜单
    QMenu *menu = mBar->addMenu("对话框");

    //************************************************************/
        //模态对话框和非模态对话框
    QAction *p1 = menu->addAction("模态对话框");
    connect(p1,&QAction::triggered,
            [=]()
            {
               QDialog dia;/*程序运行到这里会创建一个新的对话框，*/
               dia.resize(100,50);
               dia.exec();/*新的对话框一直在这里循环，所以无法点击主窗口*/
                qDebug()<<"123456";
             });


    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2,&QAction::triggered,
            [=]()
            {
        /*当这段程序不暂定的时候，直接写局部变量QDialog dia;会在执行玩这个Lambda表达式之后
               直接关闭窗口，所以此时要么
                    1)将dia作为类的成员数据;
                    2)给dia动态分配空间；
                    */
          /* ＠＠　第一种写法，当作类成员时，[]里要加上=    */
//                dia2.resize(100,150);
//                dia2.show();
//                qDebug()<<"非模态对话框" ;

        /*　＠＠　第二种写法，动态分配空间，不能指定父对象*/
                QDialog *qdia = new QDialog();

                /*setAttribute 设置属性
                Qt::WA_DeleteOnClose 是属性中的一种，当窗口被关闭时自动释放空间 */
                qdia->setAttribute(Qt::WA_DeleteOnClose);

                qdia->resize(100,150);
                qdia->show();

            });

    //************************************************************/
        //下面的关于对话框和问题对话框
    QAction *p3 = menu->addAction("关于对话框");
    connect(p3,&QAction::triggered,
            [=]()
            {
            /*about是QMessageBox类的静态成员函数，所以用::来使用*/
                QMessageBox::about(this,"关于对话框","关于Qt！");
                    /*  参数一是指定父对象
                     * 参数二是标题
                     * 参数三显示文本内容
                     */
            });

    QAction *p4 = menu->addAction("问题对话框");
    connect(p4,&QAction::triggered,
            [=]()
            {
                /*默认按钮*/
               int rea = QMessageBox::question(this,"问题对话框","你还好吗？");

               /*自定义按钮，使用自定义按钮时 case 的选项要改成相应的枚举*/
//               int rea = QMessageBox::question(this,
//                         "问题对话框","你还好吗？",
//                          QMessageBox::Ok,QMessageBox::Cancel);
                switch(rea)
                {
                case QMessageBox::Yes :
                    qDebug()<<"是的，我很好！";
                    break;
                case QMessageBox::No :
                    qDebug()<<"我现在很难受！";
                    break;
                default :
                    break;
                }
            });

}

MainWindow::~MainWindow()
{

}
