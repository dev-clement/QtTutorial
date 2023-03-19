#include <QPushButton>
#include <QDebug>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // Clicked signal
    QFont serifFont{"Times", 20, QFont::Bold};
    QPushButton *btn = new QPushButton("Button1", this);
    btn->setFont(serifFont);
    btn->setMinimumSize(200, 100);
    connect(btn, &QPushButton::clicked, this, [=](){
        qDebug() << "Button clicked...";
    });

    // Released signal
    QPushButton *btn2 = new QPushButton("Button2", this);
    btn2->setFont(serifFont);
    btn2->move(205, 0);
    btn2->setMinimumSize(200, 100);
    connect(btn2, &QPushButton::pressed, this, [=]() {
        qDebug() << "Button pressed...";
    });
    connect(btn2, &QPushButton::released, this, [=]() {
        qDebug() << "Buton released...";
    });
}

Widget::~Widget()
{
}

