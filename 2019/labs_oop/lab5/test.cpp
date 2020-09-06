#include <iostream>
#include <math.h>
using namespace std;

class Point{
    int x,y;
public:
    Point(int x1,int y1){
        this->x=x1;
        this->y=y1;
    }
    void set_x(int x1){this->x=x1;};
    void set_y(int y1){this->y=y1;};
    void set_xy(int x1,int y1){
        this->set_x(x1);
        this->set_y(y1);
    };
    int get_x(){
        return this->x;
    };
    int get_y(){
        return this->y;
    };
};

class Figure{
    Point center; // координаты центра фигуры.
public:
    Figure(Point t):center(t){};
    virtual double perimetr();
    virtual double area();
    virtual void print_info();
    virtual ~Figure(){}
};



int main(){
    Point test(1,2);
    cout << "x="<<test.get_x()<<"\ny="<<test.get_y();
    return 0;
}
