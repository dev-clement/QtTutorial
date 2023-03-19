#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_centerWidget{ new QWidget{this} }
{
    setCentralWidget(m_centerWidget.data());
}

