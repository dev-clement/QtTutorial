#ifndef ROCKWIDGET_H
#define ROCKWIDGET_H

#include <QLabel>
#include <QObject>
#include <QWidget>

class RockWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RockWidget(QWidget *parent = nullptr);
    ~RockWidget();

signals:

private slots:
    void buttonClicked();

private:
    QSize sizeHint() const;
    QLabel *m_label;

};

#endif // ROCKWIDGET_H
