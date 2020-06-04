#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerEditor.h"
#include <MenuActions.h>
#include <TaskStatus.hpp>

class TaskManagerEditor : public QMainWindow
{
    Q_OBJECT

public:

    static TaskManagerEditor * instance;

    static TaskManagerEditor* getInstance()
    {

        return instance;
    }

public:

    TaskManagerEditor(QWidget* parent = Q_NULLPTR);

    void showError(TaskManager::TaskStatus_b a);

private:

    Ui::TaskManagerEditorClass ui;

    MenuActions menuActions;
};
