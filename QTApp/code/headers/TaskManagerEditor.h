#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerEditor.h"
#include <MenuActions.h>

class TaskManagerEditor : public QMainWindow
{
    Q_OBJECT

public:

    TaskManagerEditor(QWidget *parent = Q_NULLPTR);



private:

    Ui::TaskManagerEditorClass ui;

    MenuActions menuActions;
};
