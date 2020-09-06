#include "task1.hpp"

Task1::Task1(){
    QVBoxLayout *layout = new QVBoxLayout;

    SYSTEM_INFO info;
    GetSystemInfo(&info);

    //Архитектура процессора
    QHBoxLayout *lCpuArch = new QHBoxLayout;
    QLabel *nCpuArch = new QLabel(QString("Архитектура процессора"));
    QLabel *iCpuArch = new QLabel;
    QString strCpuArch;
    switch(info.wProcessorArchitecture){
        case PROCESSOR_ARCHITECTURE_AMD64:
            strCpuArch = "x64";
            break;
        case PROCESSOR_ARCHITECTURE_IA64 :
            strCpuArch = "Itanium";
            break;
        case PROCESSOR_ARCHITECTURE_INTEL :
            strCpuArch = "x86";
            break;
        default:
            strCpuArch = "Неизвестный тип";
            break;
    };
    iCpuArch->setText(strCpuArch);
    lCpuArch->addWidget(nCpuArch);
    lCpuArch->addWidget(iCpuArch);


    //Тип процессора
    QHBoxLayout *lCpuType = new QHBoxLayout;
    QLabel *nCpuType = new QLabel(QString("Тип процессора"));
    QLabel *iCpuType = new QLabel;
    QString strCpuType;
    switch(info.dwProcessorType){
        case PROCESSOR_INTEL_386:
            strCpuType = "i386";
            break;
        case PROCESSOR_INTEL_486:
            strCpuType = "i486";
            break;
        case PROCESSOR_INTEL_PENTIUM:
            strCpuType = "Intel Pentium";
            break;
        case PROCESSOR_INTEL_IA64:
            strCpuType = "Intel x64";
            break;
        case PROCESSOR_AMD_X8664 :
            strCpuType = "x64";
            break;
        default:
            strCpuType = "Неопознанно";
            break;
    };
    iCpuType->setText(strCpuType);
    lCpuType->addWidget(nCpuType);
    lCpuType->addWidget(iCpuType);

    //Размер страницы памяти
    QHBoxLayout *lPageSize = new QHBoxLayout;
    QLabel *nPageSize = new QLabel(QString("Размер страницы памяти"));
    QLabel *iPageSize = new QLabel;
    QString strPageSize = QString::number(info.dwPageSize) + QString(" байт");
    iPageSize->setText(strPageSize);
    lPageSize->addWidget(nPageSize);
    lPageSize->addWidget(iPageSize);

    //Указатель на младший адрес доступной памяти 
    QHBoxLayout *lMinimumApplicationAddress = new QHBoxLayout;
    QLabel *nMinimumApplicationAddress = new QLabel(QString("Младший адрес доступной памяти"));
    QLabel *iMinimumApplicationAddress = new QLabel;
    QString strMinimumApplicationAddress = QString("0x") + QString::number((int)info.lpMinimumApplicationAddress,16);
    iMinimumApplicationAddress->setText(strMinimumApplicationAddress);
    lMinimumApplicationAddress->addWidget(nMinimumApplicationAddress);
    lMinimumApplicationAddress->addWidget(iMinimumApplicationAddress);

    //Указатель на старший адрес доступной памяти 
    QHBoxLayout *lMaximumApplicationAddress = new QHBoxLayout;
    QLabel *nMaximumApplicationAddress = new QLabel(QString("Старший адрес доступной памяти"));
    QLabel *iMaximumApplicationAddress = new QLabel;
    QString strMaximumApplicationAddress = QString("0x") + QString::number((int)info.lpMaximumApplicationAddress,16);
    iMaximumApplicationAddress->setText(strMaximumApplicationAddress);
    lMaximumApplicationAddress->addWidget(nMaximumApplicationAddress);
    lMaximumApplicationAddress->addWidget(iMaximumApplicationAddress);

    //Количество процессоров
    QHBoxLayout *lCpuCount = new QHBoxLayout;
    QLabel *nCpuCount = new QLabel(QString("Количество логических процессоров"));
    QLabel *iCpuCount = new QLabel;
    QString strCpuCount = QString::number(info.dwNumberOfProcessors) + QString(" шт");
    iCpuCount->setText(strCpuCount);
    lCpuCount->addWidget(nCpuCount);
    lCpuCount->addWidget(iCpuCount);


    //Количество процессоров
    QHBoxLayout *lAllocationGranularity = new QHBoxLayout;
    QLabel *nAllocationGranularity = new QLabel(QString("Гранулярность для начального адреса виртуальной памяти"));
    QLabel *iAllocationGranularity = new QLabel;
    QString strAllocationGranularity = QString::number(info.dwAllocationGranularity);
    iAllocationGranularity->setText(strAllocationGranularity);
    lAllocationGranularity->addWidget(nAllocationGranularity);
    lAllocationGranularity->addWidget(iAllocationGranularity);

    //установка layout-ов
    layout->addLayout(lCpuArch);
    layout->addLayout(lCpuType);
    layout->addLayout(lPageSize);
    layout->addLayout(lMinimumApplicationAddress);
    layout->addLayout(lMaximumApplicationAddress);
    layout->addLayout(lCpuCount);
    layout->addLayout(lAllocationGranularity);
    this->setLayout(layout);
};
