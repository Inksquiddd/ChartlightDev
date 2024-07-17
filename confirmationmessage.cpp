#include "confirmationmessage.h"

bool actionConfirmed(QString infomrationText) {
    QMessageBox msgBox;
    msgBox.setText("Confirmation Window");
    msgBox.setInformativeText(infomrationText);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    if (msgBox.exec() == QMessageBox::Yes) return true;
    return false;
}
