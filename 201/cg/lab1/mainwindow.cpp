#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QRectF getCircleArea(qreal radius,QPointF center){
    QRectF area = QRectF(center.x() - radius, center.y() - radius, radius*2, radius*2);
    return area;
}

qreal to_rad(qreal angle){
    return angle*3.14/180;
}

QPolygonF get_n_poly(int count_of_sides,QPointF center,qreal radius){
    QPolygonF poly;
    qreal angle_step = to_rad(360.0/count_of_sides);
    qreal current_angle = 0;
    for(int i=0;i<count_of_sides;i++){
        poly << QPointF(radius*qCos(current_angle)+center.x(),radius*qSin(current_angle)+center.y());
        current_angle+=angle_step;
    }
    return poly;
}

QList<QPolygonF> get_polygons_from_points(QPolygonF points,QPointF center,int size){
    QList<QPolygonF> polygons;
    for(int i=0;i<size-1;i++){
        QPolygonF polygon;
        polygon<<points[i];
        polygon<<points[i+1];
        polygon<<center;
        polygons.push_back(polygon);
    }
    QPolygonF polygon;
    polygon<<points[size-1];
    polygon<<points[0];
    polygon<<center;
    polygons.push_back(polygon);
    return polygons;
};

QList<QConicalGradient> get_colors(QPointF center,int count,qreal angle){
    QList<QConicalGradient> colors;
    qreal angle_step = 360.0/count;
    qreal current_angle = 0;
    for(int i=0;i<count;i++){
        QConicalGradient color;
        QColor c1 = QColor();
        QColor c2 = QColor();
        color.setCenter(center);
        color.setAngle(current_angle);
        c1.setHsl(((int)current_angle)%360,100,100);
        c2.setHsl(((int)current_angle)%360,255,150);
        color.setColorAt(1,c2);    
        current_angle=current_angle+angle_step;
        colors.push_back(color);
    }
    return colors;
}

QPointF rotate(QPointF point,QPointF center,qreal angle){
    angle = to_rad(angle);
    qreal sin_A = qSin(angle);
    qreal cos_A = qCos(angle);
    QPointF temp_point = QPointF(point.x()-center.x(),point.y()-center.y());
    temp_point = QPointF(temp_point.x()*cos_A-temp_point.y()*sin_A,
                   temp_point.x()*sin_A+temp_point.y()*cos_A);
    return QPointF(temp_point.x()+center.x(),temp_point.y()+center.y());
}

QRectF rotate_QRectF(QRectF rect,QPointF center,qreal angle){
    rect.setBottomLeft(rotate(rect.bottomLeft(),center,angle));
    rect.setBottomRight(rotate(rect.bottomRight(),center,angle));
    rect.setTopLeft(rotate(rect.topLeft(),center,angle));
    rect.setTopRight(rotate(rect.topRight(),center,angle));
    return rect;
}

qreal hypotenuse (qreal side1,qreal side2){
    return qSqrt(qPow(side1,2)+qPow(side2,2));
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    //отмена отрисовки при недостатке места.
    if (width() < 40 || height() < 40) return;

    QPainter painter(this);
    //включение НОРМАЛЬНОГО антиалиасинга.
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    //установка пера.
    QColor penColor(0,0,0);
    QColor sectorPenColor(0,0,0,0);
    QPen borderPen(penColor,3);
    QPen sectorPen(sectorPenColor,0);
    painter.setPen(borderPen);
    //установка цветов.
    int colorCount = 5;
    QColor brushColors[colorCount];
    for(int i=0;i<colorCount;i++){
        brushColors[i].setHsl(((i+1)*250+angle/10)%359,(i+1*150)%255,150);
    }
    //центр окна
    QPointF center = QPointF(width() / 2, height() / 2);

    //радиусы кругов находящихся в треугольнике. круг с inner_radius3 вписан в треугольник.
    qreal inner_radius1,inner_radius2,inner_radius3;
    if (width() > height()){
        inner_radius1 = (height() - 20) /20;
        inner_radius2 = inner_radius1+(height()/30);
        inner_radius3 = inner_radius2+(height()/30);
    }else{
        inner_radius1 = (width() - 20) /20;
        inner_radius2 = inner_radius1+(width()/30);
        inner_radius3 = inner_radius2+(width()/30);
    }

    qreal a = 2*qSqrt(3)*inner_radius3;
    qreal outer_triangle_R = (qSqrt(3)/3)*a;
    
    QPolygonF outer_triangle;
    outer_triangle << QPointF(center.x(),center.y()-outer_triangle_R);
    outer_triangle << QPointF(center.x()+a/2,center.y()+inner_radius3);
    outer_triangle << QPointF(center.x()-a/2,center.y()+inner_radius3);
    for(int i=0;i<3;i++) outer_triangle[i] = rotate(outer_triangle[i],center,angle);

    qreal end_circle_radius = a/8;
    qreal a2_add = qSqrt((end_circle_radius*end_circle_radius)-(end_circle_radius/2*end_circle_radius/2));
    qreal a2 = a+2*a2_add;
    qreal circle_centers_R = qSqrt(6)/2*a2;
    qreal circle_centers_r = qSqrt(3)/2*a2;

    QPolygonF circle_centers;
    circle_centers << QPointF(center.x(),center.y()-outer_triangle_R-end_circle_radius);
    circle_centers << QPointF(center.x()+(a/2)+a2_add,center.y()+inner_radius3+end_circle_radius/2);
    circle_centers << QPointF(center.x()-(a/2)-a2_add,center.y()+inner_radius3+end_circle_radius/2);
    for(int i=0;i<3;i++) circle_centers[i] = rotate(circle_centers[i],center,angle);

    QPolygonF inner_poly = get_n_poly(n,center,inner_radius1);
    for(int i=0;i<n;i++) inner_poly[i] = rotate(inner_poly[i],center,angle);


    QList<QPolygonF> poly_arr = get_polygons_from_points(inner_poly,center,n);
    QList<QConicalGradient> colors = get_colors(center,n,angle);
    QRectF inner_circle_area1 = getCircleArea(inner_radius1,center);
    QRectF inner_circle_area2 = getCircleArea(inner_radius2,center);
    QRectF inner_circle_area3 = getCircleArea(inner_radius3,center);
    QRectF end_circle_area1 = getCircleArea(end_circle_radius,circle_centers[0]);
    QRectF end_circle_area2 = getCircleArea(end_circle_radius,circle_centers[1]);
    QRectF end_circle_area3 = getCircleArea(end_circle_radius,circle_centers[2]);

    painter.setBrush(brushColors[0]);
    painter.drawEllipse(end_circle_area1);
    painter.drawEllipse(end_circle_area2);
    painter.drawEllipse(end_circle_area3);
    painter.setBrush(brushColors[1]);
    painter.drawPolygon(outer_triangle);
    painter.setBrush(brushColors[2]);
    painter.drawEllipse(inner_circle_area3);
    painter.setBrush(brushColors[3]);
    painter.drawEllipse(inner_circle_area2);
    painter.setBrush(Qt::white);
    painter.drawEllipse(inner_circle_area1);
    painter.setPen(sectorPen);
    for(int i=0;i<n;i++){
        QBrush brush = QBrush(colors[i]);
        painter.setBrush(brush);
        painter.drawPolygon(poly_arr[i]);
        if(poly_arr[i].containsPoint(lastPos, Qt::OddEvenFill)){
            qDebug() << i+1 << " сегмент содержит выбранную точку\n";
        };
    };
    /*
    




    // Рисуем большой круг красно-оранжевым цветом

    // Рисуем ещё три круга меньшего диаметра и разными цветами
    float radiuses[3] = { radius*0.9f, radius*0.3f, radius*0.2f };
    // Инициализируем три кисти разного цвета
    QBrush brushes[3] = { QBrush(Qt::black),  QBrush(orangeRed),  QBrush(Qt::black) };
    */

};

void MainWindow::mousePressEvent(QMouseEvent *event){
        lastPos = event->pos();
    };
// Обработчик события прокрутки колеса мыши
void MainWindow::wheelEvent(QWheelEvent* wheelevent)
{
    angle -= wheelevent->delta()/10;
    repaint(); // Обновляем окно
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    n=arg1;
    repaint();
};
