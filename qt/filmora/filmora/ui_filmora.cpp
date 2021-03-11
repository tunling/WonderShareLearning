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
	//文件菜单按钮
	fileMenuButton = new QPushButton(filmoraClass);
	fileMenuButton->setObjectName(QString::fromUtf8("fileMenuButton"));
	fileMenuButton->setGeometry(QRect(64, 0, 64, 24));
	fileMenu = new QMenu();
	newProjectMenu = new QMenu(fileMenu);	//新建项目
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
	openProjectAction = new QAction(fileMenu);	//打开项目
	fileMenu->addAction(openProjectAction);
	openLastProjectsMenu = new QMenu(fileMenu);	//打开最近使用的内容
	openLastProjectsMenu->addActions(lastProjectActions);
	openLastProjectsMenu->setDisabled(true);
	fileMenu->addMenu(openLastProjectsMenu);
	fileMenu->addSeparator();
	importMenu = new QMenu(fileMenu);	//导入菜单
	importMediaAction = new QAction(importMenu);
	importFromDirAction = new QAction(importMenu);
	importFromCorPAction = new QAction(importMenu);
	importFromHarmlessAction = new QAction(importMenu);
	importMenu->addAction(importMediaAction);
	importMenu->addAction(importFromDirAction);
	importMenu->addAction(importFromCorPAction);
	importMenu->addAction(importFromHarmlessAction);
	fileMenu->addMenu(importMenu);
	recordMenu = new QMenu(fileMenu);	//录制菜单
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
	fileMenuButton->setText(QApplication::translate("filmoraClass", "文件", nullptr));
	newProjectMenu->setTitle(QApplication::translate("filmoraClass", "新建项目", nullptr));
	sixteenColonNine->setText(QApplication::translate("filmoraClass", "16 : 9", nullptr));
	oneColonone->setText(QApplication::translate("filmoraClass", "1 : 1", nullptr));
	nineColonSixteen->setText(QApplication::translate("filmoraClass", "9 : 16", nullptr));
	fourColonThree->setText(QApplication::translate("filmoraClass", "4 : 3", nullptr));
	threeColonFour->setText(QApplication::translate("filmoraClass", "3 : 4", nullptr));
	twentyoneColonNine->setText(QApplication::translate("filmoraClass", "21 : 9", nullptr));
	openProjectAction->setText(QApplication::translate("filmoraClass", "打开项目", nullptr));
	openLastProjectsMenu->setTitle(QApplication::translate("filmoraClass", "打开最近使用的内容", nullptr));
	importMenu->setTitle(QApplication::translate("filmoraClass", "导入", nullptr));
	importMediaAction->setText(QApplication::translate("filmoraClass", "导入媒体", nullptr));
	importFromDirAction->setText(QApplication::translate("filmoraClass", "导入文件夹", nullptr));
	importFromCorPAction->setText(QApplication::translate("filmoraClass", "从相机或手机导入", nullptr));
	importFromHarmlessAction->setText(QApplication::translate("filmoraClass", "使用无损剪切工具导入", nullptr));
	recordMenu->setTitle(QApplication::translate("filmoraClass", "录制", nullptr));
	recordCameraAction->setText(QApplication::translate("filmoraClass", "录制摄像头", nullptr));
	recordPCAction->setText(QApplication::translate("filmoraClass", "录制电脑屏幕", nullptr));
	recordOffscreenAction->setText(QApplication::translate("filmoraClass", "录制画外音", nullptr));
	//
	editMenuButton->setText(QApplication::translate("filmoraClass", "编辑", nullptr));
	cutMenuButton->setText(QApplication::translate("filmoraClass", "剪辑", nullptr));
	displayMenuButton->setText(QApplication::translate("filmoraClass", "显示", nullptr));
	helpMenuButton->setText(QApplication::translate("filmoraClass", "帮助", nullptr));
	label->setText(QApplication::translate("filmoraClass", "未命名: 00:00:00:00", nullptr));
	closeButton->setText(QApplication::translate("filmoraClass", "X", nullptr));
	maxButton->setText(QApplication::translate("filmoraClass", "口", nullptr));
	minButton->setText(QApplication::translate("filmoraClass", "-", nullptr));
} // retranslateUi