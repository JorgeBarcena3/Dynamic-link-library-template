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


#ifndef QTSTATEWIDGET_HEADER
#define QTSTATEWIDGET_HEADER

#include <QWidget>
#include "ui_QTStateWidget.h"
#include <StateDto.hpp>
#include <PanelManager.hpp>

/**
* Muestra la informacion de un estado por pantalla
*/
class QTStateWidget : public QWidget
{
    Q_OBJECT

private:

    Ui::QTStateWidget ui; ///< UI del widget

    TaskManager::PanelManager * panelManager; ///< Referencia al componente de la aplicacion


public:

    /**
    * Constructor por defecto
    */
    QTStateWidget(TaskManager::StateDto * state, QWidget* parent = Q_NULLPTR);

    /**
    * Destructor  por defecto
    */
    ~QTStateWidget();

    /**
    * Actualiza la informacion del panel
    */
    void refreshPanel(TaskManager::StateDto * state);

public slots:

    /**
    * Añade una tare al estado
    */
    void add_task_to_state();

    /**
    * Cambia el nombre del estado
    */
    void change_state_name();

    /**
    * Elimina el estado
    */
    void remove_state();

private:

    /**
    * Limpia el estado
    */
    void clearState();

    /**
    * Crea un dialogo
    */
    QString createDialog(QString title, QString subtitle);

    /**
    * Crea un dialogo de varias lineas
    */
    QString createMultiLineDialog(QString title, QString subtitle);


};

#endif
