#include "Triangle.h"
#include "Shape.h"

Triangle::Triangle(int x1_, int y1_, int x2_, int y2_, int x3_, int y3_)
	: x1(x1_), x2(x2_), x3(x3_), y1(y1_), y2(y2_), y3(y3_)
{
	a_side = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b_side = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	c_side = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

	rot_angle = 0; size = 1;
}


inline std::pair<double, int> Triangle::area_and_perim()
{
	std::pair<double, int> pair_;
	double p = (a_side + b_side + c_side) / 2;
	pair_.first = sqrt(p * (p - a_side) * (p - b_side) * (p - c_side));
	pair_.second = a_side + b_side + c_side;

	return pair_;
}


inline std::pair<double, double> Triangle::center()
{
	std::pair<double, double> pair_;
	pair_.first = (x1 + x2 + x3) / 3;
	pair_.second = (y1 + y2 + y3) / 3;
	return pair_;
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