#pragma once
#include <MenuActions.h>


#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerEditor.h"
#include <TaskStatus.hpp>

class TaskManagerEditor : public QMainWindow
{
    Q_OBJECT

private:

    static TaskManagerEditor* instance;

public:

    static TaskManagerEditor* getInstance()
    {

        return instance;
    }

public:

    TaskManagerEditor(QWidget* parent = Q_NULLPTR);

    void showError(TaskManager::TaskStatus_b a);

    void refreshBoard();

    inline Ui::TaskManagerEditorClass* getUI()
    {
        return &ui;
    }

private:

    Ui::TaskManagerEditorClass ui;

    MenuActions menuActions;
};
