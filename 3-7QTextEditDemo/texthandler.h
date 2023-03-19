#ifndef TEXTHANDLER_H
#define TEXTHANDLER_H

#include <memory>
#include <QString>
#include <QPushButton>

class TextHandler
{
public:
    TextHandler(const QString& pString, QPushButton *pButton);
    const QString& getName() const;
    QPushButton *get() const;
private:
    QString m_name;
    QPushButton *m_btn;
};

#endif // TEXTHANDLER_H
