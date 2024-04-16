#include<iostream>
struct Point {
	int x;
	int y;
	int z;
};
struct Vector {
    int x;
    int y;
    int z;
};
int main() {
	Point A;
	std::cin >> A.x >> A.y >> A.z;
	Point B;
	std::cin >> B.x >> B.y >> B.z;
	Point C;
	std::cin >> C.x >> C.y >> C.z;
	Point D;
	std::cin >> D.x >> D.y >> D.z;
    /*
    if ((A.x == B.x && A.y == B.y && A.z == B.z) || (C.x == D.x && C.y == D.y && C.z == D.z)) {
        std::cout << "Invalid" << std::endl;
    }
    else {
        int dx1 = B.x - A.x;
        int dy1 = B.y - A.y;
        int dz1 = B.z - A.z;

        int dx2 = D.x - C.x;
        int dy2 = D.y - C.y;
        int dz2 = D.z - C.z;

        if ((dx1 * dx2 + dy1 * dy2 + dz1 * dz2) == 0) {
            std::cout << "Valid" << std::endl;
        }
        else {
            std::cout << "Invalid" << std::endl;
        }
    }
    */
    if (A.x == B.x && A.y == B.y) {
        std::cout << "Invalid";
    }
    else if (C.x == D.x && C.y == D.y) {
        std::cout << "Invalid";
    }

    Vector dAB;
    dAB.x = B.x - A.x;
    dAB.y = B.y - A.y;
    dAB.z = B.z - A.z;
    Vector dCD;
    dCD.x = D.x - C.x;
    dCD.y = D.y - C.y;
    dCD.z = D.z - C.z;

	return 0;
}