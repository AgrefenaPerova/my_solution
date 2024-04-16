//1521
/*
#include<iostream>
struct Node {
	int num;
	Node* next;
	Node(int n) {
		num = n;
		next = nullptr;
	}
};
int main() {
	int n, k;
	std::cin >> n;
	std::cin >> k;
	Node* rood = new Node(1);
	Node* curr = rood;
	for (int i = 2; i < n; ++i) {
		Node* var = new Node(i);
		curr->next = var;
		curr = var;
	}
	curr->next = rood;
	for (int i = 1; i < n;++i){
		for (int i = 0; i < n; i += k){
			std::cout << rood->num << ' ';
			rood = rood->k;
		}
	}
	return 0;
}
*/