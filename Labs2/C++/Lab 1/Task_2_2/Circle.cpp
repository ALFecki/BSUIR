#include "Circle.h"


Circle::Circle(int radius_) : radius(radius_)
{
	size = 1;
}


void Circle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->rotate(rot_angle);
	rot_angle += 1;
	painter->setPen(Qt::black);
	painter->setBrush(Qt::cyan);
	painter->drawEllipse(-radius / 2, -radius / 2, radius, radius);

	if (size != 1)
	{
		painter->scale(size, size);
	}



	QTimer::singleShot(0, this, SLOT(update()));

	Q_UNUSED(option);
	Q_UNUSED(widget);
}


QString Circle::infoAboutCircle()
{
	int area = M_PI * pow(radius, 2), perimetr = 2 * M_PI *radius;
	double x = radius, y = radius;
	return QString("Area: %1, Perimetr: %2, Center: (%3,%4)").arg(area).arg(perimetr).arg(x).arg(y);
}


QRectF Circle::boundingRect() const
{
	return QRectF(-800, -800, 1600, 1600);
}


void Circle::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	this->setPos(mapToScene(event->pos()));
}

void Circle::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	this->setCursor(QCursor(Qt::ClosedHandCursor));

	Q_UNUSED(event);
}

void Circle::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{

	this->setCursor(QCursor(Qt::ArrowCursor));
	Q_UNUSED(event);
}

void Circle::wheelEvent(QGraphicsSceneWheelEvent* event)
{
	if (event->delta() < 0)
		size -= 0.1;
	else size += 0.1;
}


void Circle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	delete this;
	Q_UNUSED(event);
}



Hexagon::Hexagon(int x1_, int y1_, int x2_, int y2_, int x3_, int y3_,
	int x4_, int y4_, int x5_, int y5_, int x6_, int y6_)
	: x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_), x4(x4_), y4(y4_), x5(x5_), y5(y5_), x6(x6_), y6(y6_)
{
	size = 1; rot_angle = 0;
}


QString Hexagon::infoAboutHexagon()
{
	int area = (abs(x5 - x2) + abs(x6 - x1)) * abs(y1 - y2), perimetr = abs(x6 - x1) * 6;
	double x = abs(x5 - x2) / 2, y = abs(y3 - y1) / 2;
	return QString("Area: %1, Perimetr: %2, Center: (%3,%4)").arg(area).arg(perimetr).arg(x).arg(y);
}


void Hexagon::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->rotate(rot_angle);
	rot_angle += 1;
	painter->setPen(Qt::black);
	painter->setBrush(Qt::darkBlue);

	QPolygon pol;
	pol << QPoint(x1, y1) << QPoint(x2, y2) << QPoint(x3, y3) << QPoint(x4, y4) << QPoint(x5, y5) << QPoint(x6, y6);

	if (size != 1)
	{
		painter->scale(size, size);
	}

	painter->drawPoint(boundingRect().center());

	painter->drawPolygon(pol);
	QTimer::singleShot(0, this, SLOT(update()));


	Q_UNUSED(option);
	Q_UNUSED(widget);

}


QRectF Hexagon::boundingRect() const
{
	return QRectF(-800, -800, 1600, 1600);
}


void Hexagon::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	this->setPos(mapToScene(event->pos()));
}

void Hexagon::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	this->setCursor(QCursor(Qt::ClosedHandCursor));

	Q_UNUSED(event);
}

void Hexagon::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{

	this->setCursor(QCursor(Qt::ArrowCursor));
	Q_UNUSED(event);
}

void Hexagon::wheelEvent(QGraphicsSceneWheelEvent* event)
{
	if (event->delta() < 0)
		size -= 0.1;
	else size += 0.1;
}


void Hexagon::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	delete this;
	Q_UNUSED(event);
}