#pragma once
#include "Shape.h"
class Triangle : public Shape
{
public:
	Triangle(int x1_, int y1_, int x2_, int y2_, int x3_, int y3_);
	QString infoAboutTriangle();

private:
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
	int x1, x2, x3, y1, y2, y3;
	double a_side, b_side, c_side;
	double rot_angle, size;

	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	virtual void wheelEvent(QGraphicsSceneWheelEvent* event);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
};

