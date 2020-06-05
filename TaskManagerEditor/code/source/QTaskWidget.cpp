#include <QTaskWidget.h>
#include <TaskManagerEditor.h>

#include <time.h>
#include <QtWidgets\qinputdialog.h>
#include <StateDto.hpp>
#include <PanelDto.hpp>
#include <QMessageBox>

QTaskWidget::QTaskWidget(TaskManager::TaskDto& task, QWidget* parent)
    : QWidget(parent), currentTask(&task)
{

    manager = (TaskManager::PanelManager*)TaskManager::Aplication::instance()->getComponent("PanelManager");

    ui.setupUi(this);

    connectSignals();

    currentTask = &task;

    refresh_info();

}

QTaskWidget::~QTaskWidget()
{
}

void QTaskWidget::edit_task_title(bool triggered)
{
    auto name = createDialog("Edit Task", "New Name:");
    currentTask->setTitle(name.toUtf8().constData());
    refresh_info();
}

void QTaskWidget::change_to_panel(bool triggered)
{
    QStringList items;

    auto panels = manager->getStatesFromPanel(manager->getCurrentPanel()->getTitle()).getReturnObj();
    for (auto panel : panels)
    {
        items << QString(panel->getTitle().c_str());
    }


    bool ok;
    QString item = QInputDialog::getItem(
        this,
        "Change task",
        "New state: ",
        items,
        0,
        false,
        &ok
    );

    if (ok && !item.isEmpty())
    {
        manager->changeTaskToState(currentTask->getStateDto().getTitle(), currentTask->getTitle(), item.toUtf8().constData());
        TaskManagerEditor::getInstance()->refreshBoard();

    }
        

}

void QTaskWidget::remove_task(bool triggered)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete", "Do you want to remove the task?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        manager->removeTaskofState(currentTask->getStateDto().getTitle(), currentTask->getTitle());
        delete this;
    }
}

void QTaskWidget::edit_assigned(bool triggered)
{
    currentTask->setAssigned( createDialog("Edit task", "New Assigned").toUtf8().constData() );
    refresh_info();
}

void QTaskWidget::edit_description(bool triggered)
{
    currentTask->setDescription(createMultiLineDialog("Edit task", "New description").toUtf8().constData());
    refresh_info();
}

void QTaskWidget::refresh_info()
{
    ui.task_box->setTitle(currentTask->getTitle().c_str());
    ui.assigned->setText(currentTask->getAssigned().c_str());
    ui.desc->setText(currentTask->getDescription().c_str());
    ui.fecha->setText(currentTask->getCreationDateString().c_str());
}

void QTaskWidget::connectSignals()
{
    connect(ui.edit_task_title,  &QAbstractButton::clicked, this, &QTaskWidget::edit_task_title);
    connect(ui.change_state,     &QAbstractButton::clicked, this, &QTaskWidget::change_to_panel);
    connect(ui.delete_task,      &QAbstractButton::clicked, this, &QTaskWidget::remove_task);
    connect(ui.edit_assign,      &QAbstractButton::clicked, this, &QTaskWidget::edit_assigned);
    connect(ui.edit_description, &QAbstractButton::clicked, this, &QTaskWidget::edit_description);

}


QString QTaskWidget::createDialog(QString title, QString subtitle)
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

QString QTaskWidget::createMultiLineDialog(QString title, QString subtitle)
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

