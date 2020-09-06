#include "view.h"
#include <QDebug>
#include <QList>
#include "fileoperation.h"
#include <QFileDialog>
#include <QLayout>
#include <QLabel>
view::view(QWidget *parent) : QWidget(parent){
    this->root = HKEY_CURRENT_USER;
    FileOperation file;
    this->arr = file.read(QFileDialog::getOpenFileName(nullptr, "Открыть ветку реестра","",("Бинарный файл реестра (*.breg)")));
    qDebug()<< this->arr;
    int current_arr_pointer = 0;
      if(arr[current_arr_pointer]!=(char)2){
          qDebug() << "Ошибка\n";
      }else current_arr_pointer+=2;
      qDebug() << "Заголовок прочитан";

      QString branch_name;
      while(arr[current_arr_pointer]!=(char)0){
          branch_name.append(QChar(arr[current_arr_pointer]));
          current_arr_pointer++;
      }
      current_arr_pointer+=2;
      qDebug() << branch_name;

      short count_of_subkey;
      short count_of_values;
      count_of_subkey = (short)arr[current_arr_pointer];
      current_arr_pointer+=2;
      count_of_values = (short)arr[current_arr_pointer];
      current_arr_pointer+=2;
      qDebug() << "Начало перечисления подключей";
      QList<QString> subkeys;
      for(int i=0; i< count_of_subkey;i++){
          QString subkey_name;
          while(arr[current_arr_pointer]!=(char)0){
              subkey_name.append(QChar(arr[current_arr_pointer]));
              current_arr_pointer++;
          }
          qDebug() << subkey_name << "\n";
          subkeys.append(subkey_name);
      }
      current_arr_pointer+=2;
      QString value_str = QString("Значения:\n");
      qDebug() << "Начало перечисления значений";
      for(int i=0;i<count_of_values;i++){
          QString subkey_name;
          while(arr[current_arr_pointer]!=(char)0){
              subkey_name.append(QChar(arr[current_arr_pointer]));
              current_arr_pointer++;
          }
          current_arr_pointer++;
          int type = arr[current_arr_pointer];
          current_arr_pointer++;
          int size = arr[current_arr_pointer];
          QByteArray temp;
          for(int ptr=0;ptr<size;ptr++){
              temp.append(arr[current_arr_pointer]);
              current_arr_pointer++;
          }
          if(type==REG_DWORD_LITTLE_ENDIAN){
              std::reverse(temp.begin(),temp.end());
          }
          current_arr_pointer++;
          QString type_str;
          switch(type){
          case REG_BINARY:{
              type_str = "REG_BINARY";
              break;
          }
          case REG_DWORD_LITTLE_ENDIAN:{
              type_str = "REG_DWORD_LITTLE_ENDIAN";
              break;}
          case REG_DWORD_BIG_ENDIAN:{
              type_str = "REG_DWORD_BIG_ENDIAN";
              break;}
          case REG_EXPAND_SZ:{
              type_str = "REG_EXPAND_SZ";
              break;}
          case REG_LINK:{
              type_str = "REG_LINK";
              break;}
          case REG_MULTI_SZ:{
              type_str = "REG_MULTI_SZ";
              break;}
          case REG_NONE:{
              type_str = "REG_NONE";
              break;}
          case REG_QWORD:{
              type_str = "REG_QWORD";
              break;}
          case REG_SZ:{
              type_str = "REG_SZ";
              break;}
          }
          value_str.append(" --- "+subkey_name+QString(" ")+type_str+QString(" ")+QString::number(size)+QString(" ")+QString(temp)+QString("\n\n"));
          qDebug() <<subkey_name << type << " " << size << " " << temp << "\n";
      };
    QVBoxLayout* layout = new QVBoxLayout();
    QLabel *lname = new QLabel(QString("Имя ветки реестра: ")+branch_name);
    QLabel *lsubkeys = new QLabel(QString("Кол-во дочерних ключей: ")+QString::number(count_of_subkey));
    QLabel *lvalues = new QLabel("Кол-во значений ключа: "+QString::number(count_of_values));
    QLabel *keys = new QLabel;
    QString key_str = QString("Дочерние ключи:\n");
    for(int i = 0;i<subkeys.length();i++){
        key_str.append(subkeys[i]+QString("\n"));
    };
    qDebug() << key_str;
    keys->setText(key_str);
    QLabel *values = new QLabel;
    values->setText(value_str);
    for(int i = 0;i<subkeys.length();i++){
        key_str.append(" --- "+subkeys[i]+QString("\n\n"));
    };
    layout->addWidget(lname);
    layout->addWidget(lsubkeys);
    layout->addWidget(lvalues);
    layout->addWidget(keys);
    layout->addWidget(values);
    this->setLayout(layout);
};


