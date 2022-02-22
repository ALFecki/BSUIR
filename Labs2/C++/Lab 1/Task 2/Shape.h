#pragma once


#include <QtWidgets/QMainWindow>
#include <qgraphicssceneevent.h>
#include <qtimer.h>
#include <qopengl.h>
#include <qevent.h>
#include <qobject.h>
#include <qcursor.h>
#include <qpainter.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qmovie.h>


class Shape : public QGraphicsScene, public QGraphicsItem
{
public:
	
	virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) {};
	QRectF boundingRect() const
	{
		return (QRect(0, 0, 1280, 720));
	}
	
	
};





