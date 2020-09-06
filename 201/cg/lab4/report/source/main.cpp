#include <QtWidgets>
#include "Draw.hpp"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DrawArea* l = new DrawArea;

    QWidget *settings = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *sName =new QLabel("Количество секторов:");
    QLabel *bSelect =new QLabel("Тип проектирования:");
    QSpinBox *s = new QSpinBox;
    QComboBox *b = new QComboBox;

    b->addItem(QString("Центральное проектирование"));
    b->addItem(QString("Косоугольное кабинетное проектирование"));
    b->addItem(QString("Косоугольное свободное проектирование"));
    b->addItem(QString("Параллельное проектирование"));
    s->setRange(3,4000);

    QObject::connect(s,SIGNAL(valueChanged(int)),l,SLOT(reGenModel(int)));
    QObject::connect(b,SIGNAL(currentIndexChanged(int)),l,SLOT(selectProjection(int)));

    layout->addWidget(sName);
    layout->addWidget(s);
    layout->addWidget(bSelect);
    layout->addWidget(b);
    settings->setLayout(layout);
    settings->show();
    l->show();
    return a.exec();
}
