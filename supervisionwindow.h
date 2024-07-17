#ifndef SUPERVISIONWINDOW_H
#define SUPERVISIONWINDOW_H

#include <QDebug>

#include <qwidget.h>
#include <QGridLayout>
#include <QLineEdit>

#include <QListWidget>
#include <QListWidgetItem>

#include <QGroupBox>
#include <QBoxLayout>

#include "buttons.h"
#include "confirmationmessage.h"

class SupervisionWindow : public QWidget
{
    Q_OBJECT

public:
    SupervisionWindow(QWidget *parent = nullptr);

private slots:
    void addTask();

    void clearTodo();

    void updateUserTodo();
    void retrieveUserTodo();

    void deleteTask();
private:
    Button *addUserBtn;
    Button *removeUserBtn;
    Button *removeGUIBtn;
    Button *clearTodoBtn;
    Button *addTaskBtn;
    Button *updateUserTodoBtn;
    Button *retrieveUserTodoBtn;

    QLineEdit *taskInputBox;

    QListWidget *localTodoList;
    QListWidget *activeUsersList;

    QGroupBox *getLocalTodoBox();
    QGroupBox *getActiveUsersBox();
    QGroupBox *getSelectedUserBox();
};
#endif // SUPERVISIONWINDOW_H
