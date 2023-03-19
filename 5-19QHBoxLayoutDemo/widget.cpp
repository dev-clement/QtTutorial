#include <QHBoxLayout>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Layout is defined
//    QHBoxLayout *hLayout = new QHBoxLayout{};

    // Add widget to the layout
//    hLayout->addWidget(ui->oneButton);
//    hLayout->addWidget(ui->twoButton);
//    hLayout->addWidget(ui->threeButton);
//    hLayout->addWidget(ui->fiveButton);
//    hLayout->addWidget(ui->fourButton);

    // Layout is set to the widget !
    // Commented-out because of the use of the form through design mode.
    // setLayout(hLayout);
}

Widget::~Widget()
{
    delete ui;
}

