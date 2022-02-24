#pragma once
#include "Shape.h"
class Circle : public Shape
{
	Q_OBJECT

public:
	Circle(int radius_ = 100);
	QString infoAboutCircle();

private:
	int radius, rot_angle;
	double size, center;

	virtual QRectF boundingRect() const;
	
	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

	
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	virtual void wheelEvent(QGraphicsSceneWheelEvent* event);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);

};

class Hexagon : public Shape
{
public:
	Hexagon(int x1_ = -50, int y1_ = -100, int x2_ = -150, int y2_ = 0, int x3_ = -50, int y3_ = 100,
		int x4_ = 50, int y4_ = 100, int x5_ = 150, int y5_ = 0, int x6_ = 50, int y6_ = -100);
	QString infoAboutHexagon();


private:
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	double rot_angle, size;
	virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
	virtual  QRectF boundingRect() const;
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	virtual void wheelEvent(QGraphicsSceneWheelEvent* event);
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
};