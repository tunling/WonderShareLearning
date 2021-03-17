#include "filmora.h"

filmora::filmora(QWidget *parent)
	: QWidget(parent)
{
	m_bIsPressed = false;
	m_bIsResizing = false;
	m_direction = NONE;
	ui.setupUi(this);
}


void filmora::handleMaxButton()
{
	if (windowState() == Qt::WindowMaximized)
	{
		showNormal();
	}
	else 
	{
		showMaximized();
		setCursor(Qt::ArrowCursor);
	}
}// 处理最大化窗口按钮


bool filmora::event(QEvent *event)
{
	// 非最大化窗口时检测鼠标移动事件
	if (windowState() != Qt::WindowMaximized && event->type() == QEvent::HoverMove) 
	{
		QHoverEvent *hoverEvent = static_cast<QHoverEvent *>(event);
		QMouseEvent mouseEvent(QEvent::MouseMove, hoverEvent->pos(),
			Qt::NoButton, Qt::NoButton, Qt::NoModifier);
		mouseMoveEvent(&mouseEvent);
	}

	// 双击放大、缩小
	if (windowState() == Qt::WindowMaximized && event->type() == QMouseEvent::MouseButtonDblClick) 
	{
		QRect mainRect = geometry();
		QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
		int marginTop = mouseEvent->globalY() - mainRect.y();
		if (marginTop <= 24) 
		{
			showNormal();
		}
	}
	else if (windowState() != Qt::WindowMaximized && event->type() == QMouseEvent::MouseButtonDblClick)
	{
		QRect mainRect = geometry();
		QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
		int marginTop = mouseEvent->globalY() - mainRect.y();
		if (marginTop <= 24) 
		{
			showMaximized();
		}
	}
	return QWidget::event(event);
}

void filmora::mousePressEvent(QMouseEvent *event)
{
	// 非最大化窗口时检测鼠标按压事件
	if (windowState() != Qt::WindowMaximized && event->button() == Qt::LeftButton) 
	{
		m_bIsPressed = true;
		m_pressPoint = event->globalPos();
	}
	return QWidget::mousePressEvent(event);
}

void filmora::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bIsPressed) 
	{
		if (m_bIsResizing) 
		{
			m_movePoint = event->globalPos() - m_pressPoint;
			m_pressPoint += m_movePoint;
		}
		else 
		{
			QPoint point = event->globalPos() - m_pressPoint;
			move(pos() + point);
			m_pressPoint = event->globalPos();
		}
	}
	if (windowState() != Qt::WindowMaximized) 
	{
		updateRegion(event);
	}
	QWidget::mouseMoveEvent(event);
}


void filmora::updateRegion(QMouseEvent *event)
{
	QRect mainRect;
	// 分别记录鼠标离窗口上下左右边缘的距离，在调整窗口过程中时不计算值
	int marginTop, marginBottom, marginLeft, marginRight;

	if (!m_bIsResizing) 
	{
		mainRect = geometry();
		marginTop = event->globalY() - mainRect.y();
		marginBottom = mainRect.y() + mainRect.height() - event->globalY();
		marginLeft = event->globalX() - mainRect.x();
		marginRight = mainRect.x() + mainRect.width() - event->globalX();
		if ((marginRight >= MARGIN_MIN_SIZE && marginRight <= MARGIN_MAX_SIZE)
			&& ((marginBottom <= MARGIN_MAX_SIZE) && marginBottom >= MARGIN_MIN_SIZE)) 
		{
			m_direction = BOTTOMRIGHT;
			setCursor(Qt::SizeFDiagCursor);
		}
		else if ((marginTop >= MARGIN_MIN_SIZE && marginTop <= MARGIN_MAX_SIZE)
			&& (marginRight >= MARGIN_MIN_SIZE && marginRight <= MARGIN_MAX_SIZE)) 
		{
			m_direction = TOPRIGHT;
			setCursor(Qt::SizeBDiagCursor);
		}
		else if ((marginLeft >= MARGIN_MIN_SIZE && marginLeft <= MARGIN_MAX_SIZE)
			&& (marginTop >= MARGIN_MIN_SIZE && marginTop <= MARGIN_MAX_SIZE)) 
		{
			m_direction = TOPLEFT;
			setCursor(Qt::SizeFDiagCursor);
		}
		else if ((marginLeft >= MARGIN_MIN_SIZE && marginLeft <= MARGIN_MAX_SIZE)
			&& (marginBottom >= MARGIN_MIN_SIZE && marginBottom <= MARGIN_MAX_SIZE)) 
		{
			m_direction = BOTTOMLEFT;
			setCursor(Qt::SizeBDiagCursor);
		}
		else if (marginBottom <= MARGIN_MAX_SIZE && marginBottom >= MARGIN_MIN_SIZE)
		{
			m_direction = DOWN;
			setCursor(Qt::SizeVerCursor);
		}
		else if (marginLeft <= MARGIN_MAX_SIZE - 1 && marginLeft >= MARGIN_MIN_SIZE - 1) 
		{
			m_direction = LEFT;
			setCursor(Qt::SizeHorCursor);
		}
		else if (marginRight <= MARGIN_MAX_SIZE && marginRight >= MARGIN_MIN_SIZE) 
		{
			m_direction = RIGHT;
			setCursor(Qt::SizeHorCursor);
		}
		else if (marginTop <= MARGIN_MAX_SIZE && marginTop >= MARGIN_MIN_SIZE) 
		{
			m_direction = UP;
			setCursor(Qt::SizeVerCursor);
		}
		else 
		{
			if (!m_bIsPressed) 
			{
				setCursor(Qt::ArrowCursor);
			}
		}
	}

	if (m_direction != NONE) 
	{
		mainRect = geometry();
		marginTop = event->globalY() - mainRect.y();
		marginBottom = mainRect.y() + mainRect.height() - event->globalY();
		marginLeft = event->globalX() - mainRect.x();
		marginRight = mainRect.x() + mainRect.width() - event->globalX();
		m_bIsResizing = true;
		resizeRegion(marginTop, marginBottom, marginLeft, marginRight);
	}
}// 判断放缩方向并调用更新大小函数

void filmora::resizeRegion(int marginTop, int marginBottom, int marginLeft, int marginRight)
{
	if (m_bIsPressed) 
	{
		QRect rect;
		switch (m_direction) 
		{
		case BOTTOMRIGHT:
			rect = geometry();
			rect.setBottomRight(rect.bottomRight() + m_movePoint);
			setGeometry(rect);
			break;
		case TOPRIGHT:
			if (marginLeft > minimumWidth() && marginBottom > minimumHeight()) 
			{
				rect = geometry();
				rect.setTopRight(rect.topRight() + m_movePoint);
				setGeometry(rect);
			}
			break;
		case TOPLEFT:
			if (marginRight > minimumWidth() && marginBottom > minimumHeight()) 
			{
				rect = geometry();
				rect.setTopLeft(rect.topLeft() + m_movePoint);
				setGeometry(rect);
			}
			break;
		case BOTTOMLEFT:
			if (marginRight > minimumWidth() && marginTop > minimumHeight()) 
			{
				rect = geometry();
				rect.setBottomLeft(rect.bottomLeft() + m_movePoint);
				setGeometry(rect);
			}
			break;
		case RIGHT:
			rect = geometry();
			rect.setWidth(rect.width() + m_movePoint.x());
			setGeometry(rect);
			break;
		case DOWN:
			rect = geometry();
			rect.setHeight(rect.height() + m_movePoint.y());
			setGeometry(rect);
			break;
		case LEFT:
			if (marginRight > minimumWidth()) 
			{
				rect = geometry();
				rect.setLeft(rect.x() + m_movePoint.x());
				setGeometry(rect);
			}
			break;
		case UP:
			if (marginBottom > minimumHeight()) 
			{
				rect = geometry();
				rect.setTop(rect.y() + m_movePoint.y());
				setGeometry(rect);
			}
			break;
		default:
			break;
		}
	}
	else 
	{
		m_bIsResizing = false;
		m_direction = NONE;
	}
}// 更新大小

void filmora::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) 
	{
		m_bIsPressed = false;
		m_bIsResizing = false;
		this->setGraphicsEffect(nullptr);
	}
	QWidget::mouseReleaseEvent(event);
}

void filmora::leaveEvent(QEvent *event)
{
	m_bIsPressed = false;
	m_bIsResizing = false;
	QWidget::leaveEvent(event);
}
