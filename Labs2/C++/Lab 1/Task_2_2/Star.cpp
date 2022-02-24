#include "Star.h"


Star::Star(int R, int r)
	: Rad_out(R), rad_in(r)
{
	x = Rad_out / 2; y = Rad_out / 2;
	rot_angle = 0;
	size = 1;
	points_x = new double[11];
	points_y = new double[11];

}


void Star::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->rotate(rot_angle);
	rot_angle += 0.5;
	



	painter->setPen(Qt::black);
	painter->setBrush(Qt::red);

	double grad = 0;

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			points_x[i] = x + rad_in / 2 * cos(grad * M_PI / 180);
			points_y[i] = y - rad_in / 2 * sin(grad * M_PI / 180);

		}
		else
		{
			points_x[i] = x + Rad_out * cos(grad * M_PI / 180);
			points_y[i] = y - Rad_out * sin(grad * M_PI / 180);

		}
		grad += 36;
	}
	points_x[10] = points_x[0];
	points_y[10] = points_y[0];


	QPainterPath star;
	star.moveTo(points_x[0], points_y[0]);
	for (int i = 0; i < 11; i++)
	{
		star.lineTo(points_x[i], points_y[i]);
	}

	painter->drawPath(star);

	if (size != 1)
	{
		painter->scale(size, size);
	}

	QTimer::singleShot(0, this, SLOT(update()));
	Q_UNUSED(option);
	Q_UNUSED(widget);


}


void Star::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	this->setPos(mapToScene(event->pos()));
}

void Star::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	this->setCursor(QCursor(Qt::ClosedHandCursor));

	Q_UNUSED(event);
}

void Star::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{

	this->setCursor(QCursor(Qt::ArrowCursor));
	Q_UNUSED(event);
}

void Star::wheelEvent(QGraphicsSceneWheelEvent* event)
{
	if (event->delta() < 0)
		size -= 0.1;
	else size += 0.1;
}


void Star::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
	delete this;
	Q_UNUSED(event);
}

QRectF Star::boundingRect() const
{
	return QRectF(-800, -800, 1600, 1600);
}