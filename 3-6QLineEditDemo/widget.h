#ifndef WIDGET_H
#define WIDGET_H

#include <QKeyEvent>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QCloseEvent>
#include "userinput.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void displayInfoFromLineEdit() const;
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    UserInput *m_firstName;
    UserInput *m_lastName;
    UserInput *m_city;
    QPushButton *m_submitBtn;
};
#endif // WIDGET_H
