#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <qmainwindow.h>
#include <qobject.h>
#include <qgraphicsitem.h>
#include <qgraphicssceneevent.h>
#include <qpainter.h>
#include <qtimer.h>
#include <qcursor.h>
#include <qgraphicsscene.h>
#include <qwidget.h>
#include <qmovie.h>

class Shape : public QObject, public QGraphicsItem
{
protected:
	virtual QRectF boundingRect() const { return QRectF(-800, -800, 1600, 1600);  }
	virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) {}

	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) {}
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) {}
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {}
	virtual void wheelEvent(QGraphicsSceneWheelEvent* event){}
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {}


};

