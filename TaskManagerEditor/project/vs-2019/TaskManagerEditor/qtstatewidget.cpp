#include "QTStateWidget.h"
#include <QTaskWidget.h>

QTStateWidget::QTStateWidget(TaskManager::StateDto* state, QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

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
    for (auto task : tasks)
    {
        layout->addWidget(new QTaskWidget(*task, ui.scrollAreaWidgetContents));
    }

    //auto c = ui.scrollArea->findChild<QWidget *>("scrollAreaWidgetContents")->children();
}

void QTStateWidget::clearState()
{

    QList<QTaskWidget*> widgets = ui.scrollAreaWidgetContents->findChildren<QTaskWidget*>();

    foreach(QWidget * widget, widgets)
    {
        delete widget;
    }
}
