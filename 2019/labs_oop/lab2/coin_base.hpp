#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
struct coin_size{
    double l;
    double w;
    double t;
    void read_size();
    double get_l();
    double get_w();
    double get_t();
};

struct coin_discr{
    double weight;
    coin_size s;
    //1 - серебро, 2 - медь, 3 - золото, 4 - прочее(биметал и тд).
    int material;
    int condition;
    void read();
    void print();
};

struct coin{
    char value[20];
    char country[20];
    unsigned year;
    void read();
    void print();
};

struct coin_record{
    coin c;
    coin_discr discription;
    void read_record();
    void print_title_record();
    void print_embed_record();
};

struct record_arr{
    coin_record *arr;
    int size=0;
    void init_records();
    void open_records(char *datafile_name);
    int search_value(char* value);
    int search_country(char* country);
    int remove_record(int key);
    void save_records(char *datafile_name);
    void free_records();

};