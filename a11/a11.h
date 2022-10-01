#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_a11.h"

class a11 : public QMainWindow
{
    Q_OBJECT

public:
    a11(QWidget *parent = Q_NULLPTR);

private:
    Ui::a11Class ui;
};
