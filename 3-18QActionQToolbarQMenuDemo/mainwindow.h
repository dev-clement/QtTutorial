#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPointer>
#include <QWidget>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QPointer<QWidget> m_centerWidget;
};
#endif // MAINWINDOW_H
