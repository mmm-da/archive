#include <QtWidgets>
#pragma once

class Polygon3D{
    private:
        QList<QVector4D> _list;
        QColor _color;
    public:
        QColor color();
        void setColor(QColor color);
        Polygon3D(QColor color);
        void operator() (QPainter *painter){
            painter->save();
            painter->setBrush(color());
            painter->drawPolygon(qPolygon());
            painter->restore();
        }
        void operator << (QVector4D vect){
            _list.append(vect);
        }
        Polygon3D& operator= (Polygon3D right){
            if(this == &right){
                return *this;
            }
            this->_list = right._list;
            this->_color = right._color;
            return *this;
        }
        friend Polygon3D operator *(Polygon3D poly,QMatrix4x4 matr){
            Polygon3D result(poly.color());
            for(int i=0,size=poly._list.size();i<size;i++){
                result._list.append(matr*poly._list[i]);
            }
            return result;
        }
        QPolygon qPolygon();
        friend QDebug operator<<(QDebug stream,const Polygon3D poly){
            for(int i=0,size=poly._list.size();i<size;i++){
                stream<<"("<<poly._list[i].x()<<","<<poly._list[i].y()<<")\n";
            }
            stream<<"\n";
            return stream;
        }
};

QPoint vectToPoint(QVector4D vect);
