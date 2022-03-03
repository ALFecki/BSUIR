#pragma once


#include "Shape.h"


class Rhombus : public Shape
{
public:
	Rhombus(int x1_ = 0, int y1_ = -150, int x2_ = -100, int y2_ = 0, 
		int x3_ = 0, int y3_ = 150, int x4_ = 100, int y4_ = 0);

private:

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);


	int x1, x2, x3, x4, y1, y2, y3, y4;
	int diagonal_1, diagonal_2;
	double rot_angle, size;

	QRectF boundingRect() const
	{
		return QRectF(-800, -800, 1600, 1600);
	}

	std::pair<double, int> area_and_perim();
	std::pair<double, double> center();

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

