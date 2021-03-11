#ifndef UI_FILMORA_H
#define UI_FILMORA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/Qmenu>

QT_BEGIN_NAMESPACE

class Ui_filmoraClass
{
private:
	void setupMenuUi(QWidget *filmoraClass);
public:
	QGraphicsView *logo;
	QPushButton *fileMenuButton;
	QMenu *fileMenu;
	QAction *newProjectAction;
	QPushButton *editMenuButton;
	QPushButton *cutMenuButton;
	QPushButton *displayMenuButton;
	QPushButton *helpMenuButton;
	QLabel *label;
	QPushButton *closeButton;
	QPushButton *maxButton;
	QPushButton *minButton;

	void setupUi(QWidget *filmoraClass);	// setupUi
	void retranslateUi(QWidget *filmoraClass);	// retranslateUi

};

namespace Ui {
	class filmoraClass : public Ui_filmoraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILMORA_H
