#ifndef WIDGET_H
#define WIDGET_H

#include <memory>
#include <QWidget>
#include <QPointer>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

private:
    QPointer<QVBoxLayout> m_mainLayout;
};
#endif // WIDGET_H
