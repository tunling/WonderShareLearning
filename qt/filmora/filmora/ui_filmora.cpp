#pragma execution_character_set("utf-8")
#include "ui_filmora.h"
void Ui_filmoraClass::setupUi(QWidget *filmoraClass)
{
	if (filmoraClass->objectName().isEmpty())
		filmoraClass->setObjectName(QString::fromUtf8("filmoraClass"));
	filmoraClass->setWindowModality(Qt::NonModal);
	filmoraClass->setEnabled(true);
	filmoraClass->resize(1920, 1080);
	filmoraClass->setMaximumSize(QSize(16777215, 16777215));
	filmoraClass->setContextMenuPolicy(Qt::DefaultContextMenu);
	setupMenuUi(filmoraClass);
	retranslateUi(filmoraClass);
	QMetaObject::connectSlotsByName(filmoraClass);
} // setupUi

void Ui_filmoraClass::setupMenuUi(QWidget *filmoraClass)
{
	logo = new QGraphicsView(filmoraClass);
	logo->setObjectName(QString::fromUtf8("logo"));
	logo->setGeometry(QRect(0, 0, 64, 24));
	fileMenuButton = new QPushButton(filmoraClass);
	fileMenuButton->setObjectName(QString::fromUtf8("fileMenuButton"));
	fileMenuButton->setGeometry(QRect(64, 0, 64, 24));
	fileMenu = new QMenu();
	newProjectAction = new QAction(fileMenu);
	fileMenu->addAction(newProjectAction);
	fileMenuButton->setMenu(fileMenu);
	fileMenuButton->setStyleSheet("QPushButton::menu-indicator{image:None;}");

	editMenuButton = new QPushButton(filmoraClass);
	editMenuButton->setObjectName(QString::fromUtf8("editMenuButton"));
	editMenuButton->setGeometry(QRect(128, 0, 64, 24));
	cutMenuButton = new QPushButton(filmoraClass);
	cutMenuButton->setObjectName(QString::fromUtf8("cutMenuButton"));
	cutMenuButton->setGeometry(QRect(192, 0, 64, 24));
	displayMenuButton = new QPushButton(filmoraClass);
	displayMenuButton->setObjectName(QString::fromUtf8("displayMenuButton"));
	displayMenuButton->setGeometry(QRect(256, 0, 64, 24));
	helpMenuButton = new QPushButton(filmoraClass);
	helpMenuButton->setObjectName(QString::fromUtf8("helpMenuButton"));
	helpMenuButton->setGeometry(QRect(320, 0, 64, 24));
	label = new QLabel(filmoraClass);
	label->setObjectName(QString::fromUtf8("label"));
	label->setGeometry(QRect(0, 0, 1920, 24));
	label->setTextFormat(Qt::AutoText);
	label->setAlignment(Qt::AlignCenter);
	closeButton = new QPushButton(filmoraClass);
	closeButton->setObjectName(QString::fromUtf8("closeButton"));
	closeButton->setGeometry(QRect(1888, 0, 32, 24));
	maxButton = new QPushButton(filmoraClass);
	maxButton->setObjectName(QString::fromUtf8("maxButton"));
	maxButton->setGeometry(QRect(1856, 0, 32, 24));
	minButton = new QPushButton(filmoraClass);
	minButton->setObjectName(QString::fromUtf8("minButton"));
	minButton->setGeometry(QRect(1824, 0, 32, 24));
	label->raise();
	logo->raise();
	fileMenuButton->raise();
	editMenuButton->raise();
	cutMenuButton->raise();
	displayMenuButton->raise();
	helpMenuButton->raise();
	closeButton->raise();
	maxButton->raise();
	minButton->raise();

	QObject::connect(closeButton, SIGNAL(clicked()), filmoraClass, SLOT(close()));
	QObject::connect(maxButton, SIGNAL(clicked()), filmoraClass, SLOT(showMaximized()));
	QObject::connect(minButton, SIGNAL(clicked()), filmoraClass, SLOT(showMinimized()));
} // setupUi

void Ui_filmoraClass::retranslateUi(QWidget *filmoraClass)
{
	filmoraClass->setWindowTitle(QApplication::translate("filmoraClass", "filmora", nullptr));
	fileMenuButton->setText(QApplication::translate("filmoraClass", "ÎÄ¼þ", nullptr));
	newProjectAction->setText(QApplication::translate("filmoraClass", "new project", nullptr));
	editMenuButton->setText(QApplication::translate("filmoraClass", "±à¼­", nullptr));
	cutMenuButton->setText(QApplication::translate("filmoraClass", "¼ô¼­", nullptr));
	displayMenuButton->setText(QApplication::translate("filmoraClass", "ÏÔÊ¾", nullptr));
	helpMenuButton->setText(QApplication::translate("filmoraClass", "°ïÖú", nullptr));
	label->setText(QApplication::translate("filmoraClass", "Î´ÃüÃû: 00:00:00:00", nullptr));
	closeButton->setText(QApplication::translate("filmoraClass", "X", nullptr));
	maxButton->setText(QApplication::translate("filmoraClass", "¿Ú", nullptr));
	minButton->setText(QApplication::translate("filmoraClass", "-", nullptr));
} // retranslateUi