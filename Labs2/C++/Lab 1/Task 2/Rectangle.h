#pragma once

#include "Shape.h"


class Rectangle : public Shape
{

public:
	
	Rectangle(int width_ = 200, int height_ = 100, double rot_angle_ = 0);

private:

	int width, height;
	double size, rot_angle;

	virtual std::pair<double, int> area_and_perim();
	virtual std::pair<double, double> center();

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	virtual QRectF boundingRect() const
	{
		return QRectF(-800, -800, 1600, 1600);
	}

	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event)
	{
		this->setPos(mapToScene(event->pos()));
	}

	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event)
	{
		this->setCursor(QCursor(Qt::ClosedHandCursor));

		Q_UNUSED(event);
	}

	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
	{

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


class Square : public Rectangle
{
public:
	Square(int width = 200, double rot_angle_ = 0) : Rectangle(width, width, rot_angle_) {}

};


//class Rhombus : public Square
//{
//public:
//	Rhombus(int width = 200, double rot_angle_ = 45) : Square(width, rot_angle_) {}
//};

