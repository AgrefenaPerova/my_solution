//1111 (переделать с использованием классов, класс точка, рассто€ние между точками), 
//затем нужен класс отрезок(по двум точкам), затем класс пр€ма€(задаетс€ кф а, б, с), 
// класс квадрат(четыре поинта), аккуратно должны быть методы, конструкторы.
//#include <iostream>
/*
#include <cmath>

class Point {
public:
    double x;
    double y;

    Point(double x_val, double y_val) : x(x_val), y(y_val) {}

    double distanceTo(const Point& other) {
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

class Segment {
public:
    Point start;
    Point end;

    Segment(const Point& start_point, const Point& end_point) : start(start_point), end(end_point) {}

    double length() {
        return start.distanceTo(end);
    }
};

class Line {
public:
    double a;
    double b;
    double c;

    Line(double a_val, double b_val, double c_val) : a(a_val), b(b_val), c(c_val) {}

    double distanceFromPoint(const Point& point) {
        return std::abs(a * point.x + b * point.y + c) / sqrt(a * a + b * b);
    }
};

class Square {
public:
    Point p1, p2, p3, p4;

    Square(const Point& point1, const Point& point2, const Point& point3, const Point& point4)
        : p1(point1), p2(point2), p3(point3), p4(point4) {}

    double sideLength() {
        return p1.distanceTo(p2);
    }
};

int main() {
    int n;
    std::cin >> n;

    return 0;
}
*/

//написать класс матрица (n x m), должна быть реализована на одномерном массиве, 
// должны быть методы: вз€ть элемент (вернуть элемент ij), положить элемент ij, 
// напечатать кв.матрицу, перегрузить операцию ввода, вывода, +. 
// ƒобавить оператор присваивани€ и конструктор копировани€.

/*
class Matrix {
public:
    int rows;
    int cols;
    int* data;


    Matrix(int n, int m) : rows(n), cols(m) {
        data = new int[n * m];
    }

    ~Matrix() {
        delete[] data;
    }

    int& operator()(int i, int j) {
        return data[i * cols + j];
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i * cols + j] << " ";
            }
            std::cout << std::endl;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                os << mat.data[i * mat.cols + j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& mat) {
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                is >> mat.data[i * mat.cols + j];
            }
        }
        return is;
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = data[i * cols + j] + other.data[i * cols + j];
            }
        }
        return result;
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            delete[] data;
            rows = other.rows;
            cols = other.cols;
            data = new int[rows * cols];
            std::copy(other.data, other.data + rows * cols, data);
        }
        return *this;
    }

    //  онструктор копировани€
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new int[rows * cols];
        std::copy(other.data, other.data + rows * cols, data);
    }
};

int main() {
    Matrix mat1(2, 2);
    std::cin >> mat1;

    Matrix mat2(2, 2);
    std::cin >> mat2;

    std::cout << "Matrix 1:" << std::endl;
    std::cout << mat1;

    std::cout << "Matrix 2:" << std::endl;
    std::cout << mat2;

    Matrix sum = mat1 + mat2;
    std::cout << "Sum of matrices:" << std::endl;
    std::cout << sum;

    return 0;
}
*/
//≈сть файлы с парами (первое слово английское, затем перевод (словарик в два столбца)),
//  мы создаем бинарное дерево (дерево поиска по английскому слову) (по алфавиту), 
// состоит из левого, правого потомка и из двух string, в результате должны заполнить бинарное дерево 
// и написать оператор поиска (ищет английское слово).

/*
#include <string>

struct Node {
    std::string englishWord;
    std::string translation;
    Node* left;
    Node* right;

    Node(std::string eng, std::string trans) : englishWord(eng), translation(trans), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* node, std::string eng, std::string trans) {
        if (node == nullptr) {
            return new Node(eng, trans);
        }

        if (eng < node->englishWord) {
            node->left = insert(node->left, eng, trans);
        }
        else if (eng > node->englishWord) {
            node->right = insert(node->right, eng, trans);
        }

        return node;
    }

    Node* search(Node* node, std::string eng) {
        if (node == nullptr || node->englishWord == eng) {
            return node;
        }

        if (eng < node->englishWord) {
            return search(node->left, eng);
        }
        else {
            return search(node->right, eng);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(std::string eng, std::string trans) {
        root = insert(root, eng, trans);
    }

    Node* search(std::string eng) {
        return search(root, eng);
    }
};

int main() {
    BinarySearchTree bst;
    std::string a, b, c, d, e, f;
    // ѕример заполнени€ бинарного дерева
    std::cin >> a >> b >> c >> d >> e >> f;
    bst.insert(a, b);
    bst.insert(c, d);
    bst.insert(e, f);
    // ѕример поиска слова
    std::cout << std::endl;
    std::cout << "what word do you want to find?" << std::endl;
    std::string ans;
    std::cin >> ans;
    Node* result = bst.search(ans);
    if (result != nullptr) {
        std::cout << "Word translation "<<ans <<": "<< result->translation << std::endl;
    }
    else {
        std::cout << "The word was not found." << std::endl;
    }

    return 0;
}
*/