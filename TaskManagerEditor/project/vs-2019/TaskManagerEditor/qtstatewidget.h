#pragma once

#include <QWidget>
#include "ui_QTStateWidget.h"
#include <StateDto.hpp>
#include <PanelManager.hpp>

class QTStateWidget : public QWidget
{
    Q_OBJECT

private:

    Ui::QTStateWidget ui;

    TaskManager::PanelManager * panelManager;


public:

    QTStateWidget(TaskManager::StateDto * state, QWidget* parent = Q_NULLPTR);

    ~QTStateWidget();

    void refreshPanel(TaskManager::StateDto * state);

public slots:

    void add_task_to_state();

    void change_state_name();

private:

    void clearState();

    QString createDialog(QString title, QString subtitle);

    QString createMultiLineDialog(QString title, QString subtitle);


};
