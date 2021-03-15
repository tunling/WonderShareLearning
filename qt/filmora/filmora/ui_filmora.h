#pragma execution_character_set("utf-8")	//设置utf-8编码，防止中文乱码
#ifndef UI_FILMORA_H
#define UI_FILMORA_H
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
#include <Qmessagebox>
QT_BEGIN_NAMESPACE

class Ui_filmoraClass
{
private:
	//主布局
	QGridLayout *mainLayout;	
	//主Widget
	QWidget *mainLayoutWidget;
	//菜单布局
	QHBoxLayout *menuLayout;
	//资源管理器布局
	QHBoxLayout *resLayout;
	//视频播放器布局
	QHBoxLayout *videoLayout;
	//时间线布局
	QHBoxLayout *timeLayout;
	//软件logo
	QLabel *logo;
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
	//TODO
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
	//设置UI
	void setupUi(QWidget *filmoraClass);
	void retranslateUi(QWidget *filmoraClass);
};

namespace Ui 
{
	class filmoraClass : public Ui_filmoraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILMORA_H
