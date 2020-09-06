#include "exporter.h"
#include <QDebug>

exporter::exporter(QWidget *parent) : QWidget(parent){
    this->root = HKEY_CURRENT_USER;
    bool is_valid_branch_name = false;
    while(!is_valid_branch_name){
        this->branch_str = QInputDialog::getText(nullptr,QString("Экспорт ветки реестра"),QString("Введите имя ветки для экспорта"));
        if(branch_str.length()==0){
            is_valid_branch_name = true;
            exit(0);
        }
        is_valid_branch_name = validate_branch_name();
    }


    char subkey_name_buffer[255];  
    DWORD subkey_name_buffer_size;  
    DWORD subkey_count = 0;

    DWORD longest_subkey_size;
    DWORD longest_class_string;

    char subkey_value_buffer[255];  
    DWORD subkey_value_buffer_size;  
    DWORD values_count;
    
    DWORD longest_value_name;
    DWORD longest_value_data;

    DWORD sec_desc;
    FILETIME flwt;
    
    HKEY test_key;
    DWORD str_size = 255;
    str_size = (DWORD)this->branch_str.length();
    char* test_char_name = (char*) malloc((int)str_size);
    QByteArray temp_arr = this->branch_str.toLocal8Bit();
    strcpy(test_char_name,temp_arr.constData());

    RegOpenKeyExA(this->root,test_char_name,str_size,KEY_READ,&test_key);
    RegQueryInfoKeyA(test_key,
                     test_char_name,
                     &str_size,
                     NULL,
                     &subkey_count,
                     &longest_subkey_size,
                     &longest_class_string,
                     &values_count,
                     &longest_value_name,
                     &longest_value_data,
                     &sec_desc,
                     &flwt);

    char char_subkey_count;
    if(subkey_count>255){
        char_subkey_count = 255;
    }else{
        char_subkey_count = subkey_count;
    }

    char char_values_count;
    if(values_count>255){
        char_values_count = 255;
    }else{
        char_values_count = values_count;
    }

    //(1 byte) Заголовок [2d] 
    //(1 byte) Сепаратор [28d]
    //(N byte) Название ключа
    //(1 byte) Конец строки [0d]
    //(1 byte) Сепаратор [28d]
    //(1 byte) Кол-во дочерних ключей [0-255d]
    //(1 byte) Сепаратор [28d]
    //(1 byte) Кол-во значений [0-255d]
    //(1 byte) Начало начало перечисления дочерних ключей [29d]

        //0-255 дочерних ключа
        //(1 byte) Сепаратор [30d]
        //(N byte) Конец строки [0d]
    //(1 byte) Начало начало перечисления значений ключа [29d]
        //0-255 дочерних ключа
        //(N byte) значение
        //(1 byte) Сепаратор [30d]
        //(N byte) значение
    //(1 byte) Конец передачи [4d]

    if(branch_str.length()>255){
        exit(1);
    }
    result.append((char)2);
    result.append((char)28);
    result.append(this->branch_str.toLatin1());
    result.append((char)0);
    result.append((char)28);
    result.append(char_subkey_count);
    result.append((char)28);
    result.append(char_values_count);
    result.append((char)29);
    for(int index = 0;index<char_subkey_count;index++){
        char subkey_name[255];
        DWORD cbName = 255;
        if(RegEnumKeyExA(test_key,index,subkey_name,&cbName,NULL,NULL,NULL,NULL)==ERROR_SUCCESS){
            result.append(subkey_name);
            result.append((char)0);
        }
    }
    result.append((char)29);
    for(int index = 0;index<char_values_count;index++){
        char value_name[255];
        QByteArray str = QByteArray(value_name);
        DWORD cbName = 255;
        DWORD valueType;
        unsigned char *valueData = (unsigned char*)malloc(longest_value_data);
        unsigned long valueDataSize;
        if(RegEnumValueA(test_key,index,value_name,&cbName,NULL,&valueType,valueData,&valueDataSize)==ERROR_SUCCESS){
            result.append(str);
            result.append((char)0);
            result.append((char)valueType);
            result.append((char)valueDataSize);
            switch (valueType) {
                case REG_BINARY:{
                    QByteArray temp;
                    for(int pointer = 0;pointer<valueDataSize;pointer++){
                        temp.append(valueData[pointer]);
                    };
                    result.append(temp);
                    break;
                }
                case REG_DWORD_LITTLE_ENDIAN:{
                    QByteArray temp;
                    for(int pointer = 0;pointer<valueDataSize;pointer++){
                        temp.append(valueData[pointer]);
                    };
                    result.append(temp);
                    std::reverse(temp.begin(),temp.end());
                    break;}
                case REG_DWORD_BIG_ENDIAN:{
                    QByteArray temp;
                    for(int pointer = 0;pointer<valueDataSize;pointer++){
                        temp.append(valueData[pointer]);
                    };
                    result.append(temp);
                    break;}
                case REG_EXPAND_SZ:{
                    QByteArray temp;
                    for(int pointer = 0;pointer<valueDataSize;pointer++){
                        temp.append(valueData[pointer]);
                    };
                    result.append(temp);
                    break;}
                case REG_LINK:{
                    QByteArray temp;
                    for(int pointer = 0;pointer<valueDataSize;pointer++){
                        temp.append(valueData[pointer]);
                    };
                    result.append(temp);
                    break;}
                case REG_MULTI_SZ:{
                    QByteArray temp;
                    for(int pointer = 0;pointer<valueDataSize;pointer++){
                        temp.append(valueData[pointer]);
                    };
                    result.append(temp);
                    break;}
                case REG_NONE:{
                    QByteArray temp;
                    for(int pointer = 0;pointer<valueDataSize;pointer++){
                        temp.append(valueData[pointer]);
                    };
                    result.append(temp);
                    break;}
                case REG_QWORD:{
                    QByteArray temp;
                    for(int pointer = 0;pointer<valueDataSize;pointer++){
                        temp.append(valueData[pointer]);
                    };
                    result.append(temp);
                    break;}
                case REG_SZ:{
                    QByteArray temp;
                    for(int pointer = 0;pointer<valueDataSize;pointer++){
                        temp.append(valueData[pointer]);
                    };
                    result.append(temp);
                    break;}
                result.append((char)28);
            }
        }
    }
    result.append((char)4);
    qDebug() << result;
}

bool exporter::validate_branch_name(){
    HKEY test_key;
    DWORD str_size = 255;
    str_size = (DWORD)this->branch_str.length();
    char* test_char_name = (char*) malloc((int)str_size);
    QByteArray temp_arr = this->branch_str.toLocal8Bit();
    strcpy(test_char_name,temp_arr.constData());

    LSTATUS return_value;
    return_value = RegOpenKeyExA(this->root,test_char_name,str_size,KEY_READ,&test_key);

    RegCloseKey(test_key);
    if(return_value == ERROR_SUCCESS){
        return true;
    }else{
        return false;
    }
};

QByteArray exporter::get_result_array(){
    return this->result;
};
