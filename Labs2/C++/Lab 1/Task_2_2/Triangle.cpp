#include "Triangle.h"

Triangle::Triangle(int x1_ = 0, int y1_ = -200, int x2_ = -400, int y2_ = 100, int x3_ = 400, int y3_ = 100)
	: x1(x1_), x2(x2_), x3(x3_), y1(y1_), y2(y2_), y3(y3_)
{
	a_side = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b_side = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	c_side = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

	rot_angle = 0; size = 1;
}

inline void Triangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->rotate(rot_angle);
	rot_angle += 0.5;
	painter->setPen(Qt::black);
	painter->setBrush(Qt::green);
	QPolygon pol;
	pol << QPoint(x1, y1) << QPoint(x2, y2) << QPoint(x3, y3);

	if (size != 1)
	{
		painter->scale(size, size);
	}

	painter->drawPolygon(pol);
	QTimer::singleShot(0, this, SLOT(update()));


	Q_UNUSED(option);
	Q_UNUSED(widget);
}

QString Triangle::infoAboutTriangle()
{
	int p = (a_side + b_side + c_side) / 2;
	int area = sqrt(p * (p - a_side) * (p - b_side) * (p - c_side)), perimetr = p * 2;
	double x = (x1 + x2 + x3) / 3, y = (y1 + y2 + y3) / 3;
	return QString("Area: %1, Perimetr: %2, Center: (%3,%4)").arg(area).arg(perimetr).arg(x).arg(y);
}


QRectF Triangle::boundingRect() const
{
	return QRectF(-800, -800, 1600, 1600);
}

void Triangle::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	this->setPos(mapToScene(event->pos()));
}

void Triangle::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	this->setCursor(QCursor(Qt::ClosedHandCursor));

	Q_UNUSED(event);
}

void Triangle::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{

	this->setCursor(QCursor(Qt::ArrowCursor));
	Q_UNUSED(event);
}

void Triangle::wheelEvent(QGraphicsSceneWheelEvent* event)
{
	if (event->delta() < 0)
		size -= 0.1;
	else size += 0.1;
}


void Triangle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	delete this;
	Q_UNUSED(event);
}