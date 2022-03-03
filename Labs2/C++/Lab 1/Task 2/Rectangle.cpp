
#include "Rectangle.h"

Rectangle::Rectangle(int width_, int height_, double rot_angle_)
	: width(width_), height(height_),rot_angle(rot_angle_)
{
	size = 1;
}



inline void Rectangle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->rotate(rot_angle);
	rot_angle += 1;
	
	painter->setPen(Qt::black);
	painter->setBrush(Qt::red);
	
	if (size != 1)
	{
		painter->scale(size, size);
	}
	
	painter->drawRect(-width / 2, -height / 2, width, height);
	painter->drawPoint(QRectF(-width, -height, width, height).center());

	QTimer::singleShot(0, this, SLOT(update()));

	Q_UNUSED(option);
	Q_UNUSED(widget);

}


std::pair<double, int> Rectangle::area_and_perim()
{
	std::pair<double, int> pair_;
	pair_.first = width * height;
	pair_.second = (width + height) * 2;
	return pair_;
}

std::pair<double, double> Rectangle::center()
{
	std::pair<double, double> pair_;
	pair_.first = static_cast<double>(width) / 2;
	pair_.second = static_cast<double>(height) / 2;
	return pair_;
}




