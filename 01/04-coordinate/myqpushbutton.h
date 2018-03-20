#ifndef MYQPUSHBUTTON_H
#define MYQPUSHBUTTON_H

#include <QObject>

class MyQPushButton : public QObject
{
    Q_OBJECT
public:
    explicit MyQPushButton(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYQPUSHBUTTON_H
