//#include<iostream>
//класс дробь , перегрузка +-*/ iostream ostream(cin)
/*
class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {}

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Fraction& f) {
        char slash;
        in >> f.numerator >> slash >> f.denominator;
        if (slash != '/' || f.denominator == 0) {
            in.setstate(std::ios::failbit);
            f.Stop();
        }
        return in;
    }
    void Stop() {
        std::cout << "Incorrect data entry." << std::endl;
        return;
    }
    Fraction operator+(const Fraction& other) {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator-(const Fraction& other) {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator*(const Fraction& other) {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction operator/(const Fraction& other) {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }
};

int main() {

    Fraction a;
    Fraction b;

    std::cin >> a;
    std::cin >> b;
    Fraction c = a + b;
    std::cout << "a + b = " << c << std::endl;

    c = a - b;
    std::cout << "a - b = " << c << std::endl;

    c = a * b;
    std::cout << "a * b = " << c << std::endl;

    c = a / b;
    std::cout << "a / b = " << c << std::endl;

    return 0;
}
*/
//задан граф есть список списков, чтение из файла, строим матрицу(памяти на единицу больше чтоб 0 столбец и 0 строка) 
// смежности, матрица инцендентности(кол-во считаем делим пополам. )
 /*
    int** incidenceMatrix = new int* [numVertices];
    for (int i = 0; i < numEdges; ++i) {
        incidenceMatrix[i] = new int[numEdges];
    }

    int** adjacencyMatrix = new int* [numVertices];
    for (int i = 0; i < numEdges; ++i) {
        adjacencyMatrix[i] = new int[numEdges];
    }
 */
    
/*
#include <fstream>

const int MAX_VERTICES = 100;

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = { 0 };
int incidenceMatrix[MAX_VERTICES][MAX_VERTICES] = { 0 };

int main() {
    std::ifstream inputFile("graph.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int numVertices, numEdges;
    inputFile >> numVertices >> numEdges;
   
    for (int i = 0; i < numEdges; ++i) {
        int vertex1, vertex2;
        inputFile >> vertex1 >> vertex2;

        // Fill adjacency matrix
        adjacencyMatrix[vertex1][vertex2] = 1;
        adjacencyMatrix[vertex2][vertex1] = 1;


        // Fill incidence matrix
        incidenceMatrix[vertex1][i] = 1;
        incidenceMatrix[vertex2][i] = 1;
    }

    // Print adjacency matrix
    std::cout << "Adjacency Matrix:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Print incidence matrix
    std::cout << "Incidence Matrix:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numEdges; ++j) {
            std::cout << incidenceMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    inputFile.close();
    return 0;
}

*/