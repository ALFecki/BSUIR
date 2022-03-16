#pragma once

#include "qpainter.h"
#include "qobject.h"
#include "qgraphicsitem.h"

class Circle :	public QObject, public QGraphicsItem
{
private:

public:
	int red, green, blue;
	int x, y;
	Circle(){}
	
	Circle(int x_, int y_, int r, int g, int b)
		: x(x_), y(y_), red(r), green(g), blue(b)
	{

	}

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
	{
		painter->setPen(Qt::black);
		painter->setBrush(QColor(red, green, blue));
		painter->drawEllipse(x, y, 150, 150);
		Q_UNUSED(option);
		Q_UNUSED(widget);
	}

	QRectF boundingRect() const { return QRectF(-800, -800, 1600, 1600); }




};

