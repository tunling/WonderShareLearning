#ifndef UI_FILMORA_H
#define UI_FILMORA_H
#pragma execution_character_set("utf-8")
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/Qmenu>
#include <QtWidgets/QBoxlayout>
#include <QtWidgets/QWidget>
#include <Qdesktopwidget>
#include <QPoint>
#include <QKeyEvent>
#include <QGraphicsDropShadowEffect>

QT_BEGIN_NAMESPACE

class Ui_filmoraClass
{
private:
	QWidget *menuLayoutWidget;
	QHBoxLayout *menuHBoxLayout;
	QGraphicsView *logo;
	//�ļ��˵���ť
	QPushButton *fileMenuButton;
	QMenu *fileMenu;
	QMenu *newProjectMenu;	//�½���Ŀ�˵�
	QAction *sixteenColonNine;
	QAction *oneColonone;
	QAction *nineColonSixteen;
	QAction *fourColonThree;
	QAction *threeColonFour;
	QAction *twentyoneColonNine;
	QAction *openProjectAction;	//����Ŀ
	QMenu *openLastProjectsMenu; //�������Ŀ
	QList<QAction *> lastProjectActions;
	QMenu *importMenu;	//����˵�
	QAction *importMediaAction;
	QAction *importFromDirAction;
	QAction *importFromCorPAction;
	QAction *importFromHarmlessAction;
	QMenu *recordMenu;	//¼�Ʋ˵�
	QAction *recordCameraAction;
	QAction *recordPCAction;
	QAction *recordOffscreenAction;
	//
	QPushButton *editMenuButton;
	QPushButton *cutMenuButton;
	QPushButton *displayMenuButton;
	QPushButton *helpMenuButton;
	QLabel *label;
	QPushButton *closeButton;
	QPushButton *maxButton;
	QPushButton *minButton;
	void setupMenuUi(QWidget *filmoraClass);
public: 
	void setupUi(QWidget *filmoraClass);	// setupUi
	void retranslateUi(QWidget *filmoraClass);	// retranslateUi
};

namespace Ui 
{
	class filmoraClass : public Ui_filmoraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILMORA_H
