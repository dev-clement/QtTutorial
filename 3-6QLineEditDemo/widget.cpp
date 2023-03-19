#include <QDebug>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // First name input
    QLabel *pFirstNameLabel = new QLabel("First name", this);
    pFirstNameLabel->setMinimumSize(70, 50);
    pFirstNameLabel->move(10, 10);

    QLineEdit *pFirstNameLineEdit = new QLineEdit(this);
    pFirstNameLineEdit->setMinimumSize(200, 50);
    pFirstNameLineEdit->move(100, 10);

    m_firstName = new UserInput{pFirstNameLabel, pFirstNameLineEdit};

    // Last name input
    QLabel *pLastNameLabel = new QLabel("Last name", this);
    pLastNameLabel->setMinimumSize(70, 50);
    pLastNameLabel->move(10, 70);

    QLineEdit *pLastNameLE = new QLineEdit(this);
    pLastNameLE->setMinimumSize(200, 50);
    pLastNameLE->move(100, 70);

    m_lastName = new UserInput{pLastNameLabel, pLastNameLE};

    // City input
    QLabel *pCityLabel = new QLabel("City", this);
    pCityLabel->setMinimumSize(70, 50);
    pCityLabel->move(10, 130);

    QLineEdit *pCityLE = new QLineEdit(this);
    pCityLE->setMinimumSize(200, 50);
    pCityLE->move(100, 130);

    m_city = new UserInput{pCityLabel, pCityLE};

    // Submit button
    m_submitBtn = new QPushButton("Submit", this);
    m_submitBtn->move(10, 200);
    connect(m_submitBtn, &QPushButton::clicked,
            this, Widget::displayInfoFromLineEdit);
    // Respond to signals through LineEdit
    /*
    // Cursot position changed signal
    connect(pFirstNameLineEdit, &QLineEdit::cursorPositionChanged
            , this, [=](){
        qDebug() << "The current cursor position is: " << pFirstNameLineEdit->cursorPosition();
    });
    */
    /*
    // Signal when edit finished
    connect(pFirstNameLineEdit, &QLineEdit::editingFinished
            , this, [=]() {
        qDebug() << "Editing finished!";
    });
    */
    /*
    // Cursor return pressed
    connect(pFirstNameLineEdit, &QLineEdit::returnPressed
            , this, [=](){
        qDebug() << "When return is pressed !!";
    });
    */
    /*
    // Signal when selection changed
    connect(pFirstNameLineEdit, &QLineEdit::selectionChanged
            , this, [=](){
        qDebug() << "Selection changed";
    });
    */
    /*
    // TextChanged
    connect(pFirstNameLineEdit, &QLineEdit::textChanged
            , this, [=](const QString& text) {
        qDebug() << "Text changed: " << text;
    });
    */
    // Signal when text edited
    connect(pFirstNameLineEdit, &QLineEdit::textEdited
            , this, [=](const QString& text) {
        qDebug() << "Text editted: " << text;
    });

    // Change text in QLineEdit programmaticaly
    //pLastNameLE->setText("Say your last name");

    // Hint text
    pFirstNameLineEdit->setPlaceholderText("First name");
    pLastNameLE->setPlaceholderText("Last name");
    pCityLE->setPlaceholderText("City");
}

void Widget::displayInfoFromLineEdit() const
{
    auto firstName = m_firstName->getLineEdit().text();
    auto firstNameLabel = m_firstName->getLabel().text();
    auto lastName = m_lastName->getLineEdit().text();
    auto lastNameLabel = m_lastName->getLabel().text();
    auto city = m_city->getLineEdit().text();
    auto cityLabel = m_city->getLabel().text();
    if (!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty())
    {
        qDebug() << firstNameLabel << firstName;
        qDebug() << lastNameLabel << lastName;
        qDebug() << cityLabel<< city;
    } else
    {
        qDebug() << "A field is empty...";
    }
}

void Widget::keyPressEvent(QKeyEvent *)
{
    displayInfoFromLineEdit();
}

Widget::~Widget()
{
    delete m_firstName;
    delete m_lastName;
    delete m_city;
    delete m_submitBtn;
}

