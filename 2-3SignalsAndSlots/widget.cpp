#include <QDebug>
#include <QPushButton>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1. String notation
    /*
    connect(ui->clickBtn, SIGNAL(clicked()), this, SLOT(changeText()));
    */

    //2. Functor notation: regular slot
    /*
    connect(ui->clickBtn, &QPushButton::clicked, this, &Widget::changeText);
    */

    //3. Functor notation: Lambda
    QPushButton* btn = ui->clickBtn;
    connect(btn, QPushButton::clicked, [=](){
        this->ui->label->setText("Hello World from lamda !");
    });
}

void Widget::changeText() {
    ui->label->setText("Hello World !!");
    qDebug() << "User clicked on the button !!";
}

Widget::~Widget()
{
    delete ui;
}

