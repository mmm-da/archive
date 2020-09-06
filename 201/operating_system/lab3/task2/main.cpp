#include <QtWidgets>
#include <windows.h>
#include <wchar.h>
#include "mainwindow.hpp"

int main (int argc,char* argv[]){
    QApplication* app = new QApplication (argc,argv);
    MainWindow *t1 = new MainWindow;
    t1->setWindowTitle("Лабораторная работа №3. Задание 2.");
    t1->show();
    return app->exec();
}
