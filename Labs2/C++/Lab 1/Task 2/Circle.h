#pragma once
#define _USE_MATH_DEFINES

#include "Shape.h"
#include <cmath>


class Circle : public Shape
{
	Q_OBJECT;

public:
	
	Circle(int radius_ = 100);
	

private:
	
	int radius, rot_angle;
	double size, center;
	
	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

	QRectF boundingRect() const
	{
		return QRectF(-800, -800, 1600, 1600);
	}

	std::pair<double, int> area_and_perim();


	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event)
	{
		this->setPos(mapToScene(event->pos()));
	}

	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) {
		this->setCursor(QCursor(Qt::ClosedHandCursor));

		Q_UNUSED(event);
	}

	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {

		this->setCursor(QCursor(Qt::ArrowCursor));
		Q_UNUSED(event);
	}

	virtual void wheelEvent(QGraphicsSceneWheelEvent* event)
	{
		if (event->delta() < 0)
			size -= 0.1;
		else size += 0.1;
	}

	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
	{
		delete this;
		Q_UNUSED(event);
	}
};



class Hexagon : public Shape
{
public:
	Hexagon(int x1_ = -50, int y1_ = -100, int x2_ = -150, int y2_ = 0, int x3_ = -50, int y3_ = 100,
		int x4_ = 50, int y4_ = 100, int x5_ = 150, int y5_ = 0, int x6_ = 50, int y6_ = -100);


private:
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	double rot_angle, size;


	QRectF boundingRect() const
	{
		return QRectF(-800, -800, 1600, 1600);
	}

	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event)
	{
		this->setPos(mapToScene(event->pos()));
	}

	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) {
		this->setCursor(QCursor(Qt::ClosedHandCursor));

		Q_UNUSED(event);
	}

	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {

		this->setCursor(QCursor(Qt::ArrowCursor));
		Q_UNUSED(event);
	}

	virtual void wheelEvent(QGraphicsSceneWheelEvent* event)
	{
		if (event->delta() < 0)
			size -= 0.1;
		else size += 0.1;
	}

	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
	{
		delete this;
		Q_UNUSED(event);
	}

};