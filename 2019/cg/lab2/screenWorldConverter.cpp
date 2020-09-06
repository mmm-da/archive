#include "Point.hpp"

Coordinate::Coordinate(QRect screen){
    this->setScreen(screen);
};
QRect Coordinate::screen(){
    return this->screen;
};
void Coordinate::setScreen(QRect screen){
    this->screen = screen;
};
QPointF Coordinate::worldToScreen(QPoint worldPoint){
    QPointF result;
    
    qreal X1 = screen.topLeft.x();
    qreal X2 = screen.topRight.x();
    qreal x1 = worldTopLeft.x();
    qreal x2 = worldBottomRight.x();
    qreal x = worldPoint.x();
    result.setX((X2-X1)*((x-x1)/(x2-x1))+X1);

    qreal Y1 = screen.topLeft.y();
    qreal Y2 = screen.bottomRight.y();
    qreal y1 = worldBottomRight.x();
    qreal y2 = worldTopLeft.y();
    qreal y = worldPoint.y();
    result.setY(Y2-(Y2-Y1)*((y-y1)/(y2-y1)));
    return result;
};

QPointF Coordinate::screenToWorld(QPoint screenPoint){
    QPointF result;
    
    qreal X1 = screen.topLeft.x();
    qreal X2 = screen.topRight.x();
    qreal x1 = worldTopLeft.x();
    qreal x2 = worldBottomRight.x();
    qreal X = screenPoint.x();
    result.setX(((x2-x1)/(X2-X1))*(X-X1)+x1);

    qreal Y1 = screen.topLeft.y();
    qreal Y2 = screen.bottomRight.y();
    qreal y1 = worldBottomRight.x();
    qreal y2 = worldTopLeft.y();
    qreal Y = screenPoint.y(((y2-y1)(Y2-Y1))*(Y2-Y)+y1);
    result.setY();
    return result;    
};