#include "qtpanelwidget.h"
#include "qtstatewidget.h"
#include <PanelDto.hpp>
#include "../../../code/headers/TaskManagerEditor.h"
#include <ui_TaskManagerEditor.h>
#include <QtWidgets\qinputdialog.h>


QTPanelWidget::QTPanelWidget(QObject *parent)
{
    panelManager = (TaskManager::PanelManager*)TaskManager::Aplication::instance()->getComponent("PanelManager");

}

void QTPanelWidget::connectSignals(Ui::TaskManagerEditorClass* ui)
{
    connect(ui->actionNew_Panel, &QAction::triggered, this, &QTPanelWidget::addPanel);
    connect(this, &QTabWidget::tabBarClicked, this, &QTPanelWidget::changePanel);

}

QTPanelWidget::~QTPanelWidget()
{
}

void QTPanelWidget::addPanel(bool triggered)
{

    bool ok;

    QString text = QInputDialog::getText(
        this,
        tr("New Panel"),
        tr("Panel name:"),
        QLineEdit::Normal,
        "",
        &ok);

    if (ok && !text.isEmpty())
    {
        auto err = panelManager->createPanel(text.toUtf8().constData());

        if (err.itsOk())
        {
            
            setCurrentTab(createTab(text));
        }
        else
            showError(err);

    }

}

void QTPanelWidget::refreshData()
{
    
    removeTabs();

    createTabsFromInfo();

}

void QTPanelWidget::setCurrentTab(int index)
{
    setCurrentIndex(index);
}

void QTPanelWidget::removeTabs()
{
    while (count() > 0)
    {
        removeTab(0);
    }
}

void QTPanelWidget::createTabsFromInfo()
{
    auto panels = panelManager->getAllPanels();

    for (auto panel : panels.getReturnObj())
    {
        createTab(panel->getTitle().c_str());
    }
}

int QTPanelWidget::createTab(QString name)
{
    
    return addTab(new QTStateWidget(name, this), name);

}

void QTPanelWidget::showError(TaskManager::TaskStatus_b err)
{
    TaskManagerEditor::getInstance()->showError(err);

}

void QTPanelWidget::changePanel(int index)
{
    QTStateWidget * currentState = (QTStateWidget*)widget(index);
    panelManager->changeToPanel(currentState->getName().toUtf8().constData());
}
