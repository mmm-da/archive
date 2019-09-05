#include <iostream>
#include "optimal_code.hpp"
#include <fstream>

#ifdef _WIN32
	#define CLEAR_SCR_CMD "clr"
#else
	#define CLEAR_SCR_CMD "clear"
#endif

using namespace std;

int main(){
	system(CLEAR_SCR_CMD);

	int alphabet_size,block_size;
	cout<<"Введите размер алфавита - ";
	cin>>alphabet_size;

	Alphabet a(alphabet_size);
	a.read();

	string word = "ECBBCCDACBAACAECDDFB";
	//cout<<"Введите слово для кодирования - ";
	//cin>>word;

	char coding_cycle = '1';
	while(coding_cycle!='0'){
		cout<<"Введите размер блока - ";
		cin>>block_size;
		Alphabet b=a.build_nsized_Alphabet(block_size);

		int code_type;
		cout<<"Выберите способ кодирования (1 - Шеннон-Фано, 2 - Хаффман) - ";
		cin>>code_type;

		a.build_code_arr(code_type);
		b.build_code_arr(code_type);

		a.print_codes();
		b.print_codes();

		cout<<endl;
		cout<<"Исходное слово - ";
		for(int i=0,size = word.length();i<size;){
			if(size-i>=block_size){
				cout<<word.substr(i,block_size)<<" ";
				i+=block_size;
			}
			else{
				cout<<word.substr(i,size-i);
				i+=size-i;
			};
		};
		cout<<endl;
		cout<<endl;

		string word_code_block = b.encode_text(word);

		cout<<"Длина блочного кода деленная на размер блока слова: "<<word_code_block.length()<<endl<<endl;

		cout<<"Продолжить работу программы? (0 - закончить) - ";
		cin>>coding_cycle;
};
}
