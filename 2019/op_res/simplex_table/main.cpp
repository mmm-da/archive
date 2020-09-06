#include <iostream>
#include "Simplex_shtraf.h"
#include "SimplexArtificial.h"

using namespace std;

int main(){
	long m, n;
	cout << "Введите кол-во строк и переменных: ";
	cin >> m >> n;
	Simplex_table C(m, n);
	cout << "Введите коэффициенты системы ограничений:" << endl;
	C.Input_SLU(cin);
	cout << "Введите коэффициенты целевой функции:" << endl;
	C.Input_Z(cin);
	C.Simplex();
}
