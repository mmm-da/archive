#include <QtWidgets>
#pragma once

class Coordinate{
    private:
        QRectF screen;
        QPointF worldTopLeft,worldBottomRight;
    public:
        Coordinate(QRectF screen,);
        QRectF screen();
        void setScreen(QRectF screen);
        QPointF worldToScreen(QPointF worldPoint);
        QPointF screenToWorld(QPointF screenPoint);
}
