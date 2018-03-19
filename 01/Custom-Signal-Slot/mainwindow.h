#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "subwidget.h"      //子窗口头文件

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:        //信号

public slots:   //槽
    void myslot();
    void Show1();
    void Show2();


 //创建了两个按钮
private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;
    QPushButton b4;

    SubWidget subWid;
};

#endif // MAINWINDOW_H
