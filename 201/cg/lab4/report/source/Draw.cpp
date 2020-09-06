#include "Draw.hpp"
#include "Model3D.hpp"
#include "Polygon3D.hpp"
#include <float.h>

int mouseWheelCount = 200;
float Ccentral = 200+mouseWheelCount;
float Cparallel = FLT_MAX;
float KCab = qCos(M_PI_4)/2;
float KFree = qCos(M_PI_4);

//матрицы проектирования
QMatrix4x4 centralMatr = {1,0,0,0,0,1,0,0,0,0,0,0,0,0,-1/Ccentral,1};
QMatrix4x4 axMatrCab = {1,0,KCab,0,0,1,KCab,0,0,0,0,0,0,0,0,1};
QMatrix4x4 axMatrFree = {1,0,KFree,0,0,1,KFree,0,0,0,0,0,0,0,0,1};
QMatrix4x4 parallelMatr = {1,0,0,0,0,1,0,0,0,0,0,0,0,0,-1/Cparallel,1};
QMatrix4x4 ortoMatr = {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1};

Model3D genTaskModel(int n){
    Model3D resultModel;
    qreal step = 360.0/n;
    int i=0;
    QVector4D c1(0,0,0,1);
    QVector4D c2(0,0,1,1);
    QVector4D prevB1,b1(0,3,0,1);
    QVector4D prevB2,b2(0,2,1,1);
    QVector4D prevT1,t1(0,3,4,1);
    QVector4D prevT2,t2(0,2,4,1);
    //Polygon3D outerBottom= Polygon3D(QColor(0,0,0,0));
    //Polygon3D innerBottom= Polygon3D(QColor(0,0,0,0));
    QMatrix4x4 rotateM;
    Polygon3D tempPoly = Polygon3D(QColor(0,0,0,0));
    rotateM.setToIdentity();
    rotateM.rotate(step,QVector3D(0,0,1));
    do{
        
        prevB1 = b1;
        prevB2 = b2;
        prevT1 = t1;
        prevT2 = t2;

        b1 = rotateM*b1;
        b2 = rotateM*b2;
        t1 = rotateM*t1;
        t2 = rotateM*t2;
        //Верхняя кромка
        tempPoly = Polygon3D(QColor(0,0,0,0));
        tempPoly<<prevT1;
        tempPoly<<prevT2;
        tempPoly<<t2;
        tempPoly<<t1;
        resultModel<<tempPoly;
        
        //Внешнее дно
        tempPoly = Polygon3D(QColor(0,0,0,0));
        tempPoly<<c1;
        tempPoly<<b1;
        tempPoly<<prevB1;
        resultModel<<tempPoly;
        //Дно без разделения на сектора
        //outerBottom<<b1;

        //Внутреннее дно
        tempPoly = Polygon3D(QColor(0,0,0,0));
        tempPoly<<c2;
        tempPoly<<b2;
        tempPoly<<prevB2;
        resultModel<<tempPoly;
        //Дно без разделения на сектора
        //innerBottom<<b2;

        //Внешняя грань
        tempPoly = Polygon3D(QColor(0,0,0,0));
        tempPoly<<prevT1;
        tempPoly<<prevB1;
        tempPoly<<b1;
        tempPoly<<t1;
        resultModel<<tempPoly;

        //Внутренняя грань
        tempPoly = Polygon3D(QColor(0,0,0,0));
        tempPoly<<prevT2;
        tempPoly<<prevB2;
        tempPoly<<b2;
        tempPoly<<t2;
        resultModel<<tempPoly;
        i++;
    }while(i<n);
    //resultModel<<outerBottom;
    //resultModel<<innerBottom;

    return resultModel;
};


DrawArea::DrawArea(){
    mouseRotateMatr.setToIdentity();
    projectionMatr = axMatrCab;
    QPoint lastPos= QPoint(0,0);
    resize(500,500);
    model=genTaskModel(10);
};

void DrawArea::reGenModel(int n){
    model=genTaskModel(n);
    this->update();
}

void DrawArea::selectProjection(int index){
    switch(index){
        case 0:
            projectionMatr = centralMatr;
        break;
        case 1:
            projectionMatr = axMatrCab;
        break;
        case 2:
            projectionMatr = axMatrFree;
        break;
        case 3:
            projectionMatr = parallelMatr;
        break;
    };
    this->update();
};

void DrawArea::paintEvent(QPaintEvent* event){
    //проверка полей
    if (this->width() < 40 || this->height() < 40) return;
    QPainter *painter = new QPainter(this);
    painter->setRenderHint(QPainter::HighQualityAntialiasing);
    Ccentral = 200+mouseWheelCount;
    centralMatr = {1,0,0,0,0,1,0,0,0,0,0,0,0,0,-1/Ccentral,1};
    //вычисление коэффицента маштабирования
    qreal scale_mult;
    if(this->height()>this->width()){
        scale_mult = this->width()/30;
    }
    else{
        scale_mult = this->height()/30;
    };
    QPoint p1 = QPoint(this->width()/4,this->height()/4);
    QPoint p2 = QPoint(3*this->width()/4,this->height()/4);
    QPoint p3 = QPoint(this->width()/4,3*this->height()/4);
    QPoint p4 = QPoint(3*this->width()/4,3*this->height()/4);
    //создания пера для границ
    QPen borderPen;
    borderPen.setWidth(2);
    borderPen.setColor(Qt::black);
    painter->setPen(borderPen);
    //фронтальная
    model.resetAfin();
    model.multWithAfin(ortoMatr);
    model.translate(QVector3D(p1.x(),p1.y(),1));
    model.scale(QVector3D(scale_mult,scale_mult,scale_mult));
    model(painter);
    //верх
    model.resetAfin();
    model.multWithAfin(ortoMatr);
    model.translate(QVector3D(p2.x(),p2.y(),1));
    model.rotate(90,QVector3D(1,0,0));
    model.scale(QVector3D(scale_mult,scale_mult,scale_mult));
    model(painter);
    //бок
    model.resetAfin();
    model.multWithAfin(ortoMatr);
    model.translate(QVector3D(p3.x(),p3.y(),1));
    model.rotate(90,QVector3D(1,0,0));
    model.scale(QVector3D(scale_mult,scale_mult,scale_mult));
    model(painter);
    //проектирование модели
    model.resetAfin();
    model.multWithAfin(projectionMatr);
    model.translate(QVector3D(p4.x(),p4.y(),1));
    model.scale(QVector3D(scale_mult,scale_mult,scale_mult));
    model.multWithAfin(mouseRotateMatr.transposed());
    model.rotate(90,QVector3D(1,0,0));
    model(painter);

    painter->end();
    event->accept();
};

void DrawArea::wheelEvent(QWheelEvent *event)
{
    QPoint numPixels = event->pixelDelta();
    mouseWheelCount += numPixels.x();
    this->update();
    event->accept();
}

void DrawArea::mousePressEvent(QMouseEvent *event){
    lastPos = event->pos();
};

void DrawArea::mouseMoveEvent(QMouseEvent *event){
    double k=10;
    QPoint dp =  event->pos() - lastPos;
    mouseRotateMatr.rotate(-dp.x()/k,QVector3D(0,1,0));
    mouseRotateMatr.rotate(dp.y()/k,QVector3D(1,0,0));
    lastPos = event->pos();
    this->update();
    event->accept();
}
