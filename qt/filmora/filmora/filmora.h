#pragma once
#include "ui_filmora.h"
#define MARGIN_MIN_SIZE 0
#define MARGIN_MAX_SIZE 4

class filmora : public QWidget
{
	Q_OBJECT
public:
	filmora					(QWidget *parent = Q_NULLPTR);
	bool event				(QEvent *event);
	void mousePressEvent	(QMouseEvent *event);
	void mouseMoveEvent		(QMouseEvent *event);
	void updateRegion		(QMouseEvent *event);
	void resizeRegion		(int marginTop, int marginBottom, int marginLeft, int marginRight);
	void mouseReleaseEvent	(QMouseEvent *event);
	void leaveEvent			(QEvent *event);

private:
	Ui::filmoraClass ui;
	//ö�����ͣ��������÷������ڷ���
	enum direction { BOTTOMRIGHT, TOPRIGHT, TOPLEFT, BOTTOMLEFT, DOWN, LEFT, RIGHT, UP, NONE };	
	direction	m_direction;	
	bool		m_bIsPressed;	//��¼�Ƿ�ѹ
	bool		m_bIsResizing;	//��¼�Ƿ����ڵ�������
	QPoint		m_pressPoint;	//��¼��ѹ��
	QPoint		m_movePoint;	//��¼�ƶ���

private slots:
	//������󻯴��ڰ�ť
	void		handleMaxButton();
};
