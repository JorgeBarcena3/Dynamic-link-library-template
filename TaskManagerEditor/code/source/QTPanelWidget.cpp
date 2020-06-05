#include <QTPanelWidget.h>
#include <QTStateWidget.h>

#include <PanelDto.hpp>
#include <QtWidgets\qinputdialog.h>

QTPanelWidget::QTPanelWidget(QString _name, QWidget* parent)
    : QWidget(parent), name(_name)
{
    ui.setupUi(this);

    connect(ui.next_panel, &QAbstractButton::clicked, this, &QTPanelWidget::nextState);
    connect(ui.previous_Panel, &QAbstractButton::clicked, this, &QTPanelWidget::previusState);
    connect(ui.add_panel, &QAbstractButton::clicked, this, &QTPanelWidget::add_panel);

    panelManager = (TaskManager::PanelManager*)TaskManager::Aplication::instance()->getComponent("PanelManager");

    stateIndex = 0;

    refreshPanel();


}

QTPanelWidget::~QTPanelWidget()
{
}

void QTPanelWidget::refreshPanel()
{

    clearPanel();

    auto states = panelManager->getStatesFromPanel(name.toUtf8().constData()).getReturnObj();

    max_states = states.size() - 1;

    int max_per_page = 3;
    int fixed_index = stateIndex;
    std::vector<int> printed;
    

    for (size_t i = 0; i < max_per_page && std::find(printed.begin(), printed.end(), fixed_index) == printed.end(); i++)
    {
        ui.horizontalLayout->addWidget(new QTStateWidget(states[fixed_index], this));
        printed.push_back(fixed_index);
        fixed_index = (fixed_index + 1) > max_states ? 0 : fixed_index + 1;
    }
    
    
}

void QTPanelWidget::clearPanel()
{
    while (QLayoutItem* item = ui.horizontalLayout->takeAt(0))
    {
        if (QWidget* widget = item->widget())
            widget->deleteLater();

    }
}

void QTPanelWidget::nextState()
{
    stateIndex = (stateIndex + 1) > max_states ? 0 : stateIndex + 1;
    refreshPanel();
}

void QTPanelWidget::previusState()
{
    stateIndex = (stateIndex - 1) < 0 ? max_states : stateIndex - 1;
    refreshPanel();
}

void QTPanelWidget::add_panel()
{
    bool ok;

    QString text = QInputDialog::getText(
        this,
        QString("New Panel"),
        QString("New panel name"),
        QLineEdit::Normal,
        "",
        &ok);

    if (ok && !text.isEmpty())
    {
        panelManager->addState(text.toUtf8().constData());
        refreshPanel();

    }

}


