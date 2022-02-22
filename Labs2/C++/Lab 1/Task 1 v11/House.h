#pragma once

#include <QtWidgets/QMainWindow>
#include <qpainter.h>
#include <qwidget.h>
#include <qobject.h>
#include<qtimer.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>

class Window : public QGraphicsItem
{
public:

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	virtual QRectF boundingRect() const;

};


class Door : public Window
{
public:
	Door(int width_ = 150);
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	virtual QRectF boundingRect() const;
	int width = 150;
};


class House : public Door
{
	
private:
	
	int width, height;

public:
	House(int width_ = 900, int height_ = 400);
	~House() {};
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
	virtual QRectF boundingRect() const;

};




