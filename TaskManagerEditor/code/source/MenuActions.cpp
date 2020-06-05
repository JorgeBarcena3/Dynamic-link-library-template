#include <MenuActions.h>
#include <TaskManagerEditor.h>

#include <QFileDialog>
#include <Aplication.hpp>
#include <PanelManager.hpp>
#include <PanelExporter.hpp>
#include <PanelLoader.hpp>
#include <LuaScripting.hpp>
#include <TaskStatus.hpp>
#include <PanelDto.hpp>
#include <QDesktopServices>
#include <qinputdialog.h>
#include <fstream>
#include <QMessageBox>


MenuActions::MenuActions(QMainWindow* parent, Ui::TaskManagerEditorClass* ui)
{
    panelLoader = (TaskManager::PanelLoader*)TaskManager::Aplication::instance()->getComponent("PanelLoader");
    manager = (TaskManager::PanelManager*)TaskManager::Aplication::instance()->getComponent("PanelManager");
    panelExporter = (TaskManager::PanelExporter*)TaskManager::Aplication::instance()->getComponent("PanelExporter");

    ui->setupUi(parent);

    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(load(bool)));
    connect(ui->actionXML_Export, SIGNAL(triggered(bool)), this, SLOT(exportXML(bool)));
    connect(ui->actionXML_Import, SIGNAL(triggered(bool)), this, SLOT(importXML(bool)));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save(bool)));
    connect(ui->actionSave_as, SIGNAL(triggered(bool)), this, SLOT(saveAs(bool)));
    connect(ui->actionGithub, SIGNAL(triggered(bool)), this, SLOT(openGitHub(bool)));
    connect(ui->actionLinkedin, SIGNAL(triggered(bool)), this, SLOT(openLinkedin(bool)));
    connect(ui->actionLua, SIGNAL(triggered(bool)), this, SLOT(executeLuaCommand(bool)));
    connect(ui->actionLuaFile, SIGNAL(triggered(bool)), this, SLOT(executeLuaFile(bool)));
    connect(ui->actionNew, SIGNAL(triggered(bool)), this, SLOT(newFile(bool)));
    connect(ui->actionRemove_Panel, SIGNAL(triggered(bool)), this, SLOT(removePanel(bool)));
    connect(ui->actionClose, SIGNAL(triggered(bool)), parent, SLOT(close()));
    connect(QCoreApplication::instance(), SIGNAL(aboutToQuit()), this, SLOT(closeApplication()));

    ui->panelWidget->connectSignals(ui);

    desactiveFileButtons(ui);

}

MenuActions::~MenuActions()
{

}

void MenuActions::save(bool triggered)
{
    if (defaultPath == "")
        defaultPath = QFileDialog::getSaveFileName(this, "Save file as", QDir::currentPath(), "SAV files (*.sav)");

    checkError(panelExporter->exportData(defaultPath.toUtf8().constData()));
}

void MenuActions::saveAs(bool triggered)
{
    defaultPath = QFileDialog::getSaveFileName(this, "Save file as", QDir::currentPath(), "SAV files (*.sav)");

    if (defaultPath != "")
        checkError(panelExporter->exportData(defaultPath.toUtf8().constData()));
}

void MenuActions::exportXML(bool triggered)
{
    QString filenames = QFileDialog::getSaveFileName(this, "Save file as", QDir::currentPath(), "XML files (*.xml)");

    checkError(panelExporter->exportDataAsXML(filenames.toUtf8().constData()));

}

void MenuActions::importXML(bool triggered)
{
    QStringList filenames = QFileDialog::getOpenFileNames(this, "Open file", QDir::currentPath(), "XML files (*.xml)");

    if (filenames.size() > 0)
    {
        checkError(panelLoader->importPanelAsXML(filenames[0].toUtf8().constData()));

        TaskManagerEditor::getInstance()->refreshBoard();
        activeFileButtons(TaskManagerEditor::getInstance()->getUI());
    }

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
    QStringList filenames = QFileDialog::getOpenFileNames(this, "Open File", QDir::currentPath(), "LUA files (*.LUA)");

    if (filenames.size() > 0)
    {
        executeLuaCode(readFile(filenames[0]));
    }

}

void MenuActions::newFile(bool triggered)
{
    saveAs(triggered);

    if (defaultPath != "")
    {
        auto  m = ((TaskManager::PanelManager*)TaskManager::Aplication::instance()->getComponent("PanelManager"));
        m->createNewPanel();

        TaskManagerEditor::getInstance()->refreshBoard();

        activeFileButtons(TaskManagerEditor::getInstance()->getUI());
    }

}

void MenuActions::closeApplication()
{

    if (TaskManagerEditor::getInstance()->getUI()->actionSave->isEnabled())
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Save", "Do you want to save the file?",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            save(false);
        }
    }


}

void MenuActions::removePanel(bool triggered)
{
    QStringList items;
    for( auto panel : manager->getAllPanels().getReturnObj() )
    {
        items << QString(panel->getTitle().c_str());
    }
    

    bool ok;
    QString item = QInputDialog::getItem(
        this,
        "Remove panel",
        "Name: ", 
        items, 
        0, 
        false,
        &ok
    );

    if (ok && !item.isEmpty())
        manager->removePanel(item.toUtf8().constData());  

    TaskManagerEditor::getInstance()->refreshBoard();

}


void MenuActions::activeFileButtons(Ui::TaskManagerEditorClass* ui)
{
    ui->actionXML_Export->setEnabled(true);
    ui->actionSave->setEnabled(true);
    ui->actionSave_as->setEnabled(true);
    ui->actionLua->setEnabled(true);
    ui->actionLuaFile->setEnabled(true);
    ui->actionNew_Panel->setEnabled(true);
    ui->actionRefresh->setEnabled(true);
    ui->actionEdit_Panel->setEnabled(true);
    ui->actionRemove_Panel->setEnabled(true);
}

void MenuActions::desactiveFileButtons(Ui::TaskManagerEditorClass* ui)
{
    //ui->actionOpen->;

    ui->actionXML_Export->setEnabled(false);
    ui->actionSave->setEnabled(false);
    ui->actionSave_as->setEnabled(false);
    ui->actionLua->setEnabled(false);
    ui->actionLuaFile->setEnabled(false);
    ui->actionNew_Panel->setEnabled(false);
    ui->actionRefresh->setEnabled(false);
    ui->actionEdit_Panel->setEnabled(false);
    ui->actionRemove_Panel->setEnabled(false);
}

void MenuActions::executeLuaCode(QString code)
{

    static TaskManager::LuaScripting* scripting = (TaskManager::LuaScripting*) TaskManager::Aplication::instance()->getComponent("scriptingComponent");
    checkError(scripting->exec(code.toUtf8().constData()));

    TaskManagerEditor::getInstance()->refreshBoard();


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

    QStringList filenames = QFileDialog::getOpenFileNames(this, "Open File", QDir::currentPath(), "SAV files (*.sav)");

    if (filenames.size() > 0)
    {
        defaultPath = filenames[0].toUtf8().constData();
        checkError(panelLoader->importPanel(defaultPath.toUtf8().constData()));
        TaskManagerEditor::getInstance()->refreshBoard();
        activeFileButtons(TaskManagerEditor::getInstance()->getUI());
    }




}

void MenuActions::checkError(TaskManager::TaskStatus_b err)
{
    TaskManagerEditor::getInstance()->showError(err);
}
