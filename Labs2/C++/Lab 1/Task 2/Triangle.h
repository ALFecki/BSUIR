#pragma once

#include "Shape.h"

class Triangle : public Shape
{
	Q_OBJECT;

public:
	Triangle(int x1_ = 0, int y1_ = -200, int x2_ = -400, int y2_ = 100, int x3_ = 400, int y3_ = 100);

	

private:

	int x1, x2, x3, y1, y2, y3;
	double a_side, b_side, c_side;
	double rot_angle, size;



	QRectF boundingRect() const
	{
		return QRectF(-800, -800, 1600, 1600);
	}

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);

	std::pair<double, int> area_and_perim();
		
	std::pair<double, double> center();

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

