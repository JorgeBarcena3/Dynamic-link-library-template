// Author: Jorge Bárcena Lumbreras

// © Copyright (C) 2020  Jorge Bárcena Lumbreras

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.



#ifndef MENUACTIONS_HEADER
#define MENUACTIONS_HEADER

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

/**
* Maneja todas las acciones generales que se pueden hacer desde la barra de tareas
*/
class MenuActions : public QWidget
{
    Q_OBJECT

private:

    
    TaskManager::PanelLoader   * panelLoader;    ///< Referencia a los componentes de la aplicacion
    TaskManager::PanelManager  * manager;        ///< Referencia a los componentes de la aplicacion
    TaskManager::PanelExporter * panelExporter;  ///< Referencia a los componentes de la aplicacion

    QString defaultPath; ///< Path donde el usuario ha decidido guardar los documentos

public:

    /**
    * Constructor del menu
    */
    MenuActions(QMainWindow * parent, Ui::TaskManagerEditorClass * ui);

    /**
    * Desctructor por defecto de la aplicacion
    */
    ~MenuActions();

    /**
    * Activan los botones de la barra de tareas
    */
    void activeFileButtons(Ui::TaskManagerEditorClass* ui);

    /**
    * Desactivan los botones de la barra de tareas
    */
    void desactiveFileButtons(Ui::TaskManagerEditorClass* ui);

public slots:

    /**
    * Se ejecuta al realizar la accion (QT) de cargar
    */
    void load(bool triggered);

    /**
    * Se ejecuta al realizar la accion (QT) de guardar
    */
    void save(bool triggered);

    /**
    * Se ejecuta al realizar la accion (QT) de guardar como
    */
    void saveAs(bool triggered);

    /**
    * Se ejecuta al realizar la accion (QT) de exportar como XML
    */
    void exportXML(bool triggered);

    /**
    * Se ejecuta al realizar la accion (QT) de importar XML
    */
    void importXML(bool triggered);

    /**
    * Se ejecuta al realizar la accion (QT) de abrir github
    */
    void openGitHub(bool triggered);

    /**
    * Se ejecuta al realizar la accion (QT) de abrir Linkedin
    */
    void openLinkedin(bool triggered);

    /**
    * Se ejecuta al realizar la accion (QT) de ejecutar un comando de lua
    */
    void executeLuaCommand(bool triggered);

    /**
    * Se ejecuta al realizar la accion (QT) de ejecutar un archivo de lua
    */
    void executeLuaFile(bool triggered);

    /**
    * Se ejecuta al realizar la accion (QT) de crear un archivo nuevo
    */
    void newFile(bool triggered);

    /**
    * Se ejecuta al realizar la accion (QT) de cerrar la app
    */
    void closeApplication();

    /**
    * Se ejecuta al realizar la accion (QT) de eliminar un panel
    */
    void removePanel(bool triggered);

private:
    

    /**
    * Ejecuta un codigo de lua
    */
    void executeLuaCode(QString code);

    /**
    * Muesrta el error por pantalla
    */
    void checkError(TaskManager::TaskStatus_b err);

};

#endif