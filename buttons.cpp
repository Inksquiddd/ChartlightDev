#include "buttons.h"

ListItem::ListItem(const QString &text, QListWidget *parent)
    : QListWidgetItem(parent)
{
    setText(text);
}

ListItem *ListItem::createListItem(const QListWidget *parentWidget, const QString &text, const char *member)
{
    ListItem *item = new ListItem(text);

    return item;
}


// Button
/***************************************************************************************
*    FOR BUTTON CLASS
*    Title: qtwidgets-widgets-calculator-example
*    Author: The Qt Company
*    Date: 2016
*    Code version: 5.15
*    Availability: https://code.qt.io/cgit/qt/qtbase.git/tree/examples/widgets/widgets/calculator/calculator.cpp?h=5.15
*
***************************************************************************************/
Button::Button(const QString &text, QWidget *parent)
    : QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(text);
}

Button *Button::createButton(const QWidget *parentWidget, const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), parentWidget, member);
    return button;
}

QSize Button::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
