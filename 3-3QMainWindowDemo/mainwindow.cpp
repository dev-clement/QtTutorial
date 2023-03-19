#include <QPushButton>
#include <QDebug>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Add central widget
    QPushButton *btn = new QPushButton{"Hello", this};
    setCentralWidget(btn);

    // Declare Qt Action
    QAction *qAction = new QAction("Quit");
    connect(qAction, &QAction::triggered, [=](){ QApplication::quit(); });

    // Add menus
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(qAction);

    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    // Add status bar message
    statusBar()->showMessage("Uploading file...", 5000);
    //statusBar()->clearMessage();
}

MainWindow::~MainWindow()
{
}

QSize MainWindow::sizeHint() const
{
    return QSize(800, 500);
}

