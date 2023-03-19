#include "texthandler.h"

TextHandler::TextHandler(const QString& pName,
                         QPushButton *pButton)
    : m_name{pName}, m_btn{pButton}
{}

const QString &TextHandler::getName() const {
    return m_name;
}

QPushButton *TextHandler::get() const {
    return m_btn;
}
