#pragma once

#include <QWidget>
#include "ui_QTPanelWidget.h"

class QTPanelWidget : public QWidget
{
    Q_OBJECT

private:

    QString name;

public:

    QTPanelWidget(QString name, QWidget *parent = Q_NULLPTR);

    ~QTPanelWidget();

    inline QString getName() { return name; };

private:
    Ui::QTPanelWidget ui;
};
