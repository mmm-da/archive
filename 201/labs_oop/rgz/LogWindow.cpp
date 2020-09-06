#include "LogWindow.hpp"

void LogWindow::record_open_door(int apart_num){
    QString time_str = QTime::currentTime().toString();
    QString result_str = "["+time_str+"]. Открыта дверь. Квартира: "
        +QString::number(apart_num);
    this->list->addItem(result_str);
    this->log_stream<<result_str<<endl;
};
void LogWindow::record_connect_open(int apart_num){
    QString time_str = QTime::currentTime().toString();
    QString result_str = "["+time_str+"]. Звонок в дверь. Квартира: "
        +QString::number(apart_num);
    this->list->addItem(result_str);
    this->log_stream<<result_str<<endl;
};
void LogWindow::record_connect_close(int apart_num){
    QString time_str = QTime::currentTime().toString();
    QString result_str = "["+time_str+"]. Звонок сброшен. Квартира: "
        +QString::number(apart_num);
    this->list->addItem(result_str);
    this->log_stream<<result_str<<endl;
};
void LogWindow::record_open_with_key(int key){
    QString time_str = QTime::currentTime().toString();
    QString result_str = "["+time_str+"]. Дверь открыта ключем. Ключ: "
        +QString::number(key);
    this->list->addItem(result_str);
    this->log_stream<<result_str<<endl;
};
void LogWindow::record_wrong_key(int key){
    QString time_str = QTime::currentTime().toString();
    QString result_str = "["+time_str+"]. Попытка открыть дверь, ключ неверен. Ключ: "
        +QString::number(key);
    this->list->addItem(result_str);
    this->log_stream<<result_str<<endl;    
};

void LogWindow::save_log(){
    QString fileName = QFileDialog::getSaveFileName(this,tr("Сохранить лог"),"/home",tr("log (*.log)"));
    this->log->rename(fileName);
    this->log->close();
    this->log->setFileName(temp_filename);
    this->log->open(QIODevice::WriteOnly);
}; 
