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
	//文件菜单按钮
	QPushButton *fileMenuButton;
	QMenu *fileMenu;
	QMenu *newProjectMenu;	//新建项目菜单
	QAction *sixteenColonNine;
	QAction *oneColonone;
	QAction *nineColonSixteen;
	QAction *fourColonThree;
	QAction *threeColonFour;
	QAction *twentyoneColonNine;
	QAction *openProjectAction;	//打开项目
	QMenu *openLastProjectsMenu; //打开最近项目
	QList<QAction *> lastProjectActions;
	QMenu *importMenu;	//导入菜单
	QAction *importMediaAction;
	QAction *importFromDirAction;
	QAction *importFromCorPAction;
	QAction *importFromHarmlessAction;
	QMenu *recordMenu;	//录制菜单
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
