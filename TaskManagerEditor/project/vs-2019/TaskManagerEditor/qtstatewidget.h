#pragma once

#include <QWidget>
#include "ui_QTStateWidget.h"
#include <StateDto.hpp>

class QTStateWidget : public QWidget
{
    Q_OBJECT

private:

    Ui::QTStateWidget ui;

public:

    QTStateWidget(TaskManager::StateDto * state, QWidget* parent = Q_NULLPTR);

    ~QTStateWidget();

    void refreshPanel(TaskManager::StateDto * state);

private:

    void clearState();


};
