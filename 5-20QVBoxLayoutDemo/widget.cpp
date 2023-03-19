#include <QVBoxLayout>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    Create the layout
    auto vLayout = new QVBoxLayout{};

//    Set the layout
    vLayout->addWidget(ui->oneButton);
    vLayout->addWidget(ui->twoButton);
    vLayout->addWidget(ui->threeButon);
    vLayout->addWidget(ui->fourButton);
    vLayout->addWidget(ui->fiveButton);

//    Set the layout to the widget
    setLayout(vLayout);
}

Widget::~Widget()
{
    delete ui;
}

