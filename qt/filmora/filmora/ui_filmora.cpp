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
	//�ļ��˵���ť
	fileMenuButton = new QPushButton(filmoraClass);
	fileMenuButton->setObjectName(QString::fromUtf8("fileMenuButton"));
	fileMenuButton->setGeometry(QRect(64, 0, 64, 24));
	fileMenu = new QMenu();
	newProjectMenu = new QMenu(fileMenu);	//�½���Ŀ
	sixteenColonNine = new QAction(newProjectMenu);
	oneColonone = new QAction(newProjectMenu);
	nineColonSixteen = new QAction(newProjectMenu);
	fourColonThree = new QAction(newProjectMenu);
	threeColonFour = new QAction(newProjectMenu);
	twentyoneColonNine = new QAction(newProjectMenu);
	newProjectMenu->addAction(sixteenColonNine);
	newProjectMenu->addAction(oneColonone);
	newProjectMenu->addAction(nineColonSixteen);
	newProjectMenu->addAction(fourColonThree);
	newProjectMenu->addAction(threeColonFour);
	newProjectMenu->addAction(twentyoneColonNine);
	fileMenu->addMenu(newProjectMenu);
	openProjectAction = new QAction(fileMenu);	//����Ŀ
	fileMenu->addAction(openProjectAction);
	openLastProjectsMenu = new QMenu(fileMenu);	//�����ʹ�õ�����
	openLastProjectsMenu->addActions(lastProjectActions);
	openLastProjectsMenu->setDisabled(true);
	fileMenu->addMenu(openLastProjectsMenu);
	fileMenu->addSeparator();
	importMenu = new QMenu(fileMenu);	//����˵�
	importMediaAction = new QAction(importMenu);
	importFromDirAction = new QAction(importMenu);
	importFromCorPAction = new QAction(importMenu);
	importFromHarmlessAction = new QAction(importMenu);
	importMenu->addAction(importMediaAction);
	importMenu->addAction(importFromDirAction);
	importMenu->addAction(importFromCorPAction);
	importMenu->addAction(importFromHarmlessAction);
	fileMenu->addMenu(importMenu);
	recordMenu = new QMenu(fileMenu);	//¼�Ʋ˵�
	recordCameraAction = new QAction(recordMenu);
	recordPCAction = new QAction(recordMenu);
	recordOffscreenAction = new QAction(recordMenu);
	recordMenu->addAction(recordCameraAction);
	recordMenu->addAction(recordPCAction);
	recordMenu->addAction(recordOffscreenAction);
	fileMenu->addMenu(recordMenu);
	//
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
	fileMenuButton->setText(QApplication::translate("filmoraClass", "�ļ�", nullptr));
	newProjectMenu->setTitle(QApplication::translate("filmoraClass", "�½���Ŀ", nullptr));
	sixteenColonNine->setText(QApplication::translate("filmoraClass", "16 : 9", nullptr));
	oneColonone->setText(QApplication::translate("filmoraClass", "1 : 1", nullptr));
	nineColonSixteen->setText(QApplication::translate("filmoraClass", "9 : 16", nullptr));
	fourColonThree->setText(QApplication::translate("filmoraClass", "4 : 3", nullptr));
	threeColonFour->setText(QApplication::translate("filmoraClass", "3 : 4", nullptr));
	twentyoneColonNine->setText(QApplication::translate("filmoraClass", "21 : 9", nullptr));
	openProjectAction->setText(QApplication::translate("filmoraClass", "����Ŀ", nullptr));
	openLastProjectsMenu->setTitle(QApplication::translate("filmoraClass", "�����ʹ�õ�����", nullptr));
	importMenu->setTitle(QApplication::translate("filmoraClass", "����", nullptr));
	importMediaAction->setText(QApplication::translate("filmoraClass", "����ý��", nullptr));
	importFromDirAction->setText(QApplication::translate("filmoraClass", "�����ļ���", nullptr));
	importFromCorPAction->setText(QApplication::translate("filmoraClass", "��������ֻ�����", nullptr));
	importFromHarmlessAction->setText(QApplication::translate("filmoraClass", "ʹ��������й��ߵ���", nullptr));
	recordMenu->setTitle(QApplication::translate("filmoraClass", "¼��", nullptr));
	recordCameraAction->setText(QApplication::translate("filmoraClass", "¼������ͷ", nullptr));
	recordPCAction->setText(QApplication::translate("filmoraClass", "¼�Ƶ�����Ļ", nullptr));
	recordOffscreenAction->setText(QApplication::translate("filmoraClass", "¼�ƻ�����", nullptr));
	//
	editMenuButton->setText(QApplication::translate("filmoraClass", "�༭", nullptr));
	cutMenuButton->setText(QApplication::translate("filmoraClass", "����", nullptr));
	displayMenuButton->setText(QApplication::translate("filmoraClass", "��ʾ", nullptr));
	helpMenuButton->setText(QApplication::translate("filmoraClass", "����", nullptr));
	label->setText(QApplication::translate("filmoraClass", "δ����: 00:00:00:00", nullptr));
	closeButton->setText(QApplication::translate("filmoraClass", "X", nullptr));
	maxButton->setText(QApplication::translate("filmoraClass", "��", nullptr));
	minButton->setText(QApplication::translate("filmoraClass", "-", nullptr));
} // retranslateUi