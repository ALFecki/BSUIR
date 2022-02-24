#pragma once
#include <qwidget.h>
#include <qpainter.h>
#include <qevent.h>

class Canva : public QWidget
{
	Q_OBJECT

public:
	Canva(QWidget* parent = nullptr);
	void setDraw(bool draw);

signals:
	void drawOver();

protected:
	void paintEvent(QPaintEvent*);
	void mousePressEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent*);
	void mouseReleaseEvent(QMouseEvent*);
	void mouseDoubleClickEvent(QMouseEvent* event);

	bool draw, leftClick, move;
	QVector<QPointF> pointList;
	QPointF move_point;


};

