#include <QtWidgets>
#include <windows.h>
#include <wchar.h>
#include "view.h"
#include "fileoperation.h"
int main (int argc,char* argv[]){
    QApplication* app = new QApplication (argc,argv);
    view widget;
    widget.show();
    return app->exec();
}
