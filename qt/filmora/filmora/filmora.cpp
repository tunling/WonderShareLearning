#include "filmora.h"
filmora::filmora(QWidget *parent)
	: QWidget(parent)
{
	m_bIsPressed = false;
	m_bIsResizing = false;
	m_bIsDoublePressed = false;
	m_direction = NONE;
	ui.setupUi(this);
}

void filmora::handleMaxButton()
{
	if (windowState() == Qt::WindowMaximized) {
		showNormal();
	}
	else {
		showMaximized();
	}
}

bool filmora::event(QEvent *event)
{
	if (event->type() == QEvent::HoverMove) {
		QHoverEvent *hoverEvent = static_cast<QHoverEvent *>(event);
		QMouseEvent mouseEvent(QEvent::MouseMove, hoverEvent->pos(),
			Qt::NoButton, Qt::NoButton, Qt::NoModifier);
		mouseMoveEvent(&mouseEvent);
	}
	return QWidget::event(event);
}
//按压事件
void filmora::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		m_bIsPressed = true;
		m_pressPoint = event->globalPos();
	}
	return QWidget::mousePressEvent(event);
}
//拖动窗口
void filmora::mouseMoveEvent(QMouseEvent *event)
{
	if (m_bIsPressed) {
		if (m_bIsResizing) {
			m_movePoint = event->globalPos() - m_pressPoint;
			m_pressPoint += m_movePoint;
		}
		else {
			if (!m_bIsDoublePressed && windowState() == Qt::WindowMaximized) {
				showNormal();
				QPointF point(width() * ((double)(event->globalPos().x()) / QApplication::desktop()->width()),
					height() * ((double)(event->globalPos().y()) / QApplication::desktop()->height()));
				move(event->globalPos() - point.toPoint());
				m_pressPoint = event->globalPos();
			}
			QPoint point = event->globalPos() - m_pressPoint;
			move(pos() + point);
			m_pressPoint = event->globalPos();
		}
	}
	if (windowState() != Qt::WindowMaximized) {
		updateRegion(event);
	}
	QWidget::mouseMoveEvent(event);
}
//更新大小
void filmora::updateRegion(QMouseEvent *event)
{
	QRect mainRect;
	int marginTop;
	int marginBottom;
	int marginLeft;
	int marginRight;
	if (!m_bIsResizing) {
		mainRect = geometry();
		marginTop = event->globalY() - mainRect.y();
		marginBottom = mainRect.y() + mainRect.height() - event->globalY();
		marginLeft = event->globalX() - mainRect.x();
		marginRight = mainRect.x() + mainRect.width() - event->globalX();
		if ((marginRight >= MARGIN_MIN_SIZE && marginRight <= MARGIN_MAX_SIZE)
			&& ((marginBottom <= MARGIN_MAX_SIZE) && marginBottom >= MARGIN_MIN_SIZE)) {
			m_direction = BOTTOMRIGHT;
			setCursor(Qt::SizeFDiagCursor);
		}
		else if ((marginTop >= MARGIN_MIN_SIZE && marginTop <= MARGIN_MAX_SIZE)
			&& (marginRight >= MARGIN_MIN_SIZE && marginRight <= MARGIN_MAX_SIZE)) {
			m_direction = TOPRIGHT;
			setCursor(Qt::SizeBDiagCursor);
		}
		else if ((marginLeft >= MARGIN_MIN_SIZE && marginLeft <= MARGIN_MAX_SIZE)
			&& (marginTop >= MARGIN_MIN_SIZE && marginTop <= MARGIN_MAX_SIZE)) {
			m_direction = TOPLEFT;
			setCursor(Qt::SizeFDiagCursor);
		}
		else if ((marginLeft >= MARGIN_MIN_SIZE && marginLeft <= MARGIN_MAX_SIZE)
			&& (marginBottom >= MARGIN_MIN_SIZE && marginBottom <= MARGIN_MAX_SIZE)) {
			m_direction = BOTTOMLEFT;
			setCursor(Qt::SizeBDiagCursor);
		}
		else if (marginBottom <= MARGIN_MAX_SIZE && marginBottom >= MARGIN_MIN_SIZE) {
			m_direction = DOWN;
			setCursor(Qt::SizeVerCursor);
		}
		else if (marginLeft <= MARGIN_MAX_SIZE - 1 && marginLeft >= MARGIN_MIN_SIZE - 1) {
			m_direction = LEFT;
			setCursor(Qt::SizeHorCursor);
		}
		else if (marginRight <= MARGIN_MAX_SIZE && marginRight >= MARGIN_MIN_SIZE) {
			m_direction = RIGHT;
			setCursor(Qt::SizeHorCursor);
		}
		else if (marginTop <= MARGIN_MAX_SIZE && marginTop >= MARGIN_MIN_SIZE) {
			m_direction = UP;
			setCursor(Qt::SizeVerCursor);
		}
		else {
			if (!m_bIsPressed) {
				setCursor(Qt::ArrowCursor);
			}
		}
	}
	if (m_direction != NONE) {
		mainRect = geometry();
		marginTop = event->globalY() - mainRect.y();
		marginBottom = mainRect.y() + mainRect.height() - event->globalY();
		marginLeft = event->globalX() - mainRect.x();
		marginRight = mainRect.x() + mainRect.width() - event->globalX();
		m_bIsResizing = true;
		resizeRegion(marginTop, marginBottom, marginLeft, marginRight);
	}
}
//重新设置大小
void filmora::resizeRegion(int marginTop, int marginBottom, int marginLeft, int marginRight)
{
	if (m_bIsPressed) {
		QRect rect;
		switch (m_direction) {
		case BOTTOMRIGHT:
			rect = geometry();
			rect.setBottomRight(rect.bottomRight() + m_movePoint);
			setGeometry(rect);
			break;
		case TOPRIGHT:
			if (marginLeft > minimumWidth() && marginBottom > minimumHeight()) {
				rect = geometry();
				rect.setTopRight(rect.topRight() + m_movePoint);
				setGeometry(rect);
			}
			break;
		case TOPLEFT:
			if (marginRight > minimumWidth() && marginBottom > minimumHeight()) {
				rect = geometry();
				rect.setTopLeft(rect.topLeft() + m_movePoint);
				setGeometry(rect);
			}
			break;
		case BOTTOMLEFT:
			if (marginRight > minimumWidth() && marginTop > minimumHeight()) {
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
			if (marginRight > minimumWidth()) {
				rect = geometry();
				rect.setLeft(rect.x() + m_movePoint.x());
				setGeometry(rect);
			}
			break;
		case UP:
			if (marginBottom > minimumHeight()) {
				rect = geometry();
				rect.setTop(rect.y() + m_movePoint.y());
				setGeometry(rect);
			}
			break;
		default:
			break;
		}
	}
	else {
		m_bIsResizing = false;
		m_direction = NONE;
	}
}
//释放事件
void filmora::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		m_bIsPressed = false;
		m_bIsResizing = false;
		m_bIsDoublePressed = false;
		this->setGraphicsEffect(nullptr);
	}
	QWidget::mouseReleaseEvent(event);
}
//离开事件
void filmora::leaveEvent(QEvent *event)
{
	m_bIsPressed = false;
	m_bIsDoublePressed = false;
	m_bIsResizing = false;
	QWidget::leaveEvent(event);
}





