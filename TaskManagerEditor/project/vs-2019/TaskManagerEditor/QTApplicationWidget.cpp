#include "QTApplicationWidget.h"
#include "QTPanelWidget.h"
#include <PanelDto.hpp>
#include "../../../code/headers/TaskManagerEditor.h"
#include <ui_TaskManagerEditor.h>
#include <QtWidgets\qinputdialog.h>


QTApplicationWidget::QTApplicationWidget(QObject* parent)
{
    panelManager = (TaskManager::PanelManager*)TaskManager::Aplication::instance()->getComponent("PanelManager");

}

void QTApplicationWidget::connectSignals(Ui::TaskManagerEditorClass* ui)
{
    connect(ui->actionNew_Panel, &QAction::triggered, this, &QTApplicationWidget::addPanel);
    connect(this, &QTabWidget::tabBarClicked, this, &QTApplicationWidget::changePanel);
    connect(ui->actionEdit_Panel, &QAction::triggered, this, &QTApplicationWidget::editPanel);

}

QTApplicationWidget::~QTApplicationWidget()
{
}

void QTApplicationWidget::addPanel(bool triggered)
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

void QTApplicationWidget::refreshData()
{

    removeTabs();

    createTabsFromInfo();

}

void QTApplicationWidget::editPanel(bool triggered)
{
    bool ok;

    auto old_title = QString(panelManager->getCurrentPanel()->getTitle().c_str());

    QString text = QInputDialog::getText(
        this,
        QString("Change panel name"),
        QString("New name (" + old_title + "):"),
        QLineEdit::Normal,
        "",
        &ok);

    if (ok && !text.isEmpty())
    {
        panelManager->getCurrentPanel()->setTitle(text.toUtf8().constData());

       
        TaskManagerEditor::getInstance()->refreshBoard();


    }
}

void QTApplicationWidget::setCurrentTab(int index)
{
    panelManager->changeToPanel(index);
    setCurrentIndex(index);
}

void QTApplicationWidget::removeTabs()
{
    while (count() > 0)
    {
        removeTab(0);
    }
}

void QTApplicationWidget::createTabsFromInfo()
{
    auto panels = panelManager->getAllPanels();

    for (auto panel : panels.getReturnObj())
    {
        panelManager->changeToPanel(panel->getTitle());

        createTab(panel->getTitle().c_str());
    }

    panelManager->changeToPanel(0);

}

int QTApplicationWidget::createTab(QString name)
{

    return addTab(new QTPanelWidget(name, this), name);

}

void QTApplicationWidget::showError(TaskManager::TaskStatus_b err)
{
    TaskManagerEditor::getInstance()->showError(err);

}

void QTApplicationWidget::changePanel(int index)
{
    QTPanelWidget* currentState = (QTPanelWidget*)widget(index);
    panelManager->changeToPanel(currentState->getName().toUtf8().constData());
    //TaskManagerEditor::getInstance()->refreshBoard();

}
