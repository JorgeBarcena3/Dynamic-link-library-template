#pragma once

#include <QWidget>
#include "ui_QTaskWidget.h"

class QTaskWidget : public QWidget
{
    Q_OBJECT

public:
    QTaskWidget(QWidget *parent = Q_NULLPTR);
    ~QTaskWidget();

private:
    Ui::QTaskWidget ui;
};
