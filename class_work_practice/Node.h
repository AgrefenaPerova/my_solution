#pragma once
struct Node {
	int n;
	int min;
	Node* next;
	Node(int k) {
		n = k;
		min = k;
		next = nullptr;
	}
	//(int k):n(k), min(k)
};