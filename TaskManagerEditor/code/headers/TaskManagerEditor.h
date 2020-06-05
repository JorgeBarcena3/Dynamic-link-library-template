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


#ifndef TASKMANAGEREDITOR_HEADER
#define TASKMANAGEREDITOR_HEADER

#include <MenuActions.h>

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerEditor.h"
#include <TaskStatus.hpp>

/**
* Pantalla principal de la aplicacion
*/
class TaskManagerEditor : public QMainWindow
{
    Q_OBJECT

private:

    static TaskManagerEditor* instance; ///< Instancia de la aplicacion

    Ui::TaskManagerEditorClass ui; ///< UI de la aplicacion

    MenuActions menuActions; ///< Acciones del menu

public:

    /**
    * Devuelve la instancia de la aplicacion
    */
    static TaskManagerEditor* getInstance()
    {

        return instance;
    }

public:

    /**
    * Constructor por defecto de la aplicacion
    */
    TaskManagerEditor(QWidget* parent = Q_NULLPTR);

    /**
    * Muestra un error por pantalla
    */
    void showError(TaskManager::TaskStatus_b a);

    /**
    * Actualiza el tablero
    */
    void refreshBoard();

    /**
    * Devuelve la UI de la pantalla principal
    */
    inline Ui::TaskManagerEditorClass* getUI()
    {
        return &ui;
    }

};

#endif