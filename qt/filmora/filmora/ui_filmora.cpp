#include "ui_filmora.h"

void Ui_filmoraClass::setupUi(QWidget *filmoraClass)
{
	// 窗口设置
	filmoraClass->setWindowModality(Qt::NonModal);
	filmoraClass->setEnabled(true);
	filmoraClass->resize(960, 640);
	filmoraClass->setMaximumSize(QSize(16777215, 16777215));
	
	// 设置基础布局
	mainLayout			= new QVBoxLayout();
	filmoraClass->setLayout(mainLayout);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	mainLayoutWidget	= new QWidget(filmoraClass);
	mainLayout->addWidget(mainLayoutWidget);
	
	menuLayout	= new QHBoxLayout();
	mainLayout->addLayout(menuLayout);
	menuLayout->setSpacing(0);
	setupMenuUi(filmoraClass);	//设置菜单UI
	
	workSpaceLayout = new QHBoxLayout();
	mainLayout->addLayout(workSpaceLayout);

	mainSplitter = new QSplitter(Qt::Vertical, nullptr);
	workSpaceLayout->addWidget(mainSplitter);
	mainSplitter->setOpaqueResize(false);
	
	resAndVideoSplitter = new QSplitter(Qt::Horizontal, mainSplitter);
	mainSplitter->setStretchFactor(0, 1);
	resAndVideoSplitter->setOpaqueResize(false);

	setupResUi(filmoraClass);
	setupVideoUi(filmoraClass);
	setupTimeUi(filmoraClass);
	retranslateUi(filmoraClass);
	QMetaObject::connectSlotsByName(filmoraClass);
}// 设置UI


void Ui_filmoraClass::setupMenuUi(QWidget *filmoraClass)
{
	// logo
	logo = new QLabel(mainLayoutWidget);
	menuLayout->addWidget(logo);
	logo->setObjectName(QString("logo"));
	logo->setFixedSize(64, 24);
	logo->setPixmap(QPixmap("filmora.png"));

	// 文件菜单按钮
	fileMenuButton		= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(fileMenuButton);
	fileMenuButton->setFixedSize(64, 24);
	fileMenu = new QMenu();
	fileMenuButton->setMenu(fileMenu);
	
	newProjectMenu		= new QMenu(fileMenu);	// 新建项目
	fileMenu->addMenu(newProjectMenu);
	sixteenColonNine	= new QAction(newProjectMenu);
	newProjectMenu->addAction(sixteenColonNine);
	oneColonone			= new QAction(newProjectMenu);
	newProjectMenu->addAction(oneColonone);
	nineColonSixteen	= new QAction(newProjectMenu);
	newProjectMenu->addAction(nineColonSixteen);
	fourColonThree		= new QAction(newProjectMenu);
	newProjectMenu->addAction(fourColonThree);
	threeColonFour		= new QAction(newProjectMenu);
	newProjectMenu->addAction(threeColonFour);
	twentyoneColonNine	= new QAction(newProjectMenu);
	newProjectMenu->addAction(twentyoneColonNine);
	
	openProjectAction	 = new QAction(fileMenu);	// 打开项目
	fileMenu->addAction(openProjectAction);
	
	openLastProjectsMenu = new QMenu(fileMenu);	// 打开最近使用的内容
	fileMenu->addMenu(openLastProjectsMenu);
	openLastProjectsMenu->addActions(lastProjectActions);
	openLastProjectsMenu->setDisabled(true);

	fileMenu->addSeparator();

	importMenu					= new QMenu(fileMenu);	// 导入菜单
	fileMenu->addMenu(importMenu);
	importMediaAction			= new QAction(importMenu);
	importMenu->addAction(importMediaAction);
	importFromDirAction			= new QAction(importMenu);
	importMenu->addAction(importFromDirAction);
	importFromCorPAction		= new QAction(importMenu);
	importMenu->addAction(importFromCorPAction);
	importFromHarmlessAction	= new QAction(importMenu);
	importMenu->addAction(importFromHarmlessAction);
	
	recordMenu				= new QMenu(fileMenu);	// 录制菜单
	fileMenu->addMenu(recordMenu);
	recordCameraAction		= new QAction(recordMenu);
	recordMenu->addAction(recordCameraAction);
	recordPCAction			= new QAction(recordMenu);
	recordMenu->addAction(recordPCAction);
	recordOffscreenAction	= new QAction(recordMenu);
	recordMenu->addAction(recordOffscreenAction);
	
	// --------------TODO
	
	// 编辑菜单按钮
	editMenuButton		= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(editMenuButton);
	editMenuButton->setFixedSize(64, 24);

	// 剪辑菜单按钮
	cutMenuButton		= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(cutMenuButton);
	cutMenuButton->setFixedSize(64, 24);
	
	// 展示菜单按钮
	displayMenuButton	= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(displayMenuButton);
	displayMenuButton->setFixedSize(64, 24);

	// 帮助菜单按钮
	helpMenuButton		= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(helpMenuButton);
	helpMenuButton->setFixedSize(64, 24);
	
	// 文件名
	menuLayout->addStretch(1);
	label				= new QLabel(mainLayoutWidget);
	menuLayout->addWidget(label);
	label->setFixedSize(128, 24);
	menuLayout->addStretch(1);

	// 最小化按钮
	minButton			= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(minButton);
	minButton->setFixedSize(24, 24);
	
	// 最大化按钮
	maxButton			= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(maxButton);
	maxButton->setFixedSize(24, 24);
	
	// 关闭按钮
	closeButton			= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(closeButton);
	closeButton->setFixedSize(24, 24);
	

	QObject::connect(closeButton, SIGNAL(clicked()), filmoraClass, SLOT(close()));
	// 交由filmoraClass处理最大化按钮功能
	QObject::connect(maxButton, SIGNAL(clicked()), filmoraClass, SLOT(handleMaxButton()));
	QObject::connect(minButton, SIGNAL(clicked()), filmoraClass, SLOT(showMinimized()));
	
}

void Ui_filmoraClass::setupResUi(QWidget *filmoraClass)
{
	resTab = new QTabWidget(resAndVideoSplitter);
	resAndVideoSplitter->setStretchFactor(0, 1);
	for (int i = 0; i < 9; i++) {
		tabs.append(new QWidget(resTab));
		resTab->addTab(tabs[i], QString());

		tabLayouts.append(new QHBoxLayout());
		tabs[i]->setLayout(tabLayouts[i]);
		tabLayouts[i]->setContentsMargins(0, 0, 0, 0);

		tabSplitters.append(new QSplitter(Qt::Horizontal, tabs[i]));
		tabLayouts[i]->addWidget(tabSplitters[i]);
		tabSplitters[i]->setOpaqueResize(false);

		tabDirs.append(new QWidget(tabSplitters[i]));
		tabSplitters[i]->setStretchFactor(0, 1);

		tabReses.append(new QWidget(tabSplitters[i]));
		tabSplitters[i]->setStretchFactor(1, 5);
	}
}

void Ui_filmoraClass::setupVideoUi(QWidget *filmoraClass)
{
	videoLayout = new QHBoxLayout();
	videoWidget = new QWidget(resAndVideoSplitter);
	videoWidget->setLayout(videoLayout);
	resAndVideoSplitter->setStretchFactor(1, 12);
}

void Ui_filmoraClass::setupTimeUi(QWidget *filmoraClass)
{
	timeLayout = new QHBoxLayout();
	timeWidget = new QWidget(mainSplitter);
	timeWidget->setLayout(timeLayout);
	mainSplitter->setStretchFactor(1, 2);
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

	// -----------------TODO
	editMenuButton->setText(QApplication::translate("filmoraClass", "编辑", nullptr));

	cutMenuButton->setText(QApplication::translate("filmoraClass", "剪辑", nullptr));

	displayMenuButton->setText(QApplication::translate("filmoraClass", "显示", nullptr));

	helpMenuButton->setText(QApplication::translate("filmoraClass", "帮助", nullptr));

	label->setText(QApplication::translate("filmoraClass", "未命名: 00:00:00:00", nullptr));

	closeButton->setText(QApplication::translate("filmoraClass", "X", nullptr));

	maxButton->setText(QApplication::translate("filmoraClass", "口", nullptr));

	minButton->setText(QApplication::translate("filmoraClass", "-", nullptr));

	resTab->setTabText(resTab->indexOf(tabs[0]), QApplication::translate("filmoraClass", "我的素材", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[1]), QApplication::translate("filmoraClass", "素材库", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[2]), QApplication::translate("filmoraClass", "音频", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[3]), QApplication::translate("filmoraClass", "文字", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[4]), QApplication::translate("filmoraClass", "转场", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[5]), QApplication::translate("filmoraClass", "滤镜", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[6]), QApplication::translate("filmoraClass", "特效", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[7]), QApplication::translate("filmoraClass", "贴纸", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[8]), QApplication::translate("filmoraClass", "分屏", nullptr));

} // retranslateUi
