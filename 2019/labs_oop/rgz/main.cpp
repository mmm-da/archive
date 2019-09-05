#include <QtWidgets>
#include "HousePhone.hpp"

int main(int argc, char *argv[]){
    QApplication app(argc,argv); 
    HouseConfig cfg;
    House house = cfg.get_result();
    return app.exec();     
};
