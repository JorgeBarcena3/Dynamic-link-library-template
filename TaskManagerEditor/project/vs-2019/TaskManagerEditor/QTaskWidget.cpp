#include "QTaskWidget.h"
#include <time.h>

QTaskWidget::QTaskWidget(TaskManager::TaskDto& task, QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    setInfo(task);
}

QTaskWidget::~QTaskWidget()
{
}

void QTaskWidget::setInfo(TaskManager::TaskDto& task)
{
    ui.task_box->setTitle(task.getTitle().c_str());
    ui.assigned->setText(task.getAssigned().c_str());
    ui.desc->setText(task.getDescription().c_str());
    ui.fecha->setText(task.getCreationDateString().c_str());
}
