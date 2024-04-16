/*
#include <iostream>
#include <algorithm>

using namespace std;
struct Point {
    int x, y, num;
};

int cr_p(Point A, Point B) {
    return A.x * B.y - B.x * A.y;
}

int dist(Point A) {
    return A.x * A.x + A.y * A.y;
}

bool operator < (Point A, Point B) {
    return cr_p(A, B) > 0 || (cr_p(A, B) == 0 && dist(A) < dist(B));
}

int main() {
    int n;
    cin >> n;
    
    Point St;
    cin >> St.x >> St.y;
    for (int i = 2; i <= n; ++i) {
        Point A;
        cin >> A.x >> A.y;
        A.num = i;
        A.x -= St.x;
        A.y -= St.y;
        if (A.y > 0 || (A.y == 0 && A.x > 0)) {
            S1.push_back(A);
        }
        else {
            S2.push_back(A);
        }
    }
    sort(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());
    cout << n << endl << 1 << endl;
    //cout << cr_p(S2[0], S1[S1.size() - 1]) << endl; 
    if (S1.size() == 0 || S2.size() == 0 || cr_p(S1[S1.size() - 1], S2[0]) > 0) {
        for (int i = 0; i < (int)S1.size(); ++i) {
            cout << S1[i].num << endl;
        }
        for (int i = 0; i < (int)S2.size(); ++i) {
            cout << S2[i].num << endl;
        }

    }
    else {
        for (int i = 0; i < (int)S2.size(); ++i) {
            cout << S2[i].num << endl;
        }
        for (int i = 0; i < (int)S1.size(); ++i) {
            cout << S1[i].num << endl;
        }
    }
}
*/
/*
Point* Can_Traverse_Points(const Point* points, int n) {
	Point* ans = new Point[n];
	if (n <= 2) {
		for (int i = 0; i < n; ++i) {
			ans[i].num = points[i].num;
		}
		return ans;
	}
	Sort_Points();
	delete[] ans;
}
int main() {
	int n;
	std::cin >> n;
	Point* points = new Point[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> points[i].x >> points[i].y;
		points[i].num = n;
	}
	Point* ans = new Point[n];
	ans = Can_Traverse_Points(points, n);
	return 0;
}
*/
/*
#include <iostream>
#include <algorithm>

struct Point {
    int x, y, num;
};

int cr_p(Point A, Point B) {
    return A.x * B.y - B.x * A.y;
}

int dist(Point A) {
    return A.x * A.x + A.y * A.y;
}

bool operator<(Point A, Point B) {
    return cr_p(A, B) > 0 || (cr_p(A, B) == 0 && dist(A) < dist(B));
}

int main() {
    int n;
    std::cin >> n;
    Point* S1 = new Point[n - 1];
    Point* S2 = new Point[n - 1];
    Point St;
    std::cin >> St.x >> St.y;
    for (int i = 0; i < n; ++i) {
        Point A;
        std::cin >> A.x >> A.y;
        A.num = i;
        A.x -= St.x;
        A.y -= St.y;
        if (A.y > 0 || (A.y == 0 && A.x > 0)) {
            S1[i - 2] = A;
        }
        else {
            S2[i - 2] = A;
        }
    }

    std::sort(S1, S1 + n - 1);
    std::sort(S2, S2 + n - 1);

    std::cout << n << std::endl << 1 << std::endl;

    if (S1[n - 2].x == 0 || S1[n - 2].y == 0 || S2[n - 2].x == 0 || S2[n - 2].y == 0 || cr_p(S1[n - 2], S2[0]) > 0) {
        for (int i = 0; i < n; ++i) {
            std::cout << S1[i].num << std::endl;
        }
        for (int i = 0; i < n; ++i) {
            std::cout << S2[i].num << std::endl;
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            std::cout << S2[i].num << std::endl;
        }
        for (int i = 0; i < n; ++i) {
            std::cout << S1[i].num << std::endl;
        }
    }

    delete[] S1;
    delete[] S2;

    return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Point {
    int x, y, num;
};

int cr_p(Point A, Point B) {
    return A.x * B.y - B.x * A.y;
}

int dist(Point A) {
    return A.x * A.x + A.y * A.y;
}

bool operator < (Point A, Point B) {
    return cr_p(A, B) > 0 || (cr_p(A, B) == 0 && dist(A) < dist(B));
}

int main() {
    int n;
    std::cin >> n;
    vector <Point> S1, S2;
    Point St;
    std::cin >> St.x >> St.y;
    for (int i = 2; i <= n; ++i) {
        Point A;
        cin >> A.x >> A.y;
        A.num = i;
        A.x -= St.x;
        A.y -= St.y;
        if (A.y > 0 || (A.y == 0 && A.x > 0)) {
            S1.push_back(A);
        }
        else {
            S2.push_back(A);
        }
    }
    sort(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());
    cout << n << endl << 1 << endl;
    //cout << cr_p(S2[0], S1[S1.size() - 1]) << endl; 
    if (S1.size() == 0 || S2.size() == 0 || cr_p(S1[S1.size() - 1], S2[0]) > 0) {
        for (int i = 0; i < (int)S1.size(); ++i) {
            cout << S1[i].num << endl;
        }
        for (int i = 0; i < (int)S2.size(); ++i) {
            cout << S2[i].num << endl;
        }

    }
    else {
        for (int i = 0; i < (int)S2.size(); ++i) {
            cout << S2[i].num << endl;
        }
        for (int i = 0; i < (int)S1.size(); ++i) {
            cout << S1[i].num << endl;
        }
    }
}