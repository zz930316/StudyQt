#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = 0);

signals:        //信号

public slots:   //槽

private:
    QPushButton b;
};

#endif // SUBWIDGET_H
