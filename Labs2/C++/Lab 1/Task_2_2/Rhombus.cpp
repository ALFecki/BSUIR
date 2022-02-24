#include "Rhombus.h"



Rhombus::Rhombus(int x1_ = 0, int y1_ = -150, int x2_ = -100, int y2_ = 0,
	int x3_ = 0, int y3_ = 150, int x4_ = 100, int y4_ = 0)
	: x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_), x4(x4_), y4(y4_)
{
	diagonal_1 = abs(y1 - y3);
	diagonal_2 = abs(x2 - x4);
	size = 1; rot_angle = 0;
	side = sqrt(pow(diagonal_1 / 2, 2) + pow(diagonal_2 / 2, 2));
}


inline void Rhombus::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->rotate(rot_angle);
	rot_angle += 5;
	painter->setPen(Qt::black);
	painter->setBrush(Qt::blue);
	QPolygon pol;
	pol << QPoint(x1, y1) << QPoint(x2, y2) << QPoint(x3, y3) << QPoint(x4, y4);

	if (size != 1)
	{
		painter->scale(size, size);
	}
	painter->drawPolygon(pol);
	QTimer::singleShot(0, this, SLOT(update()));


	Q_UNUSED(option);
	Q_UNUSED(widget);
}

QRectF Rhombus::boundingRect() const
{
	return QRectF(-800, -800, 1600, 1600);
}

QString Rhombus::infoAboutRhomb()
{
	int area = diagonal_1 * diagonal_2 / 2, perimetr = 4 * side;
	double x = diagonal_1 / 2, y = diagonal_2 / 2;
	return QString("Area: %1, Perimetr: %2, Center: (%3,%4)").arg(area).arg(perimetr).arg(x).arg(y);
}


void Rhombus::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	this->setPos(mapToScene(event->pos()));
}

void Rhombus::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	this->setCursor(QCursor(Qt::ClosedHandCursor));

	Q_UNUSED(event);
}

void Rhombus::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{

	this->setCursor(QCursor(Qt::ArrowCursor));
	Q_UNUSED(event);
}

void Rhombus::wheelEvent(QGraphicsSceneWheelEvent* event)
{
	if (event->delta() < 0)
		size -= 0.1;
	else size += 0.1;
}


void Rhombus::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	delete this;
	Q_UNUSED(event);
}


Trapezoid::Trapezoid(int x1_ = 0, int y1_ = -150, int x2_ = -100, int y2_ = 0)
	: x1(x1_), y1(y1_), x2(x2_), y2(y2_)
{
	size = 1; rot_angle = 0;
}

inline void Trapezoid::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->rotate(rot_angle);
	rot_angle += 5;
	painter->setPen(Qt::black);
	painter->setBrush(Qt::blue);
	QPolygon pol;
	pol << QPoint(x1, y1) << QPoint(x2, y2) << QPoint(x2 + 50, y2) << QPoint(x1 + 200, y1);

	if (size != 1)
	{
		painter->scale(size, size);
	}
	painter->drawPolygon(pol);
	painter->drawPoint(QRectF(0, 0, x2 + 200, y1).center());
	QTimer::singleShot(0, this, SLOT(update()));


	Q_UNUSED(option);
	Q_UNUSED(widget);
}

QRectF Trapezoid::boundingRect() const
{
	return QRectF(-800, -800, 1600, 1600);
}

QString Trapezoid::infoAboutTrapezoid()
{
	int area = (abs(x2 - x1) + abs(x2 - x1 - 60)) / 2 * (y2 - y1), perimetr = (abs(x2 - x1) + abs(x2 - x1 - 60)) * 2;
	double x = abs(x2 - x1) / 2, y = abs(y2 - y1) / 2;
	return QString("Area: %1, Perimetr: %2, Center: (%3,%4)").arg(area).arg(perimetr).arg(x).arg(y);
}


void Trapezoid::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	this->setPos(mapToScene(event->pos()));
}

void Trapezoid::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	this->setCursor(QCursor(Qt::ClosedHandCursor));

	Q_UNUSED(event);
}

void Trapezoid::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{

	this->setCursor(QCursor(Qt::ArrowCursor));
	Q_UNUSED(event);
}

void Trapezoid::wheelEvent(QGraphicsSceneWheelEvent* event)
{
	if (event->delta() < 0)
		size -= 0.1;
	else size += 0.1;
}


void Trapezoid::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	delete this;
	Q_UNUSED(event);
}