#include "../headers/TaskManagerEditor.h"
#include <QMessageBox>

TaskManagerEditor::TaskManagerEditor(QWidget *parent)
    : QMainWindow(parent), menuActions(this, &ui)
{

    
    
}

void TaskManagerEditor::showError(TaskManager::TaskStatus_b a)
{
    if (!a.itsOk())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText(a.getError().c_str());
        msgBox.exec();
    }
}
