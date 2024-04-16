// чтение матрицы
/*#include<iostream>
#include<fstream>
using namespace std;
bool Is_Triangular_lower(int**, int);
int** Read_M(ifstream&, int&);
void Print_M(ofstream&, int**, int n);
int main() {
	int n;
	ifstream fin("in.txt");//через , можно добавить параметры
	if (!fin) {
		cout << "Error opened file"<<endl;
		return 0;
	}
	/*int** a = Read_M(fin, n);//читаем поток
	ofstream bb("rez.txt");//через , можнодобавить парамеры
	if (Is_Triangular_lower(a, n)) Print_M(bb, a, n);
	fin.close();*/
	/*cin >> n;
	cout << n << ' ' << &n << endl;
	int* a=new int[4];
	*a = 4;//по адресу а положил 4
	cout << *a << ' ' <<a<< endl;
	return 0;
}
bool Is_Triangular_lower(int** a, int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i][j] != 0) return false;
		}
	}
	return true;
}
int** Read_M(ifstream& f, int& n) {
	f >> n;
	int** a = new int* [n];
	for (int j = 0; j < n; ++j) {
		a[j] = new int[n];
		for (int i = 0; i < n; ++i) {
			f >> a[j][i];
		}
	}
	return a;
}
void Print_M(ofstream& f, int** a, int n) {
	for (int j = 0; j < n; ++j) {
		a[j] = new int[n];
		for (int i = 0; i < n; ++i) {
			f << a[j][i] <<' ';
		}
		f << endl;
	}
}*/
// з 5 №22
/*#include<iostream>

using namespace std;
bool Good_Guy(int**, int&, int&);
int** Read_S(ifstream&, int&);
int main() {
	int n;
	ifstream file("input22.txt");//через , можно добавить параметры
	if (!file) {
		cout << "Error opened file" << endl;
		return 0;
	}
	int** a = Read_S(file, n);//читаем поток
	ofstream bb("rez.txt");//через , можнодобавить парамеры
	if (Is_Triangular_lower(a, n)) Print_M(bb, a, n);
	fin.close();
	return 0;
}*/
//дз
// столбцы чисел
// обратный порядок
// в22 з5
// з5 в5