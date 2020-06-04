#include "MenuActions.h"
#include <QFileDialog>
#include <Aplication.hpp>
#include <PanelManager.hpp>
#include <PanelExporter.hpp>
#include <PanelLoader.hpp>
#include <LuaScripting.hpp>
#include <TaskStatus.hpp>
#include <QDesktopServices>
#include <qinputdialog.h>
#include <fstream>


MenuActions::MenuActions(QMainWindow* parent, Ui::TaskManagerEditorClass* ui)
{
    panelLoader = (TaskManager::PanelLoader*)TaskManager::Aplication::instance()->getComponent("PanelLoader");
    manager = (TaskManager::PanelManager*)TaskManager::Aplication::instance()->getComponent("PanelManager");
    panelExporter = (TaskManager::PanelExporter*)TaskManager::Aplication::instance()->getComponent("PanelExporter");

    ui->setupUi(parent);

    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(load(bool)));
    connect(ui->actionXML, SIGNAL(triggered(bool)), this, SLOT(exportXML(bool)));
    connect(ui->actionXML_2, SIGNAL(triggered(bool)), this, SLOT(importXML(bool)));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save(bool)));
    connect(ui->actionSave_as, SIGNAL(triggered(bool)), this, SLOT(saveAs(bool)));
    connect(ui->actionGithub, SIGNAL(triggered(bool)), this, SLOT(openGitHub(bool)));
    connect(ui->actionLinkedin, SIGNAL(triggered(bool)), this, SLOT(openLinkedin(bool)));
    connect(ui->actionLua, SIGNAL(triggered(bool)), this, SLOT(executeLuaCommand(bool)));
    connect(ui->actionLuaFile, SIGNAL(triggered(bool)), this, SLOT(executeLuaFile(bool)));
}

MenuActions::~MenuActions()
{
}

void MenuActions::save(bool triggered)
{
    if (defaultPath == "")
        defaultPath = QFileDialog::getExistingDirectory(this, "Determine donde quiere exportar el archivo", QDir::currentPath());

    TaskManager::TaskStatus_b err = panelExporter->exportData(defaultPath.toUtf8().constData());
}

void MenuActions::saveAs(bool triggered)
{
    defaultPath = QFileDialog::getExistingDirectory(this, "Determine donde quiere exportar el archivo", QDir::currentPath());

    TaskManager::TaskStatus_b err = panelExporter->exportData(defaultPath.toUtf8().constData());
}

void MenuActions::exportXML(bool triggered)
{
    QString filenames = QFileDialog::getExistingDirectory(this, "Determine donde quiere exportar el archivo", QDir::currentPath());

    TaskManager::TaskStatus_b err = panelExporter->exportDataAsXML(filenames.toUtf8().constData());

}

void MenuActions::importXML(bool triggered)
{
    QStringList filenames = QFileDialog::getOpenFileNames(this, "Determine un archivo que abrir", QDir::currentPath(), "XML files (*.xml)");

    if (filenames.size() > 0)
        TaskManager::TaskStatus_b err = panelLoader->importPanelAsXML(filenames[0].toUtf8().constData());
}

void MenuActions::openGitHub(bool triggered)
{
    QString link = "https://github.com/JorgeBarcena3";
    QDesktopServices::openUrl(QUrl(link));

}

void MenuActions::openLinkedin(bool triggered)
{
    QString link = "https://www.linkedin.com/in/jorge-barcena/";
    QDesktopServices::openUrl(QUrl(link));
}

void MenuActions::executeLuaCommand(bool triggered)
{
    bool ok;

    QString text = QInputDialog::getMultiLineText(
        this,
        tr("Commando LUA"),
        tr("Commando:"),
        "",
        &ok);

    if (ok && !text.isEmpty())
    {
        executeLuaCode(text);
    }

}

void MenuActions::executeLuaFile(bool triggered)
{
    QStringList filenames = QFileDialog::getOpenFileNames(this, "Determine un archivo que abrir", QDir::currentPath(), "LUA files (*.LUA)");

    if (filenames.size() > 0)
    {
        executeLuaCode(readFile(filenames[0]));
    }        

}

void MenuActions::executeLuaCode(QString code)
{

    static TaskManager::LuaScripting* scripting = (TaskManager::LuaScripting*) TaskManager::Aplication::instance()->getComponent("scriptingComponent");
    scripting->exec(code.toUtf8().constData());

}

QString MenuActions::readFile(QString path)
{
    std::string data = "";

    string line;
    ifstream myfile(path.toUtf8().constData());

    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            data += line;
        }

        myfile.close();
    }

    return QString(data.c_str());
}

void MenuActions::load(bool triggered)
{

    QStringList filenames = QFileDialog::getOpenFileNames(this, "Determine un archivo que abrir", QDir::currentPath(), "SAV files (*.sav)");

    if (filenames.size() > 0)
        TaskManager::TaskStatus_b err = panelLoader->importPanel(filenames[0].toUtf8().constData());

}
