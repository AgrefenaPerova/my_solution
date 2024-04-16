//дз

//5ая задача свой вариант
/*
#include<iostream>
#include<string>
#include<cmath>
bool Equal(int a) {
	int b = a % 10;//121 1
	std::string s = std::to_string(a);
	int c = a / (pow(10,(s.length()-1)));
	if (b == c) return true;
	return false;
}
void Print_Array(int* a, int& l) {
	for (int i = 0; i < l; ++i) {
		if (a[i] != 0) std::cout << a[i]<<std::endl;
	}
}
int main() {
	int n;
	std::cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		array[i] = a;
		if (!Equal(a)) array[i] = 0;
	}
	Print_Array(array, n);
	return 0;
}
*/
//1102
// one:out output puton
// puton: in input one
//out put
//in puton
//one
/*
#include<iostream>
#include<string>
std::string Yes_or_no(std::string& s, int& l) {
	std::string s1 = s;
	for (int i = 0, j = l - 1; i < j; i++, j--) {
		std::swap(s1[i], s1[j]);
	}
	for (int i = 0; i < l; ++i) {
		std::string str = s1.substr(i, 2);
		if (str == "ni") {
			i += 1;
			continue;
		}
		str = s1.substr(i, 3); // берем до тройки 

		if (str == "tuo" || str == "eno") {

			i += 2;
			continue;
		}
		str = s1.substr(i, 5);
		if (str == "tupni") {
			i += 4;
			continue;
		}

		if (str == "notup") {
			i += 4;
			continue;
		}
		str = s1.substr(i, 6);
		if (str == "tuptuo") {
			i += 5;
			continue;
		}
		return  "NO";
	}
	return "YES";
}
void Print_yes_or_no(std::string* ans, int& l) {
	for (int i = 0; i < l; ++i) {
		std::cout << ans[i] << std::endl;
	}
}
int main() {
	int n;
	std::cin >> n;
	std::string* ans = new std::string[n];
	for (int i = 0; i < n; ++i) {
		std::string s = "";
		std::cin >> s;
		int l = s.length();
		ans[i] = Yes_or_no(s, l);

	}
	Print_yes_or_no(ans, n);
	return 0;
}
*/
//1656
/*
#include<iostream>
void Sort_Army(int* a, int& l) {
	int now, temp;
	for (int i = 1; i < l; ++i) {
		now = a[i];
		for (int j = i - 1; j >= 0 && a[j] > now; --j) {
			temp = a[j + 1];
			a[j + 1] = a[j];
			a[j] = temp;
		}
	}
}
void Print_Army(int* a, int& l2, int&l) {
	
}
int main() {
	int n;
	std::cin >> n;
	int n2 = n * n;
	int* army = new int[n2];
	for (int i = 0; i < n2; ++i) {
		std::cin >> army[i];
	}
	Sort_Army(army, n2);
	std::cout << std::endl;
	Print_Army(army, n2, n);
	return 0;
}
*/
//1404
/*
#include <iostream>
#include <string>
using namespace std;
int main() {
	std::string s;
	cin >> s;
	int l = s.length();
	int a[200] = { 5 };
	for (int i = 0; i < l; i++) a[i + 1] = (s[i] - 'a');
	int n = l;
	for (int i = n; i >= 1; i--) {
		a[i] -= a[i - 1];
		if (a[i] < 0) a[i] += 26;
	}
	for (int i = 1; i <= n; i++) cout << (char)(a[i] + 'a');
	return 0;
}
*/
//2033
/*
#include<iostream>
int In_Array(std::string& a, std::string* s) {
	int k = 0;
	for (int i = 1; i < 12; i+=2) {
		if (a == s[i]) k++;
	}
	return k;
}
std::string Answer(std::string* s, int* a) {
	int mx = 0, k = 0;
	for (int i = 1; i < 12; i+=2) {
		a[i]=In_Array(s[i], s);
	}
	for (int i = 1; i < 12; i += 2) {
		if (mx < a[i]) {
			mx = a[i];
			k = i;
		}
		else if (mx == a[i]) {
			if (a[i-1] < a[k - 1]) k = i;
		}
	}
	return s[k];
}
int main() {
	int ans[12];
	std::string friends[12];
	for (int i = 0; i < 12; i+=2) {
		std::cin >> friends[i];
		std::cin >> friends[i + 1];
		std::cin >> ans[i];
	}
	std::cout << Answer(friends, ans);
	return 0;
}
*/
//либо 1603 либо конь(1298)
/*
#include <iostream>
using namespace std;
int direct[8][2] = { {2, 1}, {1, 2}, {-1,2}, {-2, 1},{-2,-1}, {-1,-2}, {1, -2},{2, -1} };
int x[64];
int y[64];
char alphabet[10] = "zabcdefgh";
int Table[9][9];
int n, k;

struct Point {
	char x;
	int y;
};
Point* path = new Point[64];
bool OK(int i, int j) {
	return (i >= 1) && (i <= n) && (j >= 1) && (j <= n) && (!Table[i][j]);
}
void Game(int x, int y) {
	int dx, dy;
	path[k].x = alphabet[x];
	path[k++].y = y;
	if (k == n * n) {
		for (int i = 0; i < k; i++) {
			cout << path[i].x << path[i].y << endl;
		}
		exit(0);
	}
	for (int i = 0; i < 8; i++) {
		dx = x + direct[i][0];
		dy = y + direct[i][1];
		if (OK(dx, dy)) {
			Table[dx][dy] = k;
			Game(dx, dy);
		}
	}
	Table[x][y] = 0;
	k--;
}
int main()
{
	cin >> n;
	if (n == 1) cout << "a1";
	else if (n > 4) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				Table[i][j] = 0;
			}
		}
		k = 0;
		Table[1][1] = 1;
		Game(1, 1);
	}
	else cout << "IMPOSSIBLE";
	return 0;
}
*/