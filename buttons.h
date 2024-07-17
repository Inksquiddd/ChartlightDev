

#ifndef BUTTONS_H
#define BUTTONS_H

#include <QToolButton>
#include <QListWidgetItem>

class ListItem : public QListWidgetItem
{

public:
    explicit ListItem(const QString &text, QListWidget *parent = nullptr);

    static ListItem *createListItem(const QListWidget *parentWidget, const QString &text, const char *member);
};

/***************************************************************************************
*    FOR BUTTON CLASS
*    Title: qtwidgets-widgets-calculator-example
*    Author: The Qt Company
*    Date: 2016
*    Code version: 5.15
*    Availability: https://code.qt.io/cgit/qt/qtbase.git/tree/examples/widgets/widgets/calculator/button.h?h=5.15
*
***************************************************************************************/
class Button : public QToolButton
{
    Q_OBJECT

public:
    explicit Button(const QString &text, QWidget *parent = nullptr);

    static Button *createButton(const QWidget *parentWidget, const QString &text, const char *member);

    QSize sizeHint() const override;
};
#endif // BUTTONS_H
