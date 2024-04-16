//дз
// 1601
/*
#include<iostream>
#include<string>
using namespace std;
int main() {
    int i = 0;
    string str;
    bool F = true;
    bool first = false;
    while (getline(cin, str)){
        int n = str.length();
        for (int i = 0; i < n; i++) {
            if (isalpha(str[i])) {
                if (!first) first = true;
                else str[i] = tolower(str[i]);
            }
            else if (str[i] == '.' || str[i] == '!' || str[i] == '?')
                first = false;
            cout << str[i];
        }
        cout << endl;
    }
    return 0;
}
*/
// 1881
/*
#include<iostream>
#include<string>
int main() {
    std::string str;
    int h, w, n;
    std::cin >> h >> w >> n;
    int Count_h, Count_w, Count_l;
    Count_h = 1;
    Count_w = 0;
    Count_l = 1;
    for (int i = 0; i < n; i++){
        std::cin >> str;
        int l = str.length();
        for (int j = 0; j < l; j++){
            if (Count_w + 1 <= w) Count_w++;
            else{
                Count_w = l;
                if (Count_h + 1 <= h){
                    Count_h++;
                }
                else {
                    Count_l++;
                    Count_h = 1;
                }
                break;
            }
        }
        Count_w++;
    }
    std::cout << Count_l;
    return 0;
}
*/
// 1868
/*
#include<iostream>
#include<string>
bool Is_Win(std::string& s, std::string* Un) {
    for (int i = 0; i < 4; ++i) {
        if (s == Un[i]) return true;  
    }
    return false;
}
bool Is_Second(std::string& s, std::string* Un) {
    for (int i = 4; i < 8; ++i) {
        if (s == Un[i]) return true;   
    }
    return false;
}
bool Is_Third(std::string& s, std::string* Un) {
    for (int i = 8; i < 12; ++i) {
        if (s == Un[i]) return true;
    }
    return false;
}
int main() {
    std::string Universities[12];
    for (int i = 0; i < 12; ++i) {
        getline(std::cin,Universities[i]);
    }
    int k, money=0;
    std::cin >> k;
    int* members = new int[k];
    for (int i = 0; i < k; ++i) {
        int count;
        std::cin >> count;
        members[i] = 0;
        for (int j = 0; j < count; ++j) {
            std::string s, _z, number;
            std::cin >> s;
            std::cin >> _z;
            std::cin >> number;
            if (number == "gold") {
                if (Is_Win(s, Universities)) members[i]+=1;
            }
            else if (number == "silver") {
                if (Is_Second(s, Universities))members[i]+=1;
            }
            else if (number == "bronze"){
                if (Is_Third(s, Universities))members[i]+=1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < k; ++i) {
        if (max < members[i]) {
            max = members[i];
            money = 1;
        }
        else if (max == members[i])money++;
    }
    std::cout << money*5;
    return 0;
}
*/
//  конь 1596
//1581
/*
#include<iostream>
int main() {
    int k;
    std::cin >> k;
    short* numbers = new short[k];
    for (int i = 0; i < k; ++i) {
        std::cin >> numbers[i];
    }
    int count = 1;
    for (int i = 0; i < k; ++i) {
        if (numbers[i] == numbers[i + 1]) count++;
        else {
            std::cout<<count<<' ';
            std::cout<<numbers[i]<<' ';
            count = 1;
        }
    }
    return 0;
}
*/
/*
* 
* 
* 
* 
//1298
#include<iostream>
//int* Ways(int& n, int* answer);
int find_path(int cur_x, int cur_y, int move_num,
    int** possible_moves_sh, int** desk_state)
{
    desk_state[cur_x][cur_y] = move_num; // Запомнить ход.
    if (move_num > max_moves) return 1; // Проверить завершение обхода.
    // Проверить каждый возможный ход из текущей клетки.
    for (int i = 0; i < 8; i++)
    {
        int next_x = cur_x + possible_moves_sh[i][0]; // Определить следующее поле.
        int next_y = cur_y + possible_moves_sh[i][1];

        if (move_possible(next_x, next_y)
            && find_path(next_x, next_y, move_num + 1)) return 1;
    }

    // Возврат.
    desk_state[cur_x][cur_y] = 0;
    back_ret++;
    return 0;
}
int main() {
    int n;
    std::cin >> n;
    int n2 = n * n;
    //int* answer = new int[n2] {0};
    int possible_moves_sh[8][2] = {
{-1, -2}, {-2, -1}, {-2,  1}, { 1, -2},
{-1,  2}, { 2, -1}, { 1,  2}, { 2,  1} };
    int** desk_state = new int*[n];
    for (int i = 0; i < n; ++i) {
        desk_state[i] = new int[n];
    }
   
    return 0;
}
*/
