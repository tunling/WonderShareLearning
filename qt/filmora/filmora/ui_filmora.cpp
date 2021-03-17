#include "ui_filmora.h"

void Ui_filmoraClass::setupUi(QWidget *filmoraClass)
{
	// ��������
	filmoraClass->setWindowModality(Qt::NonModal);
	filmoraClass->setEnabled(true);
	filmoraClass->resize(960, 640);
	filmoraClass->setMaximumSize(QSize(16777215, 16777215));

	// ���û�������
	mainLayoutWidget	= new QWidget(filmoraClass);
	mainLayout			= new QGridLayout(mainLayoutWidget);
	mainLayout->setContentsMargins(0, 0, 0, 0);
	filmoraClass->setLayout(mainLayout);

	menuLayout	= new QHBoxLayout();
	menuLayout->setSpacing(0);
	mainLayout->addLayout(menuLayout, 0, 0);

	resLayout	= new QHBoxLayout();
	mainLayout->addLayout(resLayout, 1, 0);

	videoLayout = new QHBoxLayout();
	mainLayout->addLayout(videoLayout, 1, 1);

	timeLayout	= new QHBoxLayout();
	mainLayout->addLayout(timeLayout, 2, 0);
	mainLayout->setRowStretch(0, 1);
	mainLayout->setRowStretch(1, 25);
	mainLayout->setRowStretch(2, 25);

	//���ò˵�UI
	setupMenuUi(filmoraClass);
	retranslateUi(filmoraClass);

	QMetaObject::connectSlotsByName(filmoraClass);
}// ����UI


void Ui_filmoraClass::setupMenuUi(QWidget *filmoraClass)
{
	// logo
	logo = new QLabel(mainLayoutWidget);
	logo->setObjectName(QString("logo"));
	logo->setFixedSize(64, 24);
	logo->setPixmap(QPixmap("filmora.png"));
	menuLayout->addWidget(logo);

	// �ļ��˵���ť
	fileMenu			= new QMenu();
	fileMenuButton		= new QPushButton(mainLayoutWidget);
	fileMenuButton->setFixedSize(64, 24);
	
	newProjectMenu		= new QMenu(fileMenu);	// �½���Ŀ
	sixteenColonNine	= new QAction(newProjectMenu);
	oneColonone			= new QAction(newProjectMenu);
	nineColonSixteen	= new QAction(newProjectMenu);
	fourColonThree		= new QAction(newProjectMenu);
	threeColonFour		= new QAction(newProjectMenu);
	twentyoneColonNine	= new QAction(newProjectMenu);
	newProjectMenu->addAction(sixteenColonNine);
	newProjectMenu->addAction(oneColonone);
	newProjectMenu->addAction(nineColonSixteen);
	newProjectMenu->addAction(fourColonThree);
	newProjectMenu->addAction(threeColonFour);
	newProjectMenu->addAction(twentyoneColonNine);
	fileMenu->addMenu(newProjectMenu);

	openProjectAction	 = new QAction(fileMenu);	// ����Ŀ
	fileMenu->addAction(openProjectAction);

	openLastProjectsMenu = new QMenu(fileMenu);	// �����ʹ�õ�����
	openLastProjectsMenu->addActions(lastProjectActions);
	openLastProjectsMenu->setDisabled(true);

	
	fileMenu->addMenu(openLastProjectsMenu);
	fileMenu->addSeparator();

	importMenu					= new QMenu(fileMenu);	// ����˵�
	importMediaAction			= new QAction(importMenu);
	importFromDirAction			= new QAction(importMenu);
	importFromCorPAction		= new QAction(importMenu);
	importFromHarmlessAction	= new QAction(importMenu);
	importMenu->addAction(importMediaAction);
	importMenu->addAction(importFromDirAction);
	importMenu->addAction(importFromCorPAction);
	importMenu->addAction(importFromHarmlessAction);
	fileMenu->addMenu(importMenu);

	recordMenu				= new QMenu(fileMenu);	// ¼�Ʋ˵�
	recordCameraAction		= new QAction(recordMenu);
	recordPCAction			= new QAction(recordMenu);
	recordOffscreenAction	= new QAction(recordMenu);
	recordMenu->addAction(recordCameraAction);
	recordMenu->addAction(recordPCAction);
	recordMenu->addAction(recordOffscreenAction);
	fileMenu->addMenu(recordMenu);

	// --------------TODO
	fileMenuButton->setMenu(fileMenu);
	menuLayout->addWidget(fileMenuButton);

	// �༭�˵���ť
	editMenuButton		= new QPushButton(mainLayoutWidget);
	editMenuButton->setFixedSize(64, 24);
	menuLayout->addWidget(editMenuButton);

	// �����˵���ť
	cutMenuButton		= new QPushButton(mainLayoutWidget);
	cutMenuButton->setFixedSize(64, 24);
	menuLayout->addWidget(cutMenuButton);

	// չʾ�˵���ť
	displayMenuButton	= new QPushButton(mainLayoutWidget);
	displayMenuButton->setFixedSize(64, 24);
	menuLayout->addWidget(displayMenuButton);

	// �����˵���ť
	helpMenuButton		= new QPushButton(mainLayoutWidget);
	helpMenuButton->setFixedSize(64, 24);
	menuLayout->addWidget(helpMenuButton);

	// �ļ���
	menuLayout->addStretch(1);
	label				= new QLabel(mainLayoutWidget);
	label->setFixedSize(128, 24);
	menuLayout->addWidget(label);
	menuLayout->addStretch(1);

	// ��С����ť
	minButton			= new QPushButton(mainLayoutWidget);
	minButton->setFixedSize(24, 24);
	menuLayout->addWidget(minButton);

	// ��󻯰�ť
	maxButton			= new QPushButton(mainLayoutWidget);
	maxButton->setFixedSize(24, 24);
	menuLayout->addWidget(maxButton);

	// �رհ�ť
	closeButton			= new QPushButton(mainLayoutWidget);
	closeButton->setFixedSize(24, 24);
	menuLayout->addWidget(closeButton);


	QObject::connect(closeButton, SIGNAL(clicked()), filmoraClass, SLOT(close()));
	// ����filmoraClass������󻯰�ť����
	QObject::connect(maxButton, SIGNAL(clicked()), filmoraClass, SLOT(handleMaxButton()));
	QObject::connect(minButton, SIGNAL(clicked()), filmoraClass, SLOT(showMinimized()));
	
}// ���ò˵�UI

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
} // retranslateUi
