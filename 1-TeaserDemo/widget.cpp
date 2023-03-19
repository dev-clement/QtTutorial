#include <QDebug>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *btn = ui->submitBtn;
    connect(btn, QPushButton::clicked,
            [=](){ this->onSubmitClicked(); });
}

void Widget::onSubmitClicked() {
    qDebug() << "Submitting data...";
    qDebug() << "First name: " << ui->firstNameLE->text();
    qDebug() << "Last name: " << ui->lastNameLE->text();
    qDebug() << "Message: " << ui->messageTextE->toPlainText();
}

Widget::~Widget()
{
    delete ui;
}

