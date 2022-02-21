#include "Circle.h"


Circle::Circle(int radius_)
	: radius(radius_)
{
	size = 1; rot_angle = 0;
	center = radius / 2;
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

std::pair<double, int> Circle::area_and_perim()
{
	std::pair<double, int> pair_;
	pair_.first = M_PI * pow(radius, 2);
	pair_.second = 2 * M_PI * radius;
	return pair_;
}



Hexagon::Hexagon(int x1_, int y1_, int x2_, int y2_, int x3_, int y3_,
	int x4_, int y4_, int x5_, int y5_, int x6_, int y6_) 
	: x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_), x4(x4_), y4(y4_), x5(x5_), y5(y5_), x6(x6_), y6(y6_)
{
	size = 1; rot_angle = 0;

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