#include "Unique_vizual.h"


void Unique_vizual::paint(QPainter* painter, const QStyleOptionGraphicsItem* item, QWidget* widget)
{
	painter->setPen(Qt::black);
	painter->setBrush(Qt::red);
	painter->drawRect(200, 200, 200, 100);
	painter->drawLine(400, 250, 500, 250);
	painter->setBrush(Qt::green);
	painter->drawEllipse(500, 150, 200, 200);


}