#include "Canva.h"


Canva::Canva(QWidget* parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setBackgroundRole(QPalette::Base);

    draw = false;
    leftClick = false;
    move = false;
    setMouseTracking(true);
}


void Canva::setDraw(bool bDraw)
{
    this->draw = bDraw;
    pointList.clear();
}


void Canva::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    if (draw)
    {
        painter.setPen(Qt::darkBlue);
        QVector<QLineF> lines;
        for (int i = 0; i < pointList.size() - 1; i++)
        {
            QLineF line(QPointF(pointList[i].x(), pointList[i].y()), QPointF(pointList[i + 1].x(), pointList[i + 1].y()));
            lines.push_back(line);
        }
        if (move && pointList.size() > 0)
        {
            QLineF line(QPointF(pointList[pointList.size() - 1].x(), pointList[pointList.size() - 1].y()), move_point);
            lines.push_back(line);
        }
        painter.drawLines(lines);
    }
}


void Canva::mousePressEvent(QMouseEvent* e)
{
    if (draw)
    {
        if (!leftClick)
        {
            pointList.clear();
            leftClick = true;
        }
    }
}


void Canva::mouseMoveEvent(QMouseEvent* event)
{
    if (draw && leftClick)
    {
        move_point = event->pos();
        move = true;
        this->update();
    }
}

void Canva::mouseReleaseEvent(QMouseEvent* e)
{
    if (draw && leftClick)
    {
        pointList.push_back(QPointF(e->x(), e->y()));
        move = false;
        this->update();
    }
}

void Canva::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (draw)
    {
        leftClick = false;
        pointList.push_back(pointList[0]);
        this->update();
        drawOver();
    }
}

