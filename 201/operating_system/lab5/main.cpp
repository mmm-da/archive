#include <QtWidgets>
#include <windows.h>
#include <wchar.h>
#include "exporter.h"
#include "fileoperation.h"
int main (int argc,char* argv[]){
    QApplication* app = new QApplication (argc,argv);
    exporter widget;
    FileOperation file;
    file.write(widget.get_result_array(),QFileDialog::getSaveFileName(nullptr, "Сохранить ветку реестра","",("Бинарный файл реестра (*.breg)")));
    return app->exec();
}
