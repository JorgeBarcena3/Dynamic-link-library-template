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



#ifndef QTTASKWIDGET_HEADER
#define QTTASKWIDGET_HEADER

#include <QWidget>
#include "ui_QTaskWidget.h"
#include <TaskDto.hpp>
#include <PanelManager.hpp>

/**
* Muestra la informacion de una tarea por la pantalla
*/
class QTaskWidget : public QWidget
{
    Q_OBJECT

private:

    Ui::QTaskWidget ui; ///< UI del widget

    TaskManager::TaskDto * currentTask; ///< Tarea actual

    TaskManager::PanelManager * manager; ///< Referencia al componente de la aplicacion


public:

    /**
    * Constructor por defecto
    */
    QTaskWidget(TaskManager::TaskDto & tasks, QWidget *parent = Q_NULLPTR);

    /**
    * Destructor por defecto
    */
    ~QTaskWidget();

public slots:

    /**
    * Edita el titulo de una tarea
    */
    void edit_task_title(bool triggered);

    /**
    * Cambia de panel una tarea
    */
    void change_to_panel(bool triggered);

    /**
    * Elimina una tarea
    */
    void remove_task(bool triggered);

    /**
    * Determina a quien se le asigna una tarea
    */
    void edit_assigned(bool triggered);

    /**
    * Edita una descripcion
    */
    void edit_description(bool triggered);

private:

    /**
    * Actualiza la informacion del widget
    */
    void refresh_info();

    /**
    * Conecta las signals del widget
    */
    void connectSignals();

    /**
    * Crea un dialog en la pantalla
    */
    QString createDialog(QString title, QString subtitle);

    /**
    * Crea un dialog multiline en la pantalla
    */
    QString createMultiLineDialog(QString title, QString subtitle);

};

#endif