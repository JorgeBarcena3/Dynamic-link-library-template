#include <QTStateWidget.h>
#include <QTaskWidget.h>
#include <TaskManagerEditor.h>

#include <PanelDto.hpp>
#include <QtWidgets\qinputdialog.h>

QTStateWidget::QTStateWidget(TaskManager::StateDto* state, QWidget* parent)
    : QWidget(parent)
{

    panelManager = (TaskManager::PanelManager*)TaskManager::Aplication::instance()->getComponent("PanelManager");

    ui.setupUi(this);

    connect(ui.edit_state_name, &QAbstractButton::clicked, this, &QTStateWidget::change_state_name);
    connect(ui.add_task_to_state, &QAbstractButton::clicked, this, &QTStateWidget::add_task_to_state);
    connect(ui.remove_panel, &QAbstractButton::clicked, this, &QTStateWidget::remove_state);

    ui.titulo_estado->setText(state->getTitle().c_str());

    refreshPanel(state);
}

QTStateWidget::~QTStateWidget()
{
}

void QTStateWidget::refreshPanel(TaskManager::StateDto* state)
{
    clearState();

    auto tasks = state->getTasks();

    auto layout = ui.scrollAreaWidgetContents->findChild<QVBoxLayout*>("verticalLayout");
    for (auto tasks : tasks)
    {
        layout->addWidget(new QTaskWidget(*tasks, ui.scrollAreaWidgetContents));
    }

}

void QTStateWidget::add_task_to_state()
{

    QString name = createDialog("New Task", "Name: ");
    QString assign = createDialog("New Task", "Assigned: ");
    QString desc = createMultiLineDialog("New Task", "Description: ");

    auto err = panelManager->addTaskToState
    (
        ui.titulo_estado->text().toUtf8().constData(),
        name.toUtf8().constData(),
        desc.toUtf8().constData(),
        assign.toUtf8().constData()
    );

    TaskManagerEditor::getInstance()->showError(err);

    refreshPanel((panelManager->getStatesFromCurrentPanel(ui.titulo_estado->text().toUtf8().constData()).getReturnObj()));



}

void QTStateWidget::change_state_name()
{
    bool ok;

    QString old_title(ui.titulo_estado->text());

    QString text = QInputDialog::getText(
        this,
        QString("Change state name"),
        QString("New name (" + old_title + "):"),
        QLineEdit::Normal,
        "",
        &ok);

    if (ok && !text.isEmpty())
    {
        auto err = panelManager->changeStatusName(old_title.toUtf8().constData(), text.toUtf8().constData());

        if (err.itsOk())
            ui.titulo_estado->setText(text);
        else
            TaskManagerEditor::getInstance()->showError(err);

    }
}

void QTStateWidget::remove_state()
{
    TaskManagerEditor::getInstance()->showError(panelManager->removeTask(ui.titulo_estado->text().toUtf8().constData()));
    TaskManagerEditor::getInstance()->refreshBoard();

}

QString QTStateWidget::createDialog(QString title, QString subtitle)
{
    bool ok;

    QString text = QInputDialog::getText(
        this,
        QString(title),
        QString(subtitle),
        QLineEdit::Normal,
        "",
        &ok);

    if (ok && !text.isEmpty())
    {
        return text;
    }
    else
    {
        return "Default";
    }
}

QString QTStateWidget::createMultiLineDialog(QString title, QString subtitle)
{

    bool ok;

    QString text = QInputDialog::getMultiLineText(
        this,
        title,
        subtitle,
        "",
        &ok);

    if (ok && !text.isEmpty())
    {
        return text;
    }
    else
    {
        return "Default";
    }
}

void QTStateWidget::clearState()
{

    QList<QTaskWidget*> widgets = ui.scrollAreaWidgetContents->findChildren<QTaskWidget*>();

    foreach(QWidget * widget, widgets)
    {
        delete widget;
    }
}
