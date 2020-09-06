#pragma once
#include <QtWidgets>

const QString temp_filename = "temp.log";

class LogWindow: public QWidget{
    Q_OBJECT
    QListWidget* list;
    QPushButton* save_button;
    QFile* log;
    QTextStream log_stream;
    QHBoxLayout* layout;
    public: 
        LogWindow(){
            this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
            this->setWindowTitle(QString("Журнал событий"));
            list = new QListWidget();
            save_button = new QPushButton("Сохранить лог");
            log = new QFile(temp_filename); 
            log->remove();
            log->open(QIODevice::WriteOnly);
            log_stream.setDevice(log);
            layout = new QHBoxLayout();
            layout->addWidget(list);
            layout->addWidget(save_button);
            this->setLayout(layout);
            connect(this->save_button,SIGNAL(clicked()),this,SLOT(save_log()));
            connect(this->save_button,SIGNAL(clicked()),this->list,SLOT(clear()));
        };

    public slots:
        void save_log(); 
        void record_open_door(int apart_num);
        void record_connect_open(int apart_num);
        void record_connect_close(int apart_num);
        void record_open_with_key(int key);
        void record_wrong_key(int key);
};
