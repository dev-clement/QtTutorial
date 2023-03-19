#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // String notation
    /*
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
    */

    // Functor notation: Normal slot
    /*
    connect(ui->horizontalSlider, &QSlider::valueChanged
            , ui->progressBar, &QProgressBar::setValue);
    */

    // Functor notation: Using lambda
    connect(ui->horizontalSlider, &QSlider::valueChanged
            , this, [=](){
        int percentage = ui->horizontalSlider->value();
        ui->progressBar->setValue(percentage);
    });
}

Widget::~Widget()
{
    delete ui;
}

