#include "Polygon3D.hpp"
#include <QtWidgets>
#pragma once


class Model3D{
    private:
        QList<Polygon3D> _list;
        QList<Polygon3D> renderList;

    public:
        Model3D();
        void operator() (QPainter *painter){
            for(int i = 0,size = renderList.size();i<size;i++){
                (renderList[i])(painter);
            };
        }

        void operator << (Polygon3D vector){
            _list.append(vector);
        }

        Model3D& operator= (Model3D right){
            if(this == &right){
                return *this;
            }
            this->_list = right._list;
            this->renderList=right.renderList;
            return *this;
        }
        Model3D operator * (QMatrix4x4 matr){
            QList<Polygon3D> tempList;
            for(int i = 0,size = renderList.size();i<size;i++){
                tempList.append(renderList[i]*matr);
            };
            renderList = tempList;
            return *this;
        }
        void multWithAfin(QMatrix4x4 matr);
        friend QDebug operator<<(QDebug stream, Model3D model){
            stream<<"Текущие полигоны для рендера\n";
            for(int i = 0,size = model.renderList.size();i<size;i++){
                stream<<model.renderList[i];
            };
            return stream;
        }
        QList<QPolygon> listPoly();
        void rotate(float angle,QVector3D vector);
        void translate(QVector3D vector);
        void scale(QVector3D vector);
        void resetAfin();
        void sortOriginModel(){
            qStableSort(_list.begin(),_list.end());
        };
        void sortRenderModel(){
            qSort(renderList.begin(),renderList.end());
        };
        
        void selectAndColorizePolygon(QPoint point){
            bool flag = true;
            auto i = renderList.rbegin();
            for (;(i!=renderList.rend())&&flag;i++){
                if((*i).containPoint(point)){
                    auto j=_list.rbegin();
                    for(;j!=_list.rend();j++){
                        if((*j).num()==(*i).num()){
                            qDebug() <<"render list: "<< (*i);
                            qDebug() <<"_list: "<< (*j);
                            (*i).setHighlight(!(*i).highlight());
                            (*j).setHighlight(!(*j).highlight());
                            qDebug() <<"render list: "<< (*i);
                            qDebug() <<"_list: "<< (*j);
                        }
                    }
                    flag = false;
                }
            }
        };
            /*
                Поиск полигона которому пренадлежит точка в списке полигонов для рендера.
                Поиск полигона в списке исходных с номером совпадающим с полигоном для рендера.
                Смена цвета.

            */

};
