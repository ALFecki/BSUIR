#pragma once
#include "Shape.h"


class Rhombus : public Shape
{
public:
	Rhombus(int x1_, int y1_, int x2_, int y2_, int x3_, int y3_, int x4_, int y4_);
	QString infoAboutRhomb();

private:
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
	int x1, x2, x3, x4, y1, y2, y3, y4;
	int diagonal_1, diagonal_2;
	double side;
	double rot_angle, size;

	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	virtual void wheelEvent(QGraphicsSceneWheelEvent* event);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

};

class Trapezoid : public Shape
{
public:
	Trapezoid(int x1_, int y1_, int x2_, int y2_);
	QString infoAboutTrapezoid();

private:
	
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
	int x1, x2, y1, y2;
	double rot_angle, size;
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	virtual void wheelEvent(QGraphicsSceneWheelEvent* event);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
};