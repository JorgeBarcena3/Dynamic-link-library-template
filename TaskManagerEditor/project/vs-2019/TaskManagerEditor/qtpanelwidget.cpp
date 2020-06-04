#include "QTPanelWidget.h"

QTPanelWidget::QTPanelWidget(QString _name, QWidget *parent)
    : QWidget(parent), name(_name)
{
    ui.setupUi(this);
}

QTPanelWidget::~QTPanelWidget()
{
}


