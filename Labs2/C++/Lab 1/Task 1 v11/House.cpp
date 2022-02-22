#include "House.h"

House::House(int width_, int height_)
{
	width = width_; 
	height = height_;
}


void House::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(Qt::black);
	painter->setBrush(Qt::darkRed);
	painter->drawRect(0, 0, width, height);

	painter->setBrush(Qt::black);
	QPolygon pol;
	pol << QPoint(-50, 0) << QPoint(width + 50, 0) << QPoint(width / 2, -250);
	painter->drawPolygon(pol);

	painter->setBrush(Qt::white);
	painter->drawRect(50, 150, 150, 150); // left window
	painter->drawRect(width - 200, 150, 150, 150); // right window
	painter->drawRect(width / 2 - 75, 150, 150, 250); // door

	Q_UNUSED(option);
	Q_UNUSED(widget); 
}


QRectF House::boundingRect() const
{
	return QRectF(0, 0, 1280, 720);
}

QRectF Window::boundingRect() const
{
	return QRectF(0, 0, 1280, 720);
}

QRectF Door::boundingRect() const
{
	return QRectF(0, 0, 1280, 720);
}

void Window::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(Qt::black);
	painter->setBrush(Qt::gray);
	painter->drawRect(50, 150, 150, 150);
	painter->drawRect(700, 150, 150, 150);


}

Door::Door(int width_)
{
	width = width_;
}

void Door::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->setPen(Qt::black);
	painter->setBrush(Qt::darkBlue);
	painter->drawRect(375, 150, width, 250);
}
