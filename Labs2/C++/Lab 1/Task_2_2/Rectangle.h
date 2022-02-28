#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
	Q_OBJECT
public:
	Rectangle(int, int, double);
	QString infoAboutRect();

private:
	int width, height;
	double size;
	double rot_angle;
	virtual QRectF boundingRect() const;
	virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	virtual void wheelEvent(QGraphicsSceneWheelEvent* event);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

};

class Square : public Rectangle
{
public:
	Square(int, double);
};


//class Rhombus : public Square
//{
//public:
//	Rhombus(int width, double rot_angle = 45)
//	{
//		Square(width, rot_angle);
//	}
//};
