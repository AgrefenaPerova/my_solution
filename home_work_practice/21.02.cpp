/*
дз
1) очередь на двух стеках
--пушить только в первый стек, поп во второй стек(если не пустой) иначе из первого поп пуш во второй
2) написать очередь на закольцованном массиве(если элементы закончились в начало добавлять и энд в начало)
3) 1136 стек и бинарнрое дерево.рекурсивное создание дерева!(обход бинарного дерева)

*/
//1
#include<iostream>
/*
class Two_Stacks {
public:
    struct Node {
        int data;
        Node* next;
    };

    Node* s1_top;
    Node* s2_top;

    Two_Stacks() : s1_top(nullptr), s2_top(nullptr) {}

    void Push(int elem) {
        Node* new_node = new Node{ elem, nullptr };
        if (s1_top == nullptr) {
            s1_top = new_node;
        }
        else {
            Node* temp = s1_top;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    int Pop() {
        if (s2_top == nullptr) {
            while (s1_top != nullptr) {
                Node* temp = s1_top;
                s1_top = s1_top->next;
                temp->next = s2_top;
                s2_top = temp;
            }
        }
        Node* temp = s2_top;
        s2_top = s2_top->next;
        int val = temp->data;
        delete temp;
        return val;
    }
};
int main() {
    Two_Stacks q;
    q.Push(2);
    q.Push(3);
    std::cout << q.Pop() << std::endl;
    return 0;
}

*/
//2
//if REAR + 1 == 5 (overflow!), REAR = (REAR + 1)%5 = 0 (start of queue)
/* Размер круговой очереди */
/*
#define SIZE 5   

class Сircular_Queue {
private:
    int items[SIZE], front, rear;

public:
    Сircular_Queue() {
        front = -1;
        rear = -1;
    }

    bool is_Full() {
        if (front == 0 && rear == SIZE - 1) {
            return true;
        }
        if (front == rear + 1) {
            return true;
        }
        return false;
    }

    bool is_Empty() {
        if (front == -1) return true;
        else return false;
    }

    void en_Сircular_Queue(int element) {
        if (is_Full()) {
            std::cout << "Queue is full";
        }
        else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            std::cout << std::endl << "Inserted " << element << std::endl;
        }
    }

    int de_Сircular_Queue() {
        int element;
        if (is_Empty()) {
            std::cout << "Queue is empty" << std::endl;
            return(-1);
        }
        else {
            element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } // Q имеет только один элемент, поэтому мы удаляем очередь после удаления. 
            else {
                front = (front + 1) % SIZE;
            }
            return(element);
        }
    }

    void Display()
    {
        //Функция для отображения статуса круговой очереди 
        int i;
        if (is_Empty()) {
            std::cout << std::endl << "Empty Queue" << std::endl;
        }
        else
        {
            std::cout << "Front -> " << front;
            std::cout << std::endl << "Items -> ";
            for (i = front; i != rear; i = (i + 1) % SIZE)
                std::cout << items[i];
            std::cout << items[i];
            std::cout << std::endl << "Rear -> " << rear;
        }
    }

};


int main()
{
    Сircular_Queue q;

    // Ложь, потому что front = -1
    q.de_Сircular_Queue();

    q.en_Сircular_Queue(1);
    q.en_Сircular_Queue(2);
    q.en_Сircular_Queue(3);
    q.en_Сircular_Queue(4);
    q.en_Сircular_Queue(5);

    // Невозможно поставить в очередь, потому что front == 0 && rear == SIZE - 1
    q.en_Сircular_Queue(6);


    q.Display();

    int elem = q.de_Сircular_Queue();

    if (elem != -1)
        std::cout << std::endl << "Deleted Element is " << elem;

    q.Display();

    q.en_Сircular_Queue(7);

    q.Display();

    // Невозможно поставить в очередь, потому что front == rear + 1
    q.en_Сircular_Queue(8);

    return 0;
}
*/
//1136
/*
#include <cstring>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* Building_A_Tree(int* data, int start, int end) {
    if (end < start) {
        return nullptr;
    }

    Node* root = new Node(data[end]);

    if (end == start) {
        return root;
    }

    bool Has_Left = (data[start] < root->value);
    bool Has_Right = (data[end - 1] > root->value);

    if (!Has_Left) {
        root->right = Building_A_Tree(data, start, end - 1);
        return root;
    }
    if (!Has_Right) {
        root->left = Building_A_Tree(data, start, end - 1);
        return root;
    }

    int low = start;
    int high = end - 1;
    while (true) {
        int mid = (low + high) / 2;
        if (data[mid] < root->value) {
            low = mid + 1;
        }
        else if (data[mid - 1] > root->value) {
            high = mid - 1;
        }
        else {
            break;
        }
    }
    int mid = (low + high) / 2;
    root->left = Building_A_Tree(data, start, mid - 1);
    root->right = Building_A_Tree(data, mid, end - 1);
    return root;
}

void Output_Of_Tree_Traversal_In_Reverse_Prefix_Order(Node* root) {
    if (root->right) {
        Output_Of_Tree_Traversal_In_Reverse_Prefix_Order(root->right);
    }
    if (root->left) {
        Output_Of_Tree_Traversal_In_Reverse_Prefix_Order(root->left);
    }
    std::cout << root->value << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    int* data = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    Node* root = Building_A_Tree(data, 0, n - 1);
    Output_Of_Tree_Traversal_In_Reverse_Prefix_Order(root);

    delete[] data;

    return 0;
}
*/
