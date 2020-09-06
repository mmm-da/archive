#include "Polygon3D.hpp"

Polygon3D::Polygon3D(int num){
    number = num;
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
