#pragma once

#include <qwidget.h>
#include <QObject>
#include <ui_TaskManagerEditor.h>


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

    
    TaskManager::PanelLoader* panelLoader;
    TaskManager::PanelManager* manager;
    TaskManager::PanelExporter* panelExporter;

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
};
