#pragma once

#include <QWidget>
#include "ui_qtstatewidget.h"

class QTStateWidget : public QWidget
{
    Q_OBJECT

private:

    QString name;

public:

    QTStateWidget(QString _name, QWidget *parent = Q_NULLPTR);

    ~QTStateWidget();

    inline QString getName() { return name; };

private:

    Ui::QTStateWidget ui;
};
