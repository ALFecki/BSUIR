#pragma once


#include "qpainter.h"
#include "qobject.h"
#include "qgraphicsitem.h"



class Rectangle : public QObject, public QGraphicsItem
{
private:

	int red, green, blue;
public:
	int x, y;
	Rectangle(int x_, int y_)
		: x(x_), y(y_)
	{
		this->red = rand() % 255;
		this->green = rand() % 255;
		this->blue = rand() % 255;
	}

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
	{
		painter->setPen(Qt::black);
		painter->setBrush(QColor(red, green, blue));
		painter->drawRect(x, y, 200, 150);
		red = rand() % 255;
		green = rand() % 255;
		blue = rand() % 255;
		Q_UNUSED(option);
		Q_UNUSED(widget);
	}

	QRectF boundingRect() const { return QRectF(-800, -800, 1600, 1600); }


};

