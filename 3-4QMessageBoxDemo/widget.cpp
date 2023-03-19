#include <QPushButton>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton(this);
    btn->setText("Click me.");
    btn->move(200, 200);
    connect(btn, &QPushButton::clicked, this, [=](){
        /*
        // The hard Way
        QMessageBox mBox;
        mBox.setMinimumSize(300, 300);
        mBox.setWindowTitle("Message title");
        mBox.setText("Something happened...");
        mBox.setInformativeText("Do you want to do something about it ?");
        mBox.setIcon(QMessageBox::Critical);
        mBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        mBox.setDefaultButton(QMessageBox::Cancel);
        int ret = mBox.exec();
        */
        /*
        // Critical message
        int ret = QMessageBox::critical(this, "Message title", "Something happened here. Do you wanna do something about it ?",
                                        QMessageBox::Ok | QMessageBox::Cancel);
        */
        /*
        // Information message
        int ret = QMessageBox::information(this, "Message title", "Something happened here... Do you wanna do something about it ?",
                                           QMessageBox::Ok | QMessageBox::Cancel);
        */

        // Warning message
        int ret = QMessageBox::warning(this, "Message title", "Something happened here... Do you wanna do something about it ?",
                                       QMessageBox::Ok | QMessageBox::Cancel);

        /*
        // Questionning message
        int ret = QMessageBox::question(this, "Message title", "Something happened here... Do you wanna do something about it ?",
                                        QMessageBox::Ok | QMessageBox::Cancel);
        */
        if (ret == QMessageBox::Ok)
        {
            qDebug() << "Message box seems to be ok...";
        }
        else if (ret == QMessageBox::Cancel)
        {
            qDebug() << "Message box seems to be canceled out...";
        }
    });
}

Widget::~Widget()
{
}

