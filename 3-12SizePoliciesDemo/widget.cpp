#include <QGroupBox>
#include <QPointer>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMovie>
#include <QMenu>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_mainLayout = new QVBoxLayout{ this };

    QPointer<QMovie> movie = new QMovie{":/test.gif"};
    QPointer<QLabel> label = new QLabel{ this };
    label->setGeometry(0, 0, size().width(), size().height());
    label->setVisible(true);
    label->setScaledContents(true);
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setMovie(movie);
    label->show();
    movie->start();

    m_mainLayout->addWidget(label);
    setLayout(m_mainLayout);
}

