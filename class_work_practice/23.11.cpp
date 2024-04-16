//1711
/*
#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string** str = new string*[n];
	string a, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		if (b > c) swap(b, c);
		if (a > b)swap(a, b);
		str[i] = new string[3];
		str[i][0] = a;
		str[i][1] = b;
		str[i][2] = c;
	}
	string* ans = new string[n];
	int* num = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}
	a = "a";
	for (int i = 0; i < n; i++) {
		int k = num[i]-1;
		if (a < str[k][0]) {
			ans[i] = str[k][0];
			a = ans[i];
			continue;
		}
		else if (a < str[k][1]) {
			ans[i] = str[k][1];
			a = ans[i];
			continue;
		}
		else if (a < str[k][2]) {
			ans[i] = str[k][2];
			a = ans[i];
			continue;
		}
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
*/
//1601
//прибавлять 1
/*
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s, ans;
	while (getline(cin, s)) {
		int l = s.length();
		for (int i = 1; i < l; ++i) {
			if (isalpha(s[i]) && isalpha(s[i-1])) ans += tolower(s[i]);
			else ans += s[i];
		}
	}
	cout << ans;
}
*/
//дз
// 1601
// 1881
// 1868
//  конь