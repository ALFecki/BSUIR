#pragma once
#include "Shape.h"
class Star : public Shape
{
public:
	Star(int R = 400, int r = 250);



private:
	int Rad_out, rad_in;
	double rot_angle, x, y, size;
	double* points_x, * points_y;


	virtual QRectF boundingRect() const;
	virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	virtual void wheelEvent(QGraphicsSceneWheelEvent* event);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
};

