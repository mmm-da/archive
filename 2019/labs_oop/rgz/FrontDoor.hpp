#include <QtWidgets>

class FrontDoorPanel: public QWidget{
    Q_OBJECT
    int correct_key;
    QHBoxLayout* layout;
    QPushButton* key_open,*call_open;
    public:
        FrontDoorPanel(int key):QWidget(),correct_key(key){
            layout = new QHBoxLayout();
            key_open = new QPushButton("Открыть ключем");
            call_open = new QPushButton("Позвонить в домофон");
            layout->addWidget(key_open);
            layout->addWidget(call_open);
            this->setLayout(layout);
            connect(key_open,SIGNAL(clicked()),this,SLOT(b_key_slot()));
            connect(call_open,SIGNAL(clicked()),this,SLOT(b_call_slot()));
        };
    signals:
        void b_key_click();
        void b_call_click();
        void record_open_door(int key);
        void record_wrong_key(int key);
    private slots:
        void b_key_slot();
        void b_call_slot();
};
