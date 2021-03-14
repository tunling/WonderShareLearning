#pragma once
#include "ui_filmora.h"
#define MARGIN_MIN_SIZE 0
#define MARGIN_MAX_SIZE 4

class filmora : public QWidget
{
	Q_OBJECT
public:
	filmora(QWidget *parent = Q_NULLPTR);
	//通用事件监听器
	bool event(QEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void updateRegion(QMouseEvent *event);
	void resizeRegion(int marginTop, int marginBottom, int marginLeft, int marginRight);
	void mouseReleaseEvent(QMouseEvent *event);
	void leaveEvent(QEvent *event);
private:
	Ui::filmoraClass ui;
	enum direction { BOTTOMRIGHT, TOPRIGHT, TOPLEFT, BOTTOMLEFT, DOWN, LEFT, RIGHT, UP, NONE };
	bool m_bIsPressed;
	bool m_bIsResizing;
	direction m_direction;
	QPoint m_pressPoint;
	QPoint m_movePoint;
private slots:
	//处理最大化窗口按钮
	void handleMaxButton();
};
