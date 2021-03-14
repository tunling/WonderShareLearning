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
	//�ļ��˵���ť
	fileMenuButton = new QPushButton(menuLayoutWidget);
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