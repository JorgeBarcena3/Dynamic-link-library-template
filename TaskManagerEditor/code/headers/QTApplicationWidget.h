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



#ifndef QTAPLICATIONWIDGET_HEADER
#define QTAPLICATIONWIDGET_HEADER

#include <qtabwidget.h>
#include <PanelManager.hpp>

namespace Ui
{
    class TaskManagerEditorClass;
}

/**
* Maneja todas las acciones generales que se pueden hacer en cuanto a los paneles de la aplicacion
*/
class QTApplicationWidget : public QTabWidget
{

private:

    TaskManager::PanelManager* panelManager; ///< Referencia al componente de la aplicacion

public:

    /**
    * Constructor por defecto
    */
    QTApplicationWidget(QObject* parent);

    /**
    * Destructor por defecto
    */
    ~QTApplicationWidget();

    /**
    * Actualiza todos los paneles
    */
    void refreshData();

    /**
    * Conecta las señales de este widget
    */
    void connectSignals(Ui::TaskManagerEditorClass* ui);

public slots:

    /**
    * Añade un panel
    */
    void addPanel(bool triggered);

    /**
    * Edita el nombre de un panel
    */
    void editPanel(bool triggered);

private:

    /**
    * Determina la tab actual
    */
    void setCurrentTab(int index);

    /**
    * Elimina una tab
    */
    void removeTabs();

    /**
    * Crea las tabs segun la info de los datos cargados
    */
    void createTabsFromInfo();

    /**
    * Crea un tab nueva
    */
    int createTab(QString name);

    /**
    * Muestra un error por pantalla
    */
    void showError(TaskManager::TaskStatus_b err);

    /**
    * Cambia de panel
    */
    void changePanel(int index);

};

#endif