#include "Rectangle.h"


Rectangle::Rectangle(int width_ = 0, int height_ = 0, double rot_angle_ = 0)
	: width(width_), height(height_), rot_angle(rot_angle_)
{
	size = 1;
}


void Rectangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->rotate(rot_angle);
	rot_angle += 0.5;

	painter->setPen(Qt::black);
	painter->setBrush(Qt::red);
	if (size != 1)
	{
		painter->scale(size, size);
	}

	painter->drawRect(-50, -50, width, height);
	painter->drawPoint(QRectF(-50, -50, width, height).center());
	QTimer::singleShot(0, this, SLOT(update()));
	Q_UNUSED(option);
	Q_UNUSED(widget);


}

void Rectangle::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	this->setPos(mapToScene(event->pos()));
}

void Rectangle::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	this->setCursor(QCursor(Qt::ClosedHandCursor));

	Q_UNUSED(event);
}

void Rectangle::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{

	this->setCursor(QCursor(Qt::ArrowCursor));
	Q_UNUSED(event);
}

void Rectangle::wheelEvent(QGraphicsSceneWheelEvent* event)
{
	if (event->delta() < 0)
		size -= 0.1;
	else size += 0.1;
}


void Rectangle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	delete this;
	Q_UNUSED(event);
}

QRectF Rectangle::boundingRect() const
{
	return QRectF(-800, -800, 1600, 1600);
}

QString Rectangle::infoAboutRect()
{
	int area = width * height, perimetr = 2 * (width + height);
	double x = width / 2, y = height / 2;
	return QString("Area: %1, Perimetr: %2, Center: (%3,%4)").arg(area).arg(perimetr).arg(x).arg(y);
}


Square::Square(int width_ = 0, double rot_angle_ = 0)
	: Rectangle(width_, width_, rot_angle_) {}