#include "ui_filmora.h"
void Ui_filmoraClass::setupUi(QWidget *filmoraClass)
{
	filmoraClass->setWindowModality(Qt::NonModal);
	filmoraClass->setEnabled(true);
	filmoraClass->resize(960, 640);
	filmoraClass->setMaximumSize(QSize(16777215, 16777215));
	filmoraClass->setContextMenuPolicy(Qt::DefaultContextMenu);
	setupMenuUi(filmoraClass);
	retranslateUi(filmoraClass);
	QMetaObject::connectSlotsByName(filmoraClass);
} // setupUi

void Ui_filmoraClass::setupMenuUi(QWidget *filmoraClass)
{
	menuLayoutWidget = new QWidget(filmoraClass);
	//menuLayoutWidget->setGeometry(QRect(-1, -1, 960, 25));
	menuHBoxLayout = new QHBoxLayout(menuLayoutWidget);
	menuHBoxLayout->setContentsMargins(0, 0, 0, 0);
	logo = new QGraphicsView(menuLayoutWidget);
	//文件菜单按钮
	fileMenuButton = new QPushButton(menuLayoutWidget);
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

	editMenuButton = new QPushButton(menuLayoutWidget);
	cutMenuButton = new QPushButton(menuLayoutWidget);
	displayMenuButton = new QPushButton(menuLayoutWidget);
	helpMenuButton = new QPushButton(menuLayoutWidget);
	label = new QLabel(menuLayoutWidget);
	minButton = new QPushButton(menuLayoutWidget);
	maxButton = new QPushButton(menuLayoutWidget);
	closeButton = new QPushButton(menuLayoutWidget);
	menuHBoxLayout->addWidget(logo, Qt::AlignLeft);
	menuHBoxLayout->addWidget(fileMenuButton, Qt::AlignLeft);
	menuHBoxLayout->addWidget(editMenuButton, Qt::AlignLeft);
	menuHBoxLayout->addWidget(cutMenuButton, Qt::AlignLeft);
	menuHBoxLayout->addWidget(displayMenuButton, Qt::AlignLeft);
	menuHBoxLayout->addWidget(helpMenuButton, Qt::AlignLeft);
	menuHBoxLayout->addWidget(label, Qt::AlignCenter);
	menuHBoxLayout->addWidget(minButton, Qt::AlignRight);
	menuHBoxLayout->addWidget(maxButton, Qt::AlignRight);
	menuHBoxLayout->addWidget(closeButton, Qt::AlignRight);
	menuHBoxLayout->setGeometry(QRect(-1, -1, 1920, 25));
	QObject::connect(closeButton, SIGNAL(clicked()), filmoraClass, SLOT(close()));
	QObject::connect(maxButton, SIGNAL(clicked()), filmoraClass, SLOT(handleMaxButton()));
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