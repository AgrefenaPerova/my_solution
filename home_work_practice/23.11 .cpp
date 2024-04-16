//дз
// столбцы чисел 1506
/*#include<iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n;
	cin >> k;
	string numbers[1000];
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}
	int count_numbers = n / k;
	if (n % k != 0) count_numbers++;
	for (int j = 0; j < count_numbers; ++j) {
		for (int i = 0; i < n; i += count_numbers) {
			int s = 4 - numbers[i+j].length();
			cout << string(s, ' ') << numbers[i+j];
		}
		cout << endl;
	}
	return 0;
}*/
// обратный порядок 1226 (нет)
/*#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	char str[1000][255];
	int j = 0,i = 0;
	while (getline(cin, s)) {
		if (s.empty())break;
		int l1 = s.length();
		for (int s1 = 0; s1 < l1; ++i) {
			if (s[s1] != ' ') str[i][s1] = s[s1];
		}
		i++;
	}
	for (int j = 0; j < i; ++j) {
		for (int x = 0; x < 255; ++x) {
			cout << str[j][x] << endl;
		}
	}
	int x = 0;
	while (x <= i){
		int l = str[x].length();
		string ans = str[x];
		if (l % 2 == 0)
			for (i = 0; i < l / 2; i++) {
				char tmp = ans[i];
				ans[i] = ans[l - 1 - i];
				ans[l - 1 - i] = tmp;
			}

		else
			for (i = 0; i < (l - 1) / 2; i++) {
				char tmp = ans[i];
				ans[i] = ans[l - 1 - i];
				ans[l - 1 - i] = tmp;
			}

		cout << ans << endl;
		x++;
	}
	
	return 0;
}*/
/*исходные данные
This is an example of a simple test.If you did not
understand the ciphering algorithm yet, then write the
letters of each word in the reverse order.By the way,
"reversing" the text twice restores the original text.

результат
sihT si na elpmaxe fo a elpmis tset.fI uoy did ton
dnatsrednu eht gnirehpic mhtirogla tey, neht etirw eht
srettel fo hcae drow ni eht esrever redro.yB eht yaw,
"gnisrever" eht txet eciwt serotser eht lanigiro txet.*/

// в22 з5 (нет)
/*
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string file;
	int k, n;
	ifstream in("4.txt");
	if (!in)
	{
		cout << "Error opened file" << endl;
		return 0;
	}

	in.close();
	return 0;
}*/
// з5 в5
/*
#include<iostream>
using namespace std;
bool Equality_last_and_first_digits_in_number(string s) {
	int l = s.length();
	if (l == 1) return false;
	if (s[0] == s[l-1]) return true;
	return false;
}
int main() {
	int n;
	cin >> n;
	string* arr = new string[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		if (Equality_last_and_first_digits_in_number(arr[i]))
			cout<<arr[i].c_str()<<' ';
	}
	return 0;
}*/
// з3 в5
/*
#include<iostream>
#include<string>
using namespace std;
bool Ar(int a, int b, int c) {
	if ((b - a) == (c - b)) return true;
	return false;
}
bool Geom(int a, int b, int c) {
	if (a != 0 && b != 0 && c != 0) {
		double da = (double)a;
		double db = (double)b;
		double dc = (double)c;
		if (((db / da == dc / db))) return true;
		else if (((da / db == db / dc))) return true;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	string* str = new string[n];
	for (int i = 0; i < n; ++i) {
		cin >> str[i];

	}
	bool ar = true;
	bool geom = true;
	bool write = true;
	for (int i = 0; i < n; ++i) {
		cout << str[i].c_str() << " it is ";
		int l = str[i].length();
		for (int j = 0; j < l - 2; ++j) {
			int a = (int)(str[i][j]) - '0', b = (int)(str[i][j + 1]) - '0', c = (int)(str[i][j + 2]) - '0';
			ar = Ar(a, b, c);
			geom = Geom(a, b, c);
		}
		if (geom && ar==false) {
			cout << "Geometric progression";
			write = false;
			cout << endl;
		}
		if (ar && geom==false) {
			cout << "Arithmetic progression";
			write = false;
			cout << endl;
		}
		if (ar == false && geom == false) {
			cout << "the usual number";
			write = false;
			cout << endl;
		}
		if (ar && geom && write) {
			cout << "this is uncertainty";
			cout << endl;
		}
	}
	//12
	//123 321 2468 8642 248 842 111 54321 980 34567 87654 369
	return 0;
}*/