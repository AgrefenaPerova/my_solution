#pragma once
#include"Node.h"
class Stack {
public:
	Node* head;
	Stack() {
		head = nullptr;
	}
	Stack(Node* first) {
		head = first;
	}
	Stack(int k) {
		head = new Node(k);
	}
	void Push(int k);
	int Pop();
	bool Empty() { return (head != nullptr) ? true : false; }
	int Min() { return head->min; }
	int Top() { return head->n; }
	void View() {
		Node* cur = head;
		while (cur) {
			std::cout << cur->n << ' ';
			cur = cur->next;
		}
	}
};
void Stack::Push(int k) {
	Node* f = new Node(k);
	if (head) f->min = (k < head->min) ? k : head->min;
	else f->min = k;
	f->next = head;
	head = f;
}
int Stack::Pop() {
	int out = head->n;
	Node* temp = head;
	head = head->next;
	delete temp;
	return out;
}