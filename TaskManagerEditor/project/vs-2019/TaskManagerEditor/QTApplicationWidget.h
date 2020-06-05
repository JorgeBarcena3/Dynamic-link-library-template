#pragma once

#include <qtabwidget.h>
#include <PanelManager.hpp>

namespace Ui
{
    class TaskManagerEditorClass;
}

class QTApplicationWidget : public QTabWidget
{

private:

    TaskManager::PanelManager * panelManager;

public:

    QTApplicationWidget(QObject *parent);

    ~QTApplicationWidget();

    void refreshData();

    void connectSignals(Ui::TaskManagerEditorClass * ui);

public slots:

    void addPanel(bool triggered);

private:

    void setCurrentTab(int index);

    void removeTabs();

    void createTabsFromInfo();

    int createTab(QString name);

    void showError(TaskManager::TaskStatus_b err);

    void changePanel(int index);
};
