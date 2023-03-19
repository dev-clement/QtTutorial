#ifndef USERINPUT_H
#define USERINPUT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

class UserInput: public QWidget
{
public:
    UserInput(QLabel* pLabel, QLineEdit* pLineEdit);
    ~UserInput();

    QLabel& getLabel() const;
    QLineEdit& getLineEdit() const;
private:
    QLabel *_label;
    QLineEdit *_lineEdit;
};

#endif // USERINPUT_H
