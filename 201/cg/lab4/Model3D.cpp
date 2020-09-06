#include "Model3D.hpp"

QList<QPolygon> Model3D::listPoly(){
    QList<QPolygon> result;
    for(int i=0,size=_list.size();i<size;i++){
        result.append(_list[i].qPolygon());
    };
    return result;
};
void Model3D::multWithAfin(QMatrix4x4 matr){
    afinMatr = afinMatr*matr;
};

void Model3D::rotate(float angle,QVector3D vector){
    QMatrix4x4 r;
    r.setToIdentity();
    r.rotate(angle,vector);
    afinMatr = afinMatr*r;
};
void Model3D::translate(QVector3D vector){
    QMatrix4x4 t;
    t.setToIdentity();
    t.translate(vector);
    afinMatr = afinMatr*t;
};
void Model3D::scale(QVector3D vector){
    QMatrix4x4 s;
    s.setToIdentity();
    s.scale(vector);
    afinMatr = afinMatr*s;
};

Model3D::Model3D(){
    afinMatr.setToIdentity();
};

void Model3D::resetAfin(){
    afinMatr.setToIdentity();
};
