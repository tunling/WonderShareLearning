#pragma once

#include <QtWidgets/QWidget>
#include "ui_filmora.h"

class filmora : public QWidget
{
	Q_OBJECT

public:
	filmora(QWidget *parent = Q_NULLPTR);

private:
	Ui::filmoraClass ui;
};
