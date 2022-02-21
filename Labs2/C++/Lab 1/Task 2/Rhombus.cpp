#include "Rhombus.h"


Rhombus::Rhombus(int x1_ , int y1_, int x2_, int y2_, int x3_, int y3_, int x4_, int y4_)
	: x1(x1_), y1(y1_), x2(x2_), y2(y2_), x3(x3_), y3(y3_), x4(x4_), y4(y4_)
{

	diagonal_1 = abs(y1 - y3);
	diagonal_2 = abs(x2 - x4);
	size = 1; rot_angle = 0;

}



inline void Rhombus::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->rotate(rot_angle);
	rot_angle += 5;
	painter->setPen(Qt::black);
	painter->setBrush(Qt::blue);
	QPolygon pol;
	pol << QPoint(x1, y1) << QPoint(x2, y2) << QPoint(x3, y3) << QPoint(x4,y4);

	if (size != 1)
	{
		painter->scale(size, size);
	}
	painter->drawPolygon(pol);
	QTimer::singleShot(0, this, SLOT(update()));


	Q_UNUSED(option);
	Q_UNUSED(widget);
}


std::pair<double, int> Rhombus::area_and_perim()
{
	std::pair<double, int> pair_;
	int side = sqrt(pow(diagonal_1 / 2, 2) + pow(diagonal_2 / 2, 2));
	pair_.first = diagonal_1 * diagonal_2 * 2;
	pair_.second = side * 4;
	return pair_;
}


std::pair<double, double> Rhombus::center()
{
	std::pair<double, double> pair_;
	pair_.first = diagonal_1 / 2;
	pair_.second = diagonal_2 / 2;
	return pair_;
}
