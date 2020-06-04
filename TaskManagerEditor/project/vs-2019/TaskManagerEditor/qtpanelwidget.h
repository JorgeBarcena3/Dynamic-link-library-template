#pragma once

#include <qtabwidget.h>
#include <PanelManager.hpp>

namespace Ui
{
    class TaskManagerEditorClass;
}

class QTPanelWidget : public QTabWidget
{

private:

    TaskManager::PanelManager * panelManager;

public:

    QTPanelWidget(QObject *parent);

    ~QTPanelWidget();

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
};
