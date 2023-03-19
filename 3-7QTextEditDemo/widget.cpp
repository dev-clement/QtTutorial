#include <utility>
#include "utils.h"
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , m_label{ new QLabel{"This is my label !", this} }
    , m_textEdit{ new QTextEdit{ this } }
    , m_textHandler{
          TextHandler("cut", new QPushButton("Cut", this))
          , TextHandler("copy", new QPushButton("Copy", this))
          , TextHandler("paste", new QPushButton("Paste", this))
          , TextHandler("undo", new QPushButton("Undo", this))
          , TextHandler("redo", new QPushButton("Redo", this))
          , TextHandler("plain", new QPushButton("Plain text", this))
          , TextHandler("html", new QPushButton("Plain Html", this))
          , TextHandler("grabPlain", new QPushButton("Grab plain Tet", this))
          , TextHandler("grabHtml", new QPushButton("Grab Html", this))
    }
{
    setupUi();
}

void Widget::setupLabel()
{
    QFont lLabelFont{ "Times", 10, QFont::Bold };
    m_label->setFont(lLabelFont);
    m_label->move(100, 25);
}

QTextEdit* Widget::setupTextEdit()
{
    m_textEdit->move(70, 55);
    connect(m_textEdit, &QTextEdit::textChanged, this, [=] () { qDebug() << "Text changed..."; });
    return m_textEdit;
}

void Widget::setupCopyButton(QTextEdit* pTextEdit)
{
/*    auto copyBtn = std::find_if(m_textHandler.begin(), m_textHandler.end()
                                , [=](const TextHandler& lhs){ return lhs.getName() == "copy"; });
    if (copyBtn == m_textHandler.cend())
        throw std::runtime_error("Error while looking for copy btn");
*/
    TextHandler handler = Utils::instance()->getHandlerByName(m_textHandler, "copy");
    QPushButton *copyBtnObject = handler.get();
    copyBtnObject->setMinimumSize(50, 25);
    copyBtnObject->move(10, 250);
    connect(copyBtnObject, &QPushButton::clicked
            , this, [=](){ pTextEdit->copy(); });
}

void Widget::setupUi()
{
    setupLabel();
    setupTextEdit();
    setupCopyButton(m_textEdit);

/*    // Copy, cut and paste
    m_buttons["copy"]->setMinimumSize(50, 25);
    m_buttons["copy"]->move(10, 250);
    connect(m_buttons["copy"], &QPushButton::clicked,
            this, [=](){
       m_textEdit->copy();
    });

    m_buttons["cut"]->setMinimumSize(50, 25);
    m_buttons["cut"]->move(150, 250);
    connect(m_buttons["cut"], &QPushButton::clicked,
            this, [=](){
        m_textEdit->cut();
    });

    m_buttons["paste"]->setMinimumSize(50, 25);
    m_buttons["paste"]->move(310, 250);
    connect(m_buttons["paste"], &QPushButton::clicked,
            this, [=](){
        m_textEdit->paste();
    });

    // Undo and Redo
    m_buttons["undo"]->setMinimumSize(50, 25);
    m_buttons["undo"]->move(10, 280);
    connect(m_buttons["undo"], &QPushButton::clicked
            , this, [=](){
        m_textEdit->undo();
    });

    m_buttons["redo"]->setMinimumSize(50, 25);
    m_buttons["redo"]->move(310, 280);
    connect(m_buttons["redo"], &QPushButton::clicked
            , this, [=](){
        m_textEdit->redo();
    });

    // Set text and HTML into text edit
    m_buttons["plain"]->setMinimumSize(100, 25);
    m_buttons["plain"]->move(10, 310);
    connect(m_buttons["plain"], &QPushButton::clicked
            , this, [=](){
        m_textEdit->setPlainText("Lorem ipsum...");
    });

    m_buttons["html"]->setMinimumSize(100, 25);
    m_buttons["html"]->move(310, 310);
    connect(m_buttons["html"], &QPushButton::clicked
            , this, [=]() {
        m_textEdit->setHtml("<h1>Hello World</h1><br />My name is Clement");
    });

    // Grab that text
    m_buttons["grabHtml"]->setMinimumSize(100, 25);
    m_buttons["grabHtml"]->move(10, 340);
    connect(m_buttons["grabHtml"], &QPushButton::clicked
            , this, [=](){
        qDebug() << "The plain text inside the text edit is: "
                 << m_textEdit->toPlainText();
    });

    m_buttons["grabText"]->setMinimumSize(100, 25);
    m_buttons["grabText"]->move(310, 340);
    connect(m_buttons["grabText"], &QPushButton::clicked
            , this, [=](){
        qDebug() << "The html text inside the text edit is: "
                 << m_textEdit->toHtml();
    });
*/
}

Widget::~Widget()
{
}

