#pragma once
#include <QtWidgets>

class Polygon3D{
    private:
        QList<QVector4D> _list;
        int number;
        bool highlight_flag = false;
    public:
        QList<QVector4D> vectorList(){
            return _list;
        };
        void setHighlight(bool flag){
            this->highlight_flag = flag;
        };
        bool highlight(){
            return highlight_flag;
        };
        QList<QVector4D> setVectorList(QList<QVector4D> points){
            this->_list=points;
        };
        int num(){
            return number;
        };
        void setNum(int num){
            number = num;
        }
        Polygon3D(int num);
        void operator() (QPainter *painter){
            painter->save();
            if(highlight_flag){
                painter->setBrush(QColor(255,0,0));
            }else{
                painter->setBrush(QColor(0,0,0,50));
            };
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
            this->number = right.number;
            this->highlight_flag = right.highlight_flag;
            return *this;
        }
        friend Polygon3D operator *(Polygon3D poly,QMatrix4x4 matr){
            Polygon3D result(poly.number);
            result.setHighlight(poly.highlight());
            for(int i=0,size=poly._list.size();i<size;i++){
                result._list.append(matr*poly._list[i]);
            }
            return result;
        }
        QPolygon qPolygon();
        friend QDebug operator<<(QDebug stream,const Polygon3D poly){
            stream<<poly.number<<" "<<poly.highlight_flag;
            stream<<"\n";
            return stream;
        }
        double baricenter(){
            double result = 0.0;
            double size = _list.size();
            for(int i = 0;i<size;i++){
                result += _list[i].z();
            }
            return result;
        }
        friend bool operator< (Polygon3D l,Polygon3D r){return l.baricenter()<r.baricenter();};
        bool containPoint(QPoint point){return this->qPolygon().containsPoint(point, Qt::OddEvenFill);};


};

QPoint vectToPoint(QVector4D vect);
