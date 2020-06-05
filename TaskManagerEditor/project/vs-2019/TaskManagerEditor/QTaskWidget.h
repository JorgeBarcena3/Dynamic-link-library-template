#pragma once

#include <QWidget>
#include "ui_QTaskWidget.h"
#include <TaskDto.hpp>
#include <PanelManager.hpp>

class QTaskWidget : public QWidget
{
    Q_OBJECT

private:

    Ui::QTaskWidget ui;

    TaskManager::TaskDto * currentTask;

    TaskManager::PanelManager * manager;


public:

    QTaskWidget(TaskManager::TaskDto & task, QWidget *parent = Q_NULLPTR);

    ~QTaskWidget();

public slots:

    void edit_task_title(bool triggered);

    void change_to_panel(bool triggered);

    void remove_task(bool triggered);

    void edit_assigned(bool triggered);

    void edit_description(bool triggered);

private:

    void refresh_info();

    void connectSignals();

    QString createDialog(QString title, QString subtitle);

    QString createMultiLineDialog(QString title, QString subtitle);

};
