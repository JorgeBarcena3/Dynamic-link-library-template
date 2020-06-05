#pragma once

#include "QtWidgets/qwidget.h"
#include <QObject>
#include <ui_TaskManagerEditor.h>
#include <TaskStatus.hpp>

namespace TaskManager
{

    class PanelLoader;
    class PanelManager;
    class PanelExporter;
}

class MenuActions : public QWidget
{
    Q_OBJECT

private:

    
    TaskManager::PanelLoader   * panelLoader;
    TaskManager::PanelManager  * manager;
    TaskManager::PanelExporter * panelExporter;

    QString defaultPath;

public:

    MenuActions(QMainWindow * parent, Ui::TaskManagerEditorClass * ui);
    ~MenuActions();

public slots:

    void load(bool triggered);

    void save(bool triggered);

    void saveAs(bool triggered);

    void exportXML(bool triggered);

    void importXML(bool triggered);

    void openGitHub(bool triggered);

    void openLinkedin(bool triggered);

    void executeLuaCommand(bool triggered);

    void executeLuaFile(bool triggered);

    void newFile(bool triggered);

    void closeApplication();

private:

    void activeFileButtons(Ui::TaskManagerEditorClass* ui);

    void desactiveFileButtons(Ui::TaskManagerEditorClass * ui);

    void executeLuaCode(QString code);

    QString readFile(QString path);

    void checkError(TaskManager::TaskStatus_b err);

};
