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
	logo = new QGraphicsView(filmoraClass);
	logo->setObjectName(QString::fromUtf8("logo"));
	logo->setGeometry(QRect(0, 0, 64, 24));

	fileMenuButton = new QPushButton(filmoraClass);
	fileMenuButton->setObjectName(QString::fromUtf8("fileMenuButton"));
	fileMenuButton->setGeometry(QRect(64, 0, 64, 24));
	fileMenu = new QMenu();
	QAction *newProjectAction = new QAction(fileMenu);
	fileMenu->addAction(newProjectAction);
	fileMenuButton->setMenu(fileMenu);
	//fileMenuButton->setStyleSheet("QPushButton::menu-indicator{image:None;}");

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

	retranslateUi(filmoraClass);
	QObject::connect(closeButton, SIGNAL(clicked()), filmoraClass, SLOT(close()));
	QObject::connect(maxButton, SIGNAL(clicked()), filmoraClass, SLOT(showMaximized()));
	QObject::connect(minButton, SIGNAL(clicked()), filmoraClass, SLOT(showMinimized()));

	QMetaObject::connectSlotsByName(filmoraClass);
} // setupUi

void Ui_filmoraClass::retranslateUi(QWidget *filmoraClass)
{
	filmoraClass->setWindowTitle(QApplication::translate("filmoraClass", "filmora", nullptr));
	fileMenuButton->setText(QApplication::translate("filmoraClass", "\346\226\207\344\273\266", nullptr));
	editMenuButton->setText(QApplication::translate("filmoraClass", "\347\274\226\350\276\221", nullptr));
	cutMenuButton->setText(QApplication::translate("filmoraClass", "\345\211\252\350\276\221", nullptr));
	displayMenuButton->setText(QApplication::translate("filmoraClass", "\346\230\276\347\244\272", nullptr));
	helpMenuButton->setText(QApplication::translate("filmoraClass", "\345\270\256\345\212\251", nullptr));
	label->setText(QApplication::translate("filmoraClass", "\346\234\252\345\221\275\345\220\215: 00:00:00:00", nullptr));
	closeButton->setText(QApplication::translate("filmoraClass", "X", nullptr));
	maxButton->setText(QApplication::translate("filmoraClass", "\345\217\243", nullptr));
	minButton->setText(QApplication::translate("filmoraClass", "-", nullptr));
} // retranslateUi