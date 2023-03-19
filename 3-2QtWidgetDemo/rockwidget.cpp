#include <QPushButton>
#include <QMessageBox>
#include "rockwidget.h"

RockWidget::RockWidget(QWidget *parent)
    : QWidget{parent}
{
    m_label = new QLabel("This is my label", this);

    // Add a style widget and move it around
    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window, Qt::yellow);
    label1Palette.setColor(QPalette::WindowText, Qt::blue);

    QPalette label2Palette;
    label2Palette.setColor(QPalette::Window, Qt::green);
    label2Palette.setColor(QPalette::WindowText, Qt::black);
    QFont label1Font("Times", 20, QFont::Bold);
    QFont serifFont("Times", 20, QFont::Bold);
    QFont buttonFont("Times", 20, QFont::Bold);

    QLabel *label1 = new QLabel(this);
    // The setAutoFillBackground will allows the label to be highlight by QPalette
    label1->setAutoFillBackground(true);
    label1->move(QPoint{ 50, 50 });
    label1->setPalette(label1Palette);
    label1->setFont(label1Font);
    label1->setText("My colored label");

    // Add another label
    QLabel *label2 = new QLabel(this);
    label2->setAutoFillBackground(true);
    label2->move(QPoint{100, 100});
    label2->setPalette(label2Palette);
    label2->setText("This is my second label...");
    label2->setFont(serifFont);

    // Add a button and connect to slot
    QPushButton *btn = new QPushButton(this);
    btn->setText("Click me");
    btn->setFont(buttonFont);
    btn->move(150, 150);
    connect(btn, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

RockWidget::~RockWidget() {
    delete m_label;
}

void RockWidget::buttonClicked()
{
    QMessageBox::information(this, "Message", "You clicked on my button");
}

QSize RockWidget::sizeHint() const {
    return QSize{500, 300};
}
