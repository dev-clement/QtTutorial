#include "userinput.h"

UserInput::UserInput(QLabel *pLabel, QLineEdit *pLineEdit)
    : _label{pLabel}
    , _lineEdit{pLineEdit}
{

}

QLabel& UserInput::getLabel() const {
    return *_label;
}

QLineEdit& UserInput::getLineEdit() const {
    return *_lineEdit;
}

UserInput::~UserInput() {
    delete _label;
    delete _lineEdit;
}
