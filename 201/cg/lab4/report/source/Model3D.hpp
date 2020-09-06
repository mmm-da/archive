#include "Polygon3D.hpp"
#include <QtWidgets>
#pragma once

class Model3D{
    private:
        QList<Polygon3D> _list;
        QMatrix4x4 afinMatr;
    public:
        Model3D();
        void operator() (QPainter *painter){
            for(int i = 0,size = _list.size();i<size;i++){
                (_list[i]*afinMatr)(painter);
            }
        }

        void operator << (Polygon3D vector){
            _list.append(vector);
        }

        Model3D& operator= (Model3D right){
            if(this == &right){
                return *this;
            }
            this->_list = right._list;
            this->afinMatr=right.afinMatr;
            return *this;
        }
        Model3D operator * (QMatrix4x4 matr){
            this->afinMatr*matr;
            return *this;
        }
        void multWithAfin(QMatrix4x4 matr);
        friend QDebug operator<<(QDebug stream,const Model3D model){
            stream <<"Матрица афинных приобразований.\n"
                   << model.afinMatr
                   <<"\nТочки\n";
            for(int i = 0,size = model._list.size();i<size;i++){
                stream<<(model._list[i]*model.afinMatr);
            }
            return stream;
        }
        QList<QPolygon> listPoly();
        void rotate(float angle,QVector3D vector);
        void translate(QVector3D vector);
        void scale(QVector3D vector);
        void resetAfin();
};
