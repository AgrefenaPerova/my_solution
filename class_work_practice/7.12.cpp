/*
//1196
#include<iostream>
#include<algorithm>
int main() {
	int n;
	std::cin >> n;
	int* teacher = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin>>teacher[i];
	}
	int m;
	std::cin >> m;
	int* student = new int[m];
	for (int i = 0; i < m; ++i) {
		std::cin >> student[i];
	}
	std::sort(student, student+m);
	int i = 0, j = 0, k=0;
	while (i < n && j < m) {
		if (teacher[i] < student[j])i++;
		else if (teacher[i] == student[j]) {
			k++;
			j++;
		}
		else j++;
	}
	std::cout << k;
	return 0;
}
*/
//1656
/*
#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
void Sort(int*, int*, int);
int main() {
	int n;
	std::cin >> n;
	int n_in_2 = n * n;
	int* army = new int[n_in_2];
	for (int i = 0; i < n_in_2; ++i) {
		std::cin >> army[i];
	}
	int* index = new int[n + 1];
	for (int i = 1; i <= n; ++i) index[i] = i;
	Sort(army, index, n);
	for (int i = 0; i < n; ++i) {
		std::cout << army[index[i]]<<' ';
	}
	return 0;
}
void Sort(int* a, int* index, int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n - i - 1; ++j) {
			if (a[index[j]] > a[index[j + 1]]) std::swap(index[j], index[j+1]);
		}
	}
}
*/
//дз
// последн€€ задача в 5
// 1102
// 1656
// 1404
// 2033
// конь
// 1603 