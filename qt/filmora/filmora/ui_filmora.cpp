#include "ui_filmora.h"

//设置UI
void Ui_filmoraClass::setupUi(QWidget *filmoraClass)
{
	filmoraClass->setWindowModality(Qt::NonModal);
	filmoraClass->setEnabled(true);
	filmoraClass->resize(960, 640);
	filmoraClass->setMaximumSize(QSize(16777215, 16777215));
	//设置基础布局
	mainLayoutWidget = new QWidget(filmoraClass);
	mainLayout = new QGridLayout(mainLayoutWidget);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	menuLayout = new QHBoxLayout();
	menuLayout->setSpacing(0);
	mainLayout->addLayout(menuLayout, 0, 0);
	resLayout = new QHBoxLayout();
	mainLayout->addLayout(resLayout, 1, 0);
	videoLayout = new QHBoxLayout();
	mainLayout->addLayout(videoLayout, 1, 1);
	timeLayout = new QHBoxLayout();
	mainLayout->addLayout(timeLayout, 2, 0);
	mainLayout->setRowStretch(0, 1);
	mainLayout->setRowStretch(1, 25);
	mainLayout->setRowStretch(2, 25);
	//设置菜单UI
	setupMenuUi(filmoraClass);
	//为主窗口设置主布局
	filmoraClass->setLayout(mainLayout);
	retranslateUi(filmoraClass);
	QMetaObject::connectSlotsByName(filmoraClass);
}

//设置菜单UI
void Ui_filmoraClass::setupMenuUi(QWidget *filmoraClass)
{
	//logo
	logo = new QLabel(mainLayoutWidget);
	logo->setObjectName(QString("logo"));
	logo->setFixedSize(64, 24);
	logo->setPixmap(QPixmap("D:\\file\\wondershare\\qt\\filmora\\filmora\\filmora.png"));
	menuLayout->addWidget(logo);
	//文件菜单按钮
	fileMenuButton = new QPushButton(mainLayoutWidget);
	fileMenuButton->setFixedSize(64, 24);
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
	//TODO
	fileMenuButton->setMenu(fileMenu);
	menuLayout->addWidget(fileMenuButton);
	//编辑菜单按钮
	editMenuButton = new QPushButton(mainLayoutWidget);
	editMenuButton->setFixedSize(64, 24);
	menuLayout->addWidget(editMenuButton);
	//剪辑菜单按钮
	cutMenuButton = new QPushButton(mainLayoutWidget);
	cutMenuButton->setFixedSize(64, 24);
	menuLayout->addWidget(cutMenuButton);
	//展示菜单按钮
	displayMenuButton = new QPushButton(mainLayoutWidget);
	displayMenuButton->setFixedSize(64, 24);
	menuLayout->addWidget(displayMenuButton);
	//帮助菜单按钮
	helpMenuButton = new QPushButton(mainLayoutWidget);
	helpMenuButton->setFixedSize(64, 24);
	menuLayout->addWidget(helpMenuButton);
	//文件名
	menuLayout->addStretch(1);
	label = new QLabel(mainLayoutWidget);
	label->setFixedSize(128, 24);
	menuLayout->addWidget(label);
	menuLayout->addStretch(1);
	//最小化按钮
	minButton = new QPushButton(mainLayoutWidget);
	minButton->setFixedSize(24, 24);
	menuLayout->addWidget(minButton);
	//最大化按钮
	maxButton = new QPushButton(mainLayoutWidget);
	maxButton->setFixedSize(24, 24);
	menuLayout->addWidget(maxButton);
	//关闭按钮
	closeButton = new QPushButton(mainLayoutWidget);
	closeButton->setFixedSize(24, 24);
	menuLayout->addWidget(closeButton);

	QObject::connect(closeButton, SIGNAL(clicked()), filmoraClass, SLOT(close()));
	QObject::connect(maxButton, SIGNAL(clicked()), filmoraClass, SLOT(handleMaxButton()));
	QObject::connect(minButton, SIGNAL(clicked()), filmoraClass, SLOT(showMinimized()));
	
}

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
