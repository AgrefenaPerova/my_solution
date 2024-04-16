//1910
/*
#include <iostream>
int main() {
	int n;
	std::cin >> n;
	int a, b, c, cn;
	int mxsum = 0;
	std::cin >> a >> b;
	for (int i = 2; i < n; i++) {
		cin >> c;
		if (a + b + c > mxsum) {
			mxsum = a + b + c;
			cn = i;
		}
		a = b;
		b = c;
	}
	std::cout << mxsum << ' ' << cn;
	return 0;
}
*/
//1203 быстрая сортировка
/*
#include <iostream>
#include <algorithm>
struct Talk {
	int start;
	int end;
};
bool compareByEndTime(const Talk& talk1, const Talk& talk2) {
	return talk1.end < talk2.end;
}
int maxTalks(int n, Talk talks[]) {
	std::sort(talks, talks + n, compareByEndTime);
	int count = 1;
	int lastEndTime = talks[0].end;
	for (int i = 1; i < n; ++i) {
		if (talks[i].start >= lastEndTime + 1) {
			count++;
			lastEndTime = talks[i].end;
		}
	}
	return count;
}

int main() {
	int n;
	std::cin >> n;
	Talk talks[100001];
	for (int i = 0; i < n; ++i) {
		std::cin >> talks[i].start >> talks[i].end;
	}
	int maxTalksCount = maxTalks(n, talks);
	std::cout << maxTalksCount << std::endl;
	return 0;
}
*/
//6 задача из файла в 5
// 1 решение
/*
#include<iostream>
#include<cmath>
struct MyPolygons {
	double x;
	double y;
};
bool Is_Right(MyPolygons* a, int& k) {
	int d1x = a[0].x - a[1].x;
	int d1y = a[0].y - a[1].y;
	for (int i = 0; i < k - 1; ++i) {
		int dx = a[i + 1].x - a[i].x;
		int dy = a[i + 1].y - a[i].y;
		if (dx != d1x && dy != d1y) return false;
	}
	return true;
}
int Perimeter(MyPolygons* a, int& k) {
	int p = 0;
	int d1x = a[0].x - a[1].x;
	int d1y = a[0].y - a[1].y;
	return k * sqrt(d1x * d1x + d1y * d1y);
}
void Sort_Perimeter(int* a, int l) {
	int i = 0, j = l - 1, mid = a[l / 2];
	do {
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) Sort_Perimeter(a, j + 1);
	if (i < l) Sort_Perimeter(&a[i], l - i);
}
void Print_Polygons(int* a, int l) {
	for (int i = 0; i < l; ++i) {
		std::cin >> a[i];
	}
}
int main() {
	int l;
	int k;
	MyPolygons* polygons = new MyPolygons[k];
	std::cin >> l;
	std::cin >> k;
	int* perimeter = new int[l];
	for (int i = 0; i < l; ++i) {
		for (int j = 0; j < k; ++j) {
			std::cin >> polygons[j].x;
			std::cin >> polygons[j].y;
			
		}
		if (Is_Right(polygons, k)) {
			perimeter[i] = Perimeter(polygons, k);
		}
	}
	Sort_Perimeter(perimeter, l);
	Print_Polygons(perimeter, l);
	return 0;
}
*/
//2 решение файлы
/*
#include <iostream>
#include <cmath>
struct Polygon {
	int vertices;
	double perimeter;
	double* coordinates;
};
bool isRegularPolygon(Polygon polygon) {
	double x1 = polygon.coordinates[0];
	double y1 = polygon.coordinates[1];
	double x2 = polygon.coordinates[2];
	double y2 = polygon.coordinates[3];
	double sideLength = std::sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	double angle = 360 / polygon.vertices;
	double expectedSideLength = 2 * sideLength * std::sin(angle * 3.14 / 180 / 2);
	return std::abs(sideLength - expectedSideLength) < 1e-9;
}
void sortPolygons(Polygon* polygons, int count) {
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (polygons[i].perimeter > polygons[j].perimeter) {
				Polygon temp = polygons[i];
				polygons[i] = polygons[j];
				polygons[j] = temp;
			}
		}
	}
}
int main() {
	int l, k;
	std::cout << "Enter the number of polygons: ";
	std::cin >> l;
	std::cout << "Enter the number of vertices in the polygons: ";
	std::cin >> k;

	Polygon* polygons = new Polygon[l];

	for (int i = 0; i < l; i++) {
		polygons[i].vertices = k;
		polygons[i].coordinates = new double[2 * k];
		std::cout << "Enter the coordinates of the vertices of the polygon " << i + 1 << ":\n";
		for (int j = 0; j < 2 * k; j++) {
			std::cin >> polygons[i].coordinates[j];
		}

		if (isRegularPolygon(polygons[i])) {
			double perimeter = 0;
			for (int j = 0; j < k - 1; j++) {
				double x1 = polygons[i].coordinates[2 * j];
				double y1 = polygons[i].coordinates[2 * j + 1];
				double x2 = polygons[i].coordinates[2 * (j + 1)];
				double y2 = polygons[i].coordinates[2 * (j + 1) + 1];
				perimeter += std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
			}
			polygons[i].perimeter = perimeter;
		}
		else {
			polygons[i].perimeter = -1;
		}
	}
	sortPolygons(polygons, l);

	bool foundRegularPolygon = false;
	for (int i = 0; i < l; i++) {
		if (polygons[i].perimeter != -1) {
			foundRegularPolygon = true;
			std::cout << "A polygon with coordinates ";
			for (int j = 0; j < 2 * k; j++) {
				std::cout << polygons[i].coordinates[j] << " ";
			}
			std::cout << "has a perimeter " << polygons[i].perimeter << std::endl;
		}
	}

	if (!foundRegularPolygon) {
		std::cout << "IMPOSSIBLE" << std::endl;
	}

	// Освобождаем память
	for (int i = 0; i < l; i++) {
		delete[] polygons[i].coordinates;
	}
	delete[] polygons;

	return 0;
}
*/