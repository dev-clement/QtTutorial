#include <memory>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto widget = std::make_unique<QWidget>();
    auto topFiller = std::make_unique<QWidget>();
    setCentralWidget(widget.get());
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    _infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    _infoLabel->setAlignment(Qt::AlignCenter);

    auto bottomFilter = std::make_unique<QWidget>();
    bottomFilter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    auto layout = std::make_unique<QVBoxLayout>();
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(topFiller.get());
    layout->addWidget(_infoLabel.get());
    layout->addWidget(bottomFilter.get());
    widget->setLayout(layout.get());
}


MainWindow::~MainWindow()
{
}
