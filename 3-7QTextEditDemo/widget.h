#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <memory>
#include <QDebug>
#include <QSharedPointer>
#include "texthandler.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void setupUi();
    void setupLabel();
    QTextEdit* setupTextEdit();
    void setupCopyButton(QTextEdit* pTextEdit);
private:
    QLabel *m_label;
    QTextEdit *m_textEdit;
    QVector<TextHandler> m_textHandler;
};

#endif // WIDGET_H
