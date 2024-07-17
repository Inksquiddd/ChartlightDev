#include "supervisionwindow.h"

SupervisionWindow::SupervisionWindow(QWidget *parent): QWidget(parent){
    QGridLayout *grid = new QGridLayout;

    this->addUserBtn = Button::createButton(this, tr("Add New User"), SLOT(addTask()));
    this->removeUserBtn = Button::createButton(this, tr("REMOVE USER"), SLOT(addTask()));
    this->removeGUIBtn = Button::createButton(this, tr("REMOVE'S GUI USER"), SLOT(addTask()));
    this->clearTodoBtn = Button::createButton(this, tr("Clear ToDo"), SLOT(clearTodo()));
    this->addTaskBtn = Button::createButton(this, tr("Add to ToDo"), SLOT(addTask()));  // TODO: impliment way to retrieve taskInput
    this->updateUserTodoBtn = Button::createButton(this, tr("Send to User"), SLOT(updateUserTodo()));  // TODO: setup
    this->retrieveUserTodoBtn = Button::createButton(this, tr("Retrieve User's ToDo"), SLOT(addTask()));  // TODO: setup

    this->taskInputBox = new QLineEdit();
    this->localTodoList = new QListWidget();
    this->activeUsersList = new QListWidget();


    grid->addWidget(this->getActiveUsersBox(),0,0);
    grid->addWidget(this->getLocalTodoBox(),0,1);
    grid->addWidget(this->getSelectedUserBox(),0,2);

    setLayout(grid);

    setWindowTitle(tr("Supervion Window"));
    resize(480*2, 2*320);
}

void SupervisionWindow::deleteTask(){
    qDebug()<<"delete task. Used Git push";
}

// Button implementations

void SupervisionWindow::addTask(){
    if(this->taskInputBox->text() != static_cast<QString>("")){  // TODO: find better method of determining if input is entered
        this->taskInputBox->setDisabled(true);

        //notifyers
        qDebug() << "task added";
        qDebug() << taskInputBox->text();

        // TODO: add safeguard for preventing duplicate tasks within localToo
        QListWidgetItem *task = new QListWidgetItem(this->taskInputBox->text(), this->localTodoList);
        this->localTodoList->addItem(task);

        this->taskInputBox->clear();
        this->taskInputBox->setDisabled(false);
    }
}

void SupervisionWindow::updateUserTodo(){
    qDebug() << "TODO: impliment updateUserTodo()";
}

void SupervisionWindow::retrieveUserTodo(){
    qDebug() << "TODO: impliment retrieveUserTodo()";
}

void SupervisionWindow::clearTodo(){
    if(this->localTodoList->count() == 0) return;

    if(actionConfirmed("Are you sure you want to clear your list?")) {
        this->localTodoList->clear();
        qDebug() << "The Todo has been cleared";
    }
}


// group boxes

QGroupBox *SupervisionWindow::getLocalTodoBox(){

    this->connect(this->localTodoList,SIGNAL(doubleClicked(QModelIndex)),SLOT(deleteTask()));

    QVBoxLayout *boxLayout = new QVBoxLayout;
    boxLayout->addWidget(this->clearTodoBtn);
    boxLayout->addWidget(this->addTaskBtn);
    boxLayout->addWidget(this->updateUserTodoBtn);
    boxLayout->addWidget(this->taskInputBox);
    boxLayout->addWidget(this->localTodoList);


    QGroupBox *localTodoBox = new QGroupBox(tr("Local To-Do Box"));

    localTodoBox->setLayout(boxLayout);
    return localTodoBox;
}


QGroupBox *SupervisionWindow::getActiveUsersBox(){

    QVBoxLayout *boxLayout = new QVBoxLayout;

    boxLayout->addWidget(this->addUserBtn);
    boxLayout->addWidget(this->activeUsersList);

    QGroupBox *groupBox = new QGroupBox(tr("Active Users Box"));
    groupBox->setLayout(boxLayout);

    return groupBox;
}


QGroupBox *SupervisionWindow::getSelectedUserBox(){

    QVBoxLayout *boxLayout = new QVBoxLayout;

    boxLayout->addWidget(this->retrieveUserTodoBtn);
    boxLayout->addWidget(this->removeGUIBtn);
    boxLayout->addWidget(this->removeUserBtn);

    QGroupBox *groupBox = new QGroupBox(tr("Selected Users Box"));
    groupBox->setLayout(boxLayout);

    return groupBox;
}
