#pragma once
#include <QtWidgets/QMainWindow>
#include "qwidget.h"
#include "qgraphicsitem.h"
#include "qpainter.h"


class Unique_vizual : public QWidget, public QGraphicsItem
{
	Q_OBJECT

public:
	
	virtual QRectF boundingRect() const { return QRectF(-800, -800, 1600, 1600); }
	virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);


};

