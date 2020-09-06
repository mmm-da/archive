#include "Model3D.hpp"

QList<QPolygon> Model3D::listPoly(){
    QList<QPolygon> result;
    for(int i=0,size=_list.size();i<size;i++){
        result.append(_list[i].qPolygon());
    };
    return result;
};
void Model3D::multWithAfin(QMatrix4x4 matr){
    QList<Polygon3D> tempList;
    for(int i = 0,size = renderList.size();i<size;i++){
        tempList.append(renderList[i]*matr);
    };
    renderList = tempList;
};

void Model3D::rotate(float angle,QVector3D vector){
    QMatrix4x4 r;
    r.setToIdentity();
    r.rotate(angle,vector);
    QList<Polygon3D> tempList;
    for(int i = 0,size = renderList.size();i<size;i++){
        tempList.append(renderList[i]*r);
    };
    renderList = tempList;
};
void Model3D::translate(QVector3D vector){
    QMatrix4x4 t;
    t.setToIdentity();
    t.translate(vector);
    QList<Polygon3D> tempList;
    for(int i = 0,size = renderList.size();i<size;i++){
        tempList.append(renderList[i]*t);
    };
    renderList = tempList;
};
void Model3D::scale(QVector3D vector){
    QMatrix4x4 s;
    s.setToIdentity();
    s.scale(vector);
    QList<Polygon3D> tempList;
    for(int i = 0,size = renderList.size();i<size;i++){
        tempList.append(renderList[i]*s);
    };
    renderList = tempList;
};

Model3D::Model3D(){

};

void Model3D::resetAfin(){
    renderList.clear();
    for(int i = 0,size = _list.size();i<size;i++){
        Polygon3D tempPoly = _list[i];
        tempPoly.setHighlight(_list[i].highlight());
        renderList.append(tempPoly);
    };
};
