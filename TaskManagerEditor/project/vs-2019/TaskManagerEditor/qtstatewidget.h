#pragma once

#include <QWidget>
#include "ui_QTStateWidget.h"

class QTStateWidget : public QWidget
{
    Q_OBJECT

public:
    QTStateWidget(QWidget *parent = Q_NULLPTR);
    ~QTStateWidget();

private:
    Ui::QTStateWidget ui;
};
