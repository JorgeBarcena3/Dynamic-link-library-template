#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerEditor.h"
#include <MenuActions.h>
#include <TaskStatus.hpp>

class TaskManagerEditor : public QMainWindow
{
    Q_OBJECT

public:

    static TaskManagerEditor* getInstance()
    {
        static TaskManagerEditor instance;

        return &instance;
    }

private:

    TaskManagerEditor(QWidget* parent = Q_NULLPTR);

public:

    void showError(TaskManager::TaskStatus_b a);

private:

    Ui::TaskManagerEditorClass ui;

    MenuActions menuActions;
};
