#include "../headers/TaskManagerEditor.h"
#include <QMessageBox>


TaskManagerEditor* TaskManagerEditor::instance = nullptr;

TaskManagerEditor::TaskManagerEditor(QWidget* parent)
    : QMainWindow(parent), menuActions(this, &ui)
{
    TaskManagerEditor::instance = this;
}

void TaskManagerEditor::showError(TaskManager::TaskStatus_b a)
{
    if (!a.itsOk())
    {
        static QMessageBox  msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Error al realizar la accion");
        msgBox.setInformativeText(a.getError().c_str());

        msgBox.exec();

        
    }
}
