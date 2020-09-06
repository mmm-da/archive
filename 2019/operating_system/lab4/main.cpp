#include <QtWidgets>
#include <windows.h>
#include <wchar.h>
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"

int main (int argc,char* argv[]){
    QApplication* app = new QApplication (argc,argv);
    QTabWidget *lab4 = new QTabWidget;
    Task1 *t1 = new Task1;  
    Task2 *t2 = new Task2;  
    Task3 *t3 = new Task3;  
    lab4->setWindowTitle("Лабораторная работа №4");
    lab4->addTab(t1,QString("Задание 1"));
    lab4->addTab(t2,QString("Задание 2"));
    lab4->addTab(t3,QString("Задание 3"));
    lab4->show();
    return app->exec();
}
