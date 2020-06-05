#pragma once

#include <QWidget>
#include "ui_QTPanelWidget.h"
#include <PanelManager.hpp>


class QTPanelWidget : public QWidget
{
    Q_OBJECT

private:

    QString name;

    TaskManager::PanelManager* panelManager;

    Ui::QTPanelWidget ui;

    int stateIndex;

    int max_states;


public:

    QTPanelWidget(QString name, QWidget *parent = Q_NULLPTR);

    ~QTPanelWidget();

    inline QString getName() { return name; };

    void refreshPanel();

private:

    void clearPanel();

    void nextState();

    void previusState();

};
