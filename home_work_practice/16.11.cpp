//16.11

//1297

include<iostream>
using namespace space std;
bool isPalindrome(string s) {
    int l = s.length();
    for (int i = 0; i <= l / 2; ++i)
        if (s[i] != s[l - i - 1])            
            return false;
    return true;
}
int main() {

    string s, tmp = "";
    cin >> s;
    int l = s.length();
    for (int i = l; i > 0; --i) {
        for (int j = 0; j <= l - i; ++j) {
            for (int k = 0; k < i; ++k) {
                tmp += s[k + j];
            }
            if (isPalindrome(tmp)) {
                cout << tmp << endl;
                return 0;
            }
            else {
                tmp = "";
            }
        }
    }
    return 0;
}
// з3 в5

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
}
// з4 в5
#include<iostream>
#include<string>
using namespace std;
int main() {
    string s, ans;
    getline(cin, s);
    int l = s.length();
    string* str = new string[l];
    for (int i = 0; i <= l - 1; ++i) {
        if (isalpha(s[i])) {
            ans += s[i];
        }
        else {
            if (s[i] != ' ') {//знак препинания
                if (s[i - 1] != ' ') {//прошлая была буква
                    ans += s[i];//записали знак
                }
            }
            else if (s[i] == ' ') {//пробел
                if (isalpha(s[i + 1])) {//следующая буква
                    ans += s[i];//записали пробел
                }//если следующий знак
                else if (s[i + 1] == '.' || s[i + 1] == ':' || s[i + 1] == ',' || s[i + 1] == '!' || s[i + 1] == '?' || s[i + 1] == '-' || s[i + 1] == ';') {
                    ans += s[i + 1];//записали знак
                }
            }
        }
        if (i == l - 1) ans += ' ';
    }
    int a = 0, k = 0, i = 0;
    l = ans.length();
    for (i = l; i >= 0; --i) {
        if (ans[i] == ' ') {
            for (k = i + 1; k <= (i + a); ++k) {
                cout << ans[k];
            }
            a = 0;
        }

        a++;
    }

    for (int i = 0; i < l; i++) {
        if (ans[i] == ' ') break;
        cout << ans[i];
    }
    return 0;
}
// 1545 
#include<iostream>
#include<string>
using namespace std;
int main() {
    int n;
    cin >> n;
    string letter, words;
    string* ans = new string[n];
    for (int i = 0; i < n; ++i) {
        cin >> ans[i];
    }
    cin >> letter;
    for (int i = 0; i < n; ++i) {
        if (ans[i][0] == letter[0]) {
            cout << ans[i].c_str()<<endl;
        }
    }
    return 0;
}