#include "Polygon3D.hpp"

Polygon3D::Polygon3D(QColor color){
    _color = color;
};

QColor Polygon3D::color(){
    return _color;
};

void Polygon3D::setColor(QColor color){
    _color=color;
};

QPolygon Polygon3D::qPolygon(){
    QPolygon result;
    for(int i=0;i<_list.size();i++){
        result<<vectToPoint(_list[i]);
    };
    return result;
};

QPoint vectToPoint(QVector4D vect){
    QPoint result;
    result.setX(vect.x()/vect.w());
    result.setY(vect.y()/vect.w());
    return result;
};
