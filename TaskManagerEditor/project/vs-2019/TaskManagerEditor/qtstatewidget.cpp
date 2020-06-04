#include "qtstatewidget.h"

QTStateWidget::QTStateWidget(QString _name, QWidget *parent)
    : QWidget(parent), name(_name)
{
    ui.setupUi(this);
}

QTStateWidget::~QTStateWidget()
{
}
