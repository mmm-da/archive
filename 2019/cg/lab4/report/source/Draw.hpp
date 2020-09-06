#include <QtWidgets>
#include "Model3D.hpp"
Model3D genTaskModel(int n);

class DrawArea:public QWidget{
    Q_OBJECT
    private:
        QMatrix4x4 mouseRotateMatr;
        Model3D model;
        QMatrix4x4 projectionMatr;
        QPoint lastPos;
    public:
        DrawArea();
        void paintEvent(QPaintEvent *event);
        void wheelEvent(QWheelEvent *event);
        void mouseMoveEvent(QMouseEvent *m_event);
        void mousePressEvent(QMouseEvent *event);
    public slots:
        void reGenModel(int n);
        void selectProjection(int index);
};
