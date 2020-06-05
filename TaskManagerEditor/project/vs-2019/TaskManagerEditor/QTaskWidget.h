#pragma once

#include <QWidget>
#include "ui_QTaskWidget.h"
#include <TaskDto.hpp>

class QTaskWidget : public QWidget
{
    Q_OBJECT

private:

    Ui::QTaskWidget ui;

public:
    QTaskWidget(TaskManager::TaskDto & task, QWidget *parent = Q_NULLPTR);
    ~QTaskWidget();

private:

    void setInfo(TaskManager::TaskDto& task);

};
