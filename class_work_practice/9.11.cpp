//классные работы 9.11
//1723
/*#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main() {
	string s,s_ans="";
	cin >> s;
	int c[26] = { 0 };
	int l = s.length(), k=0;
	for (int i = 0; i < l; ++i) {
		c[s[i] - 'a']++;
	}
	char maxe = 'a';
	for (char el = 'b'; el <= 'z'; ++el) {
		if (c[maxe-'a']<=c[el-'a']) maxe=
	}
	return 0;
}*/
//1297
/*#include<iostream>
#include<string>
#include<sstream>
using namespace std;
bool Check_Pol(string s, int i, int j) {
	for (int g = j; g < j/2; ++g) {
		if (s[g] != s[i - g - 1]) return false;
	}
	return true;
}
int main() {
	string s;
	cin >> s;
	int l = s.length();
	for (int i = l; i > 0; --i) {
		for (int j = 0; j <= l-i; ++j) {
			for (int g = j; g < (i + j); ++g) {
				if (Check_Pol(s, i, j)) {
					cout << s;
					return 0;
				}
			}
		}
	}
	return 0;
}*/
// 1297
// з3 и з4 в5 
// 1545 