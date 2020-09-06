#include <string>
#include <iostream>
#include <stack>
#include "rpn.hpp"
using namespace std;

int main(){
    string str,result_str;
    vector<Token*> token_list;
    cout<<"Введите строку в инфиксной нотации - ";
    getline(cin,str);
    result_str = infix_to_postfix(str);
    cout<<result_str<<endl;
    token_list=str_to_token(result_str);
    cout<<"Результат = "<<calc_tokens(token_list);
    return 0;
}