#include "coin_base.hpp"

int main(){
    int mode, pos;
    record_arr base;
    char* filename;
    cout<<"Input filename: ";
    cin>>filename;
    base.open_records(filename);
    cout<<"Waiting command ..."<<endl;
    while (mode != '0'){
        mode = getchar();
        mode = tolower(mode);
        switch (mode){
            case 'e':
                cin >> pos;
                base.arr[pos].print_embed_record();
            break;
            case 'a':
                base.arr[base.size].read_record();
                base.size++;
            break;
            case 'p':
                for (int i = 0; i < base.size; i++){
                    cout<<i+1<<". ";
                    base.arr[i].print_title_record();
                    cout<<endl;
                }
            break;
            case 'r':
                cin >> pos;
                if (pos-1 > base.size){
                    cout << "unable to remove!" << endl;
                }
                base.remove_record(pos-1);
            break;
            case 's':
                base.save_records(filename);
            break;
            case 'q':
                base.save_records(filename);
                return 0;
            case 'h': 
                cout<<"Coin records base:"<<endl;
                cout<<"    h - show this page."<<endl;
                cout<<"    a - add coin record."<<endl;
                cout<<"    p - print all records."<<endl;
                cout<<"    s - save records file."<<endl;
                cout<<"    q - close programm and save records to origin file."<<endl;
                cout<<"    r X - remove coin record with index X."<<endl;
                cout<<"    e X - print embed info about coin."<<endl;

            break;
            default:
                cout<<"Unknown command. h to help"<<endl;
            break;
        }
    }
    return 0;
}
