#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    /*通过调用  QWidget::setStyleSheet() 或 QApplication::setStyleSheet()
     * 来为一个独立的子部件、整个窗口，甚至整个应用程序指定一个样式表。
     *  setStyleSheet("QLabel{color:red;}");
     * 改变label的颜色（color）（red），
     //setStyleSheet(“控件类名{ 属性：属性对应的值; }”);
    */
    ui->label->setStyleSheet("QLabel{color:red;}");//直接指定字体为红色
            /*通过RGB来设置颜色,
             * background-color背景色
             *
 */
    /*改变应用程序中所有的QLabel*/
   this->setStyleSheet("QLabel{color:rgb(0,255,255);"
                             "background-color:red;"
                             "}");

     /*改变指定的QLabel*/
            /*背景图片设置
             * background-image:url(:图片地址)  图片是平铺的方式显示
             * border-image:url(:图片地址)  4 4 4 4 stretch stretch
             *   图片是自动适应label大小变化  4 4 4 4 是对图片进行裁剪，一般后面的不写
*/
    ui->label->setStyleSheet("QLabel{color:rgb(255,2555,255);"
                             "background-color:blue;"
                             "border-image:url(:/new/prefix1/im/yyyy.jpg);"
                             "}");

    /*对按钮进行设定  */
            /* border: 5px outset green; 边框： 5个像素点 向外扩展  绿色
             *
             * 按钮设定大小  ui->点击按钮->QWidget->minimumSize(最小值)或者maximumSize(最大值)
             * 伪状态的写法  控件类:伪状态（更多伪状态可以查阅资料）
             *       第一个是设置按钮正常显示
             * border-image:url(:/new/prefix1/im/pkq.jpg); 设置一张图片
             *      第二个是设置当鼠标放在按钮上
             * QPushButton:hover
             *      第三个是鼠标点击时
             * QPushButton:pressed
            */
    ui->pushButton->setStyleSheet("QPushButton{"
                                  "border:2px outset green;"
                                  "}"

                                  "QPushButton:hover{"
                                  "border-image:url(:/new/prefix1/im/yyyy.jpg);"
                                  "}"

                                  "QPushButton:pressed{"
                                  "border-image:url(:/new/prefix1/im/ufm.jpg);"
                                  "}");

    //还有一些使用子部件定义微观样式，查阅资料，用法类似 伪状态的用法

}

Widget::~Widget()
{
    delete ui;
}
