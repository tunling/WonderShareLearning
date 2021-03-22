#include "ui_filmora.h"

void Ui_filmoraClass::setupUi(QWidget *filmoraClass)
{
	// ��������
	filmoraClass->setWindowModality(Qt::NonModal);
	filmoraClass->setEnabled(true);
	filmoraClass->resize(960, 640);
	filmoraClass->setMaximumSize(QSize(16777215, 16777215));
	
	// ���û�������
	mainLayout			= new QVBoxLayout();
	filmoraClass->setLayout(mainLayout);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	mainLayoutWidget	= new QWidget(filmoraClass);
	mainLayout->addWidget(mainLayoutWidget);
	
	menuLayout	= new QHBoxLayout();
	mainLayout->addLayout(menuLayout);
	menuLayout->setSpacing(0);
	setupMenuUi(filmoraClass);	//���ò˵�UI
	
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
}// ����UI


void Ui_filmoraClass::setupMenuUi(QWidget *filmoraClass)
{
	// logo
	logo = new QLabel(mainLayoutWidget);
	menuLayout->addWidget(logo);
	logo->setObjectName(QString("logo"));
	logo->setFixedSize(64, 24);
	logo->setPixmap(QPixmap("filmora.png"));

	// �ļ��˵���ť
	fileMenuButton		= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(fileMenuButton);
	fileMenuButton->setFixedSize(64, 24);
	fileMenu = new QMenu();
	fileMenuButton->setMenu(fileMenu);
	
	newProjectMenu		= new QMenu(fileMenu);	// �½���Ŀ
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
	
	openProjectAction	 = new QAction(fileMenu);	// ����Ŀ
	fileMenu->addAction(openProjectAction);
	
	openLastProjectsMenu = new QMenu(fileMenu);	// �����ʹ�õ�����
	fileMenu->addMenu(openLastProjectsMenu);
	openLastProjectsMenu->addActions(lastProjectActions);
	openLastProjectsMenu->setDisabled(true);

	fileMenu->addSeparator();

	importMenu					= new QMenu(fileMenu);	// ����˵�
	fileMenu->addMenu(importMenu);
	importMediaAction			= new QAction(importMenu);
	importMenu->addAction(importMediaAction);
	importFromDirAction			= new QAction(importMenu);
	importMenu->addAction(importFromDirAction);
	importFromCorPAction		= new QAction(importMenu);
	importMenu->addAction(importFromCorPAction);
	importFromHarmlessAction	= new QAction(importMenu);
	importMenu->addAction(importFromHarmlessAction);
	
	recordMenu				= new QMenu(fileMenu);	// ¼�Ʋ˵�
	fileMenu->addMenu(recordMenu);
	recordCameraAction		= new QAction(recordMenu);
	recordMenu->addAction(recordCameraAction);
	recordPCAction			= new QAction(recordMenu);
	recordMenu->addAction(recordPCAction);
	recordOffscreenAction	= new QAction(recordMenu);
	recordMenu->addAction(recordOffscreenAction);
	
	// --------------TODO
	
	// �༭�˵���ť
	editMenuButton		= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(editMenuButton);
	editMenuButton->setFixedSize(64, 24);

	// �����˵���ť
	cutMenuButton		= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(cutMenuButton);
	cutMenuButton->setFixedSize(64, 24);
	
	// չʾ�˵���ť
	displayMenuButton	= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(displayMenuButton);
	displayMenuButton->setFixedSize(64, 24);

	// �����˵���ť
	helpMenuButton		= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(helpMenuButton);
	helpMenuButton->setFixedSize(64, 24);
	
	// �ļ���
	menuLayout->addStretch(1);
	label				= new QLabel(mainLayoutWidget);
	menuLayout->addWidget(label);
	label->setFixedSize(128, 24);
	menuLayout->addStretch(1);

	// ��С����ť
	minButton			= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(minButton);
	minButton->setFixedSize(24, 24);
	
	// ��󻯰�ť
	maxButton			= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(maxButton);
	maxButton->setFixedSize(24, 24);
	
	// �رհ�ť
	closeButton			= new QPushButton(mainLayoutWidget);
	menuLayout->addWidget(closeButton);
	closeButton->setFixedSize(24, 24);
	

	QObject::connect(closeButton, SIGNAL(clicked()), filmoraClass, SLOT(close()));
	// ����filmoraClass������󻯰�ť����
	QObject::connect(maxButton, SIGNAL(clicked()), filmoraClass, SLOT(handleMaxButton()));
	QObject::connect(minButton, SIGNAL(clicked()), filmoraClass, SLOT(showMinimized()));
	
}

void Ui_filmoraClass::setupResUi(QWidget *filmoraClass)
{
	resLayout = new QHBoxLayout();
	resTab = new QTabWidget(resAndVideoSplitter);
	resLayout->addWidget(resTab);
	resAndVideoSplitter->setStretchFactor(0, 1);
	for (int i = 0; i < 9; i++) {
		tabs.append(new QWidget(resTab));
		resTab->addTab(tabs[i], QString());
	}
}

void Ui_filmoraClass::setupVideoUi(QWidget *filmoraClass)
{
	videoLayout = new QHBoxLayout();
	videoWidget = new QWidget(resAndVideoSplitter);
	videoLayout->addWidget(videoWidget);
	resAndVideoSplitter->setStretchFactor(1, 2);
}

void Ui_filmoraClass::setupTimeUi(QWidget *filmoraClass)
{
	timeLayout = new QHBoxLayout();
	timeWidget = new QWidget(mainSplitter);
	timeLayout->addWidget(timeWidget);
	mainSplitter->setStretchFactor(1, 1);
}

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

	// -----------------TODO
	editMenuButton->setText(QApplication::translate("filmoraClass", "�༭", nullptr));

	cutMenuButton->setText(QApplication::translate("filmoraClass", "����", nullptr));

	displayMenuButton->setText(QApplication::translate("filmoraClass", "��ʾ", nullptr));

	helpMenuButton->setText(QApplication::translate("filmoraClass", "����", nullptr));

	label->setText(QApplication::translate("filmoraClass", "δ����: 00:00:00:00", nullptr));

	closeButton->setText(QApplication::translate("filmoraClass", "X", nullptr));

	maxButton->setText(QApplication::translate("filmoraClass", "��", nullptr));

	minButton->setText(QApplication::translate("filmoraClass", "-", nullptr));

	resTab->setTabText(resTab->indexOf(tabs[0]), QApplication::translate("filmoraClass", "�ҵ��ز�", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[1]), QApplication::translate("filmoraClass", "�زĿ�", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[2]), QApplication::translate("filmoraClass", "��Ƶ", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[3]), QApplication::translate("filmoraClass", "����", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[4]), QApplication::translate("filmoraClass", "ת��", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[5]), QApplication::translate("filmoraClass", "�˾�", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[6]), QApplication::translate("filmoraClass", "��Ч", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[7]), QApplication::translate("filmoraClass", "��ֽ", nullptr));
	resTab->setTabText(resTab->indexOf(tabs[8]), QApplication::translate("filmoraClass", "����", nullptr));

} // retranslateUi
