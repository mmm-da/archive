#include "Draw.hpp"
#include "Model3D.hpp"
#include "Polygon3D.hpp"
#include <float.h>

int mouseWheelCount = 200;
float Ccentral = 200+mouseWheelCount;
float Cparallel = FLT_MAX;
float KCab = qCos(M_PI_4)/2;
float KFree = qCos(M_PI_4);

QColor polyColor= QColor(0,0,0,125);
QColor clickedPolyColor= QColor(255,0,0);

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
    QVector4D prevK1,k1(0,3,2,1);
    QVector4D prevK2,k2(0,2,2,1);
    QVector4D prevT1,t1(0,3,4,1);
    QVector4D prevT2,t2(0,2,4,1);

    int count=0;
    QMatrix4x4 rotateM;
    Polygon3D tempPoly = Polygon3D(count);
    rotateM.setToIdentity();
    rotateM.rotate(step,QVector3D(0,0,1));
    do{
        
        prevB1 = b1;
        prevB2 = b2;
        prevT1 = t1;
        prevT2 = t2;
        prevK1 = k1;
        prevK2 = k2;

        b1 = rotateM*b1;
        b2 = rotateM*b2;
        t1 = rotateM*t1;
        t2 = rotateM*t2;
        k1 = rotateM*k1;
        k2 = rotateM*k2;
        
        //Верхняя кромка
        tempPoly = Polygon3D(count);
        count++;
        tempPoly.setNum(count);
        tempPoly<<prevT1;
        tempPoly<<prevT2;
        tempPoly<<t2;
        tempPoly<<t1;
        resultModel<<tempPoly;
        
        //Внешняя грань
        tempPoly = Polygon3D(count);
        count++;
        tempPoly.setNum(count);
        tempPoly<<prevK1;
        tempPoly<<prevB1;
        tempPoly<<b1;
        tempPoly<<k1;
        resultModel<<tempPoly;
        
        tempPoly = Polygon3D(count);
        count++;
        tempPoly.setNum(count);
        tempPoly<<t1;
        tempPoly<<k1;
        tempPoly<<prevK1;
        tempPoly<<prevT1;
        resultModel<<tempPoly;

        //Внутренняя грань
        tempPoly = Polygon3D(count);
        count++;
        tempPoly.setNum(count);
        tempPoly<<k2;
        tempPoly<<prevK2;
        tempPoly<<prevB2;
        tempPoly<<b2;
        resultModel<<tempPoly;

        tempPoly = Polygon3D(count);
        count++;
        tempPoly.setNum(count);
        tempPoly<<prevK2;
        tempPoly<<prevT2;
        tempPoly<<t2;
        tempPoly<<k2;
        resultModel<<tempPoly;

        tempPoly = Polygon3D(count);
        count++;
        tempPoly.setNum(count);
        tempPoly<<prevB2;
        tempPoly<<b2;
        tempPoly<<c2;
        resultModel<<tempPoly;
        
        tempPoly = Polygon3D(count);
        count++;
        tempPoly.setNum(count);
        tempPoly<<prevB1;
        tempPoly<<b1;
        tempPoly<<c1;
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
        scale_mult = this->width()/15;
    }
    else{
        scale_mult = this->height()/15;
    };
    QPoint p1 = QPoint(this->width()/2,2*this->height()/3);

    //создания пера для границ
    QPen borderPen;
    borderPen.setWidth(3);
    borderPen.setColor(Qt::white);
    painter->setPen(borderPen);

    //проектирование модели
    model.resetAfin();
    model.rotate(90,QVector3D(1,0,0));
    model.translate(QVector3D(0,2,1));
    model.multWithAfin(mouseRotateMatr.transposed());
    model.translate(QVector3D(0,-2,-1));
    model.scale(QVector3D(scale_mult,scale_mult,scale_mult));
    model.translate(QVector3D(p1.x(),p1.y(),1));
    model.sortRenderModel();
    model.multWithAfin(projectionMatr);
    if(needColorize){
    model.selectAndColorizePolygon(colorizePoint);
    needColorize = false;
    };
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

void DrawArea::mouseDoubleClickEvent(QMouseEvent *m_event){
    needColorize = true;
    colorizePoint = m_event->pos();
    qDebug() <<m_event->pos();
    this->update();
    m_event->accept();
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
