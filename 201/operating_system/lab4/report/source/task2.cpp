#include "task2.hpp"

Task2::Task2(){
    QVBoxLayout* layout = new QVBoxLayout;
    QGridLayout* plotLayout = new QGridLayout;


    customPlot1 = new QCustomPlot;
    customPlot2 = new QCustomPlot;
    customPlot3 = new QCustomPlot;
 
    QCPTextElement *title1 = new QCPTextElement(customPlot1);
    title1->setText("Физическая память");
    customPlot1->plotLayout()->insertRow(0);
    customPlot1->plotLayout()->addElement(0, 0, title1);

    QCPTextElement *title2 = new QCPTextElement(customPlot2);
    title2->setText("Файл подкачки");
    customPlot2->plotLayout()->insertRow(0);
    customPlot2->plotLayout()->addElement(0, 0, title2);
    
    QCPTextElement *title3 = new QCPTextElement(customPlot3);
    title3->setText("Виртуальная память");
    customPlot3->plotLayout()->insertRow(0);
    customPlot3->plotLayout()->addElement(0, 0, title3);

    customPlot1->xAxis->setLabel("время (сек)");
    customPlot1->yAxis->setLabel("Мбайт");
    customPlot2->xAxis->setLabel("время (сек)");
    customPlot2->yAxis->setLabel("Мбайт");
    customPlot3->xAxis->setLabel("время (сек)");
    customPlot3->yAxis->setLabel("Мбайт");

    memStatus.dwLength = sizeof(MEMORYSTATUSEX);
    
    dataTimer = new QTimer;
    dataTimer->setInterval(1000);

    customPlot1->yAxis->setTickLabels(false);
    connect(customPlot1->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot1->yAxis2, SLOT(setRange(QCPRange)));
    customPlot1->yAxis2->setVisible(true);
    customPlot1->axisRect()->addAxis(QCPAxis::atRight);
    customPlot1->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(30);
    customPlot1->legend->setVisible(true);
    
    customPlot2->yAxis->setTickLabels(false);
    connect(customPlot2->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot2->yAxis2, SLOT(setRange(QCPRange)));
    customPlot2->yAxis2->setVisible(true);
    customPlot2->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(30);
    customPlot2->legend->setVisible(true);
    
    customPlot3->yAxis->setTickLabels(false);
    connect(customPlot3->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot3->yAxis2, SLOT(setRange(QCPRange)));
    customPlot3->yAxis2->setVisible(true);
    customPlot3->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(30);
    customPlot3->legend->setVisible(true);

    //Общий объем физической памяти в мегабайтах
    customPlot1->addGraph()->setName("Обьем физической памяти.");
    customPlot1->graph(0)->setPen(QPen(QColor("#FF0000"),Qt::DotLine));
    customPlot1->graph(0)->setBrush(QBrush(QColor("#BBBF3030")));

    //Объем доступной физической памяти в байтах
    customPlot1->addGraph()->setName("Доступный обьем физической памяти.");
    customPlot1->graph(1)->setPen(QPen(QColor("#00CC00")));
    customPlot1->graph(1)->setBrush(QBrush(QColor("#EF269926")));

    //Размер файла подкачки в байтах
    customPlot2->addGraph()->setName("Обьем файла подкачки.");
    customPlot2->graph(0)->setPen(QPen(QColor("#FF0000"),Qt::DotLine));
    customPlot2->graph(0)->setBrush(QBrush(QColor("#BBBF3030")));

    //Доступный объем байтов в файле подкачки
    customPlot2->addGraph()->setName("Доступный обьем файла подкачки.");
    customPlot2->graph(1)->setPen(QPen(QColor("#00CC00")));
    customPlot2->graph(1)->setBrush(QBrush(QColor("#EF269926")));

    //Общий объем виртуальной памяти в байтах
    customPlot3->addGraph()->setName("Общий обьем виртуальной памяти.");
    customPlot3->graph(0)->setPen(QPen(QColor("#FF0000"),Qt::DotLine));
    customPlot3->graph(0)->setBrush(QBrush(QColor("#BBBF3030")));

    //Объем доступной виртуальной памяти
    customPlot3->addGraph()->setName("Доступный обьем виртуальной памяти .");
    customPlot3->graph(1)->setPen(QPen(QColor("#00CC00")));
    customPlot3->graph(1)->setBrush(QBrush(QColor("#EF269926")));
    
    mTag1_0 = new AxisTag(customPlot1->graph(0)->valueAxis());
    mTag1_1 = new AxisTag(customPlot1->graph(1)->valueAxis());
    mTag2_0 = new AxisTag(customPlot2->graph(0)->valueAxis());
    mTag2_1 = new AxisTag(customPlot2->graph(1)->valueAxis());
    mTag3_0 = new AxisTag(customPlot3->graph(0)->valueAxis());
    mTag3_1 = new AxisTag(customPlot3->graph(1)->valueAxis());
    mTag1_0->setPen(customPlot1->graph(0)->pen());
    mTag1_1->setPen(customPlot1->graph(1)->pen());
    mTag2_0->setPen(customPlot2->graph(0)->pen());
    mTag2_1->setPen(customPlot2->graph(1)->pen());
    mTag3_0->setPen(customPlot3->graph(0)->pen());
    mTag3_1->setPen(customPlot3->graph(1)->pen());

    connect(dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer->start(1000);

    QHBoxLayout* lMemUsage = new QHBoxLayout;
    QLabel* nMemUsage = new QLabel("Использование памяти (%): ");
    memUsage = new QProgressBar;
    memUsage->setMaximum(100);
    memUsage->setMinimum(0);
    lMemUsage->addWidget(nMemUsage);
    lMemUsage->addWidget(memUsage);

    layout->addLayout(lMemUsage);
    plotLayout->addWidget(customPlot1,0,0);

    plotLayout->addWidget(customPlot2,0,1);

    plotLayout->addWidget(customPlot3,1,0,1,2);

    layout->addLayout(plotLayout);
    this->setLayout(layout);
};

void Task2::realtimeDataSlot(){
    GlobalMemoryStatusEx(&memStatus);
    static double key = 0;
    key += 1;
    if(key == 1000){
        key=0;
        customPlot1->graph(0)->data()->clear();
        customPlot1->graph(1)->data()->clear();
        customPlot2->graph(0)->data()->clear();
        customPlot2->graph(1)->data()->clear();
        customPlot3->graph(0)->data()->clear();
        customPlot3->graph(1)->data()->clear();
    };
    memUsage->setValue((int)memStatus.dwMemoryLoad);
    customPlot1->graph(0)->addData(key,memStatus.ullTotalPhys/1024/1024);
    customPlot1->graph(1)->addData(key,memStatus.ullAvailPhys/1024/1024);
    customPlot2->graph(0)->addData(key,memStatus.ullTotalPageFile/1024/1024);
    customPlot2->graph(1)->addData(key,memStatus.ullAvailPageFile/1024/1024);
    customPlot3->graph(0)->addData(key,memStatus.ullTotalVirtual/1024/1024);
    customPlot3->graph(1)->addData(key,memStatus.ullAvailVirtual/1024/1024);
    
    customPlot1->graph(0)->rescaleAxes(true);
    customPlot1->graph(1)->rescaleAxes(true);
    customPlot2->graph(0)->rescaleAxes(true);
    customPlot2->graph(1)->rescaleAxes(true);
    customPlot3->graph(0)->rescaleAxes(true);
    customPlot3->graph(1)->rescaleAxes(true);

    mTag1_0->updatePosition(memStatus.ullTotalPhys/1024/1024);
    mTag1_1->updatePosition(memStatus.ullAvailPhys/1024/1024);
    mTag2_0->updatePosition(memStatus.ullTotalPageFile/1024/1024);
    mTag2_1->updatePosition(memStatus.ullAvailPageFile/1024/1024);
    mTag3_0->updatePosition(memStatus.ullTotalVirtual/1024/1024);
    mTag3_1->updatePosition(memStatus.ullAvailVirtual/1024/1024);

    mTag1_0->setText(QString::number(memStatus.ullTotalPhys / 1024 / 1024));
    mTag1_1->setText(QString::number(memStatus.ullAvailPhys / 1024 / 1024));
    mTag2_0->setText(QString::number(memStatus.ullTotalPageFile / 1024 / 1024));
    mTag2_1->setText(QString::number(memStatus.ullAvailPageFile / 1024 / 1024));
    mTag3_0->setText(QString::number(memStatus.ullTotalVirtual / 1024 / 1024));
    mTag3_1->setText(QString::number(memStatus.ullAvailVirtual / 1024 / 1024));

    customPlot1->replot();
    customPlot2->replot();
    customPlot3->replot();
};


AxisTag::AxisTag(QCPAxis *parentAxis) :
  QObject(parentAxis),
  mAxis(parentAxis)
{
  mDummyTracer = new QCPItemTracer(mAxis->parentPlot());
  mDummyTracer->setVisible(false);
  mDummyTracer->position->setTypeX(QCPItemPosition::ptAxisRectRatio);
  mDummyTracer->position->setTypeY(QCPItemPosition::ptPlotCoords);
  mDummyTracer->position->setAxisRect(mAxis->axisRect());
  mDummyTracer->position->setAxes(0, mAxis);
  mDummyTracer->position->setCoords(1, 0);
  mArrow = new QCPItemLine(mAxis->parentPlot());
  mArrow->setLayer("overlay");
  mArrow->setClipToAxisRect(false);
  mArrow->setHead(QCPLineEnding::esSpikeArrow);
  mArrow->end->setParentAnchor(mDummyTracer->position);
  mArrow->start->setParentAnchor(mArrow->end);
  mArrow->start->setCoords(15, 0);
  mLabel = new QCPItemText(mAxis->parentPlot());
  mLabel->setLayer("overlay");
  mLabel->setClipToAxisRect(false);
  mLabel->setPadding(QMargins(3, 0, 3, 0));
  mLabel->setBrush(QBrush(Qt::white));
  mLabel->setPen(QPen(Qt::blue));
  mLabel->setPositionAlignment(Qt::AlignLeft|Qt::AlignVCenter);
  mLabel->position->setParentAnchor(mArrow->start);
}
 
AxisTag::~AxisTag()
{
  if (mDummyTracer)
    mDummyTracer->parentPlot()->removeItem(mDummyTracer);
  if (mArrow)
    mArrow->parentPlot()->removeItem(mArrow);
  if (mLabel)
    mLabel->parentPlot()->removeItem(mLabel);
}
 
void AxisTag::setPen(const QPen &pen)
{
  mArrow->setPen(pen);
  mLabel->setPen(pen);
}
 
void AxisTag::setBrush(const QBrush &brush)
{
  mLabel->setBrush(brush);
}
 
void AxisTag::setText(const QString &text)
{
  mLabel->setText(text);
}
 
void AxisTag::updatePosition(double value)
{
  mDummyTracer->position->setCoords(1, value);
  mArrow->end->setCoords(mAxis->offset(), 0);
}