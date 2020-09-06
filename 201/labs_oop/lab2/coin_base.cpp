#include "coin_base.hpp"

void coin_size::read_size(){
    cout<<"Input coin sizes - ";
    cin>>this->l>>this->w>>this->t;
};
double coin_size::get_l(){
    return this->l;
};
double coin_size::get_w(){
    return this->w;
};
double coin_size::get_t(){
    return this->t;
};

void coin_discr::read(){
    cout<<"Input coin discription: ";
    cout<<"Weight - ";
    cin>>this->weight;
    cout<<"Condition (1-10) - ";
    cin>>this->condition;
    cout<<"Material (1 - silver, 2 - copper, 3 - gold, 4 - other) - ";
    cin>>this->material;
    this->s.read_size();
};

void coin_discr::print(){
    cout<<"Weight - "<<this->weight;
    cout<<"Condition (1-10) - "<<this->condition;
    cout<<"Material - ";
    switch(this->material){
        case 1:
            cout<<"Silver";
        break;
        case 2:
            cout<<"Copper";
        break;
        case 3:
            cout<<"Gold";
        break;
        default:
            cout<<"Other";
        break;
    };
    cout<<"Size - ("<<this->s.get_l()<<","<<this->s.get_w()<<","<<this->s.get_t()<<").";  
};

void coin::read(){
    cout<<"Input coin info:";
    cout<<"Value - ";
    cin>>value;
    cout<<"Country - ";
    cin>>country;
    cout<<"Year - ";
    cin>>year;
};
void coin::print(){
    cout<<value<<", "<<country<<", "<<this->year;
};

void coin_record::read_record(){
    this->c.read();
    this->discription.read();
};

void coin_record::print_title_record(){
    this->c.print();
};

void coin_record::print_embed_record(){
    this->c.print();
    this->discription.print();
};

void record_arr::init_records(){
    this->arr=new coin_record[this->size*2];
};

void record_arr::free_records(){
    free(this->arr);
};

void record_arr::open_records(char *datafile_name){
    ifstream data;
    data.open(datafile_name);
    data >> this->size;
    this->init_records();
    for (int i = 0; i < this->size; i++){
        data >> arr[i].c.value >> arr[i].c.country >> arr[i].c.year
        >> arr[i].discription.weight>> arr[i].discription.material >> arr[i].discription.condition
        >> arr[i].discription.s.l >> arr[i].discription.s.w>> arr[i].discription.s.t;
    }
    data.close();
};

void record_arr::save_records(char *datafile_name){
    ofstream data;
    data.open(datafile_name);
    data << this->size;
    for (int i = 0; i < this->size; i++){
        data << arr[i].c.value << arr[i].c.country << arr[i].c.year
        << arr[i].discription.weight << arr[i].discription.material << arr[i].discription.condition
        << arr[i].discription.s.l << arr[i].discription.s.w << arr[i].discription.s.t;
    }
    data.close();
}

int record_arr::search_value(char* value){
     for (int i = 0; i < this->size; i++){
        if (strcmp (arr[i].c.value, value) == 0){
            arr[i].print_embed_record();
            return i;
        }
    }
    cout << "-- not found --" << endl;
};


int record_arr::search_country(char* country){
     for (int i = 0; i < this->size; i++){
        if (strcmp (arr[i].c.country, country) == 0){
            arr[i].print_embed_record();
            return i;
        }
    }
    cout << "-- not found --" << endl;
};

int record_arr::remove_record(int key){
    swap(arr[key],arr[this->size-1]);
    this->size--;
};
