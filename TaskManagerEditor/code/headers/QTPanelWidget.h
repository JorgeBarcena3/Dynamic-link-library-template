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



#ifndef QTPANELWIDGET_HEADER
#define QTPANELWIDGET_HEADER

#include <QWidget>
#include "ui_QTPanelWidget.h"
#include <PanelManager.hpp>

/**
* Administra la informacion de un panel por pantalla
*/
class QTPanelWidget : public QWidget
{
    Q_OBJECT

private:

    QString name; ///< Nombre del panel

    TaskManager::PanelManager* panelManager; ///< Referencia a un componente de la aplicacion

    Ui::QTPanelWidget ui; ///< UI del widget

    int stateIndex; ///< Indice actual

    int max_states; ///< Numero maximo de estados


public:

    /**
    * Constructor por defecto
    */
    QTPanelWidget(QString name, QWidget *parent = Q_NULLPTR);

    /**
    * Destructor por defecto
    */
    ~QTPanelWidget();

    /**
    * Devuelve el nombre del panel
    */
    inline QString getName() { return name; };

    /**
    * Refresca un panel
    */
    void refreshPanel();

public slots:

    /**
    * Limipia el panel
    */
    void clearPanel();

    /**
    * SIguiente estado
    */
    void nextState();

    /**
    * Estado anterior
    */
    void previusState();

    /**
    * Añade un panel nuevo
    */
    void add_panel();

};

#endif
