#include <iostream>
#include <string>
#include <queue>
#include <cstring>
const int MN = 20;
struct Point {
    int x;
    int y;
    Point() : x(-1), y(-1) {}
};
void selection_sort(Point* arr, const int& size)
{
    for (int i = 0; i < size; ++i)
    {
        int Min = i;
        for (int j = i; j < size; ++j)
            if (comp(arr[j], arr[Min])) Min = j;
        std::swap(arr[Min], arr[i]);
    }
}
void selection_sort(Point* arr, const int& size);
int n, ans, vx, vy;
bool black[MN][MN];
int dx[] = { 1, 0, -1, 0 };  // �������� �� ������� ����� ��������� � �������� ����� � c[]
// ���������� ��������
int dy[] = { 0, 1, 0, -1 };
char c[] = { 'R', 'T', 'L', 'B' }, b[MN];
Point a[MN * MN];
std::queue<Point> q;

bool comp(const Point& pa, const Point& pb) {
    if (pa.x != pb.x) return pa.x < pb.x;
    return pa.y < pb.y;
}

void bfs_a() {
    Point now, next;
    std::string dir;
    while (!q.empty()) {
        now = q.front();
        a[ans] = now;
        std::cin >> dir;
        for (int i = 0; i < dir.length() - 1; i++) {   // ���� �� ������ �� R T L B
            char tc = dir[i];
            int j;
            for (j = 0; j < 4; j++) {
                if (c[j] == tc) break;
            }
            next.x = now.x + dx[j];                    // ������ ���������� � ����������� �� �������� 
            next.y = now.y + dy[j];
            q.push(next);                              // ����� ����� ���������� �������
        }
        q.pop();
        ans++;
    }
}

void bfs_b() {
    Point now, next;
    while (!q.empty()) {
        now = q.front();
        for (int i = 0; i < 4; i++) {                 // ��������� ���� ��������� �������
            int tx = now.x + dx[i];
            int ty = now.y + dy[i];
            if (black[tx][ty] == 1) {                // ���� ������ ����� �������� �� �������� ������ �� R T B L
                std::cout << c[i];
                black[tx][ty] = 0;
                next.x = tx;
                next.y = ty;
                q.push(next);                       // ����� ����� ��������� ��� �������
            }
        }
        ans++;
        if (ans != n)
            std::cout << ",\n";                    // ���� ��� �� ���� ��������� �� ������ �������, ����� �����
        else
            std::cout << ".\n";
        q.pop();
    }
}

int main() {
    std::string s;
    getline(std::cin, s);
    memset(black, 0, sizeof(black));
    Point k;
    if (s.find(' ') != std::string::npos) {
        s.copy(b, s.find(' '), 0);  // �������� ������ �����  � b 
        vx = atoi(b);               // ������ � int � ����������
        s.copy(b, 100, s.find(' ') + 1); // ��� �� �� ������ ������
        vy = atoi(b);                    // ����� ����� ���� ������� ������� �������� �� �� ������� � ����� �����


        Point k;
        k.x = vx;
        k.y = vy;
        q.push(k);
        bfs_a();
        selection_sort(a, ans);          // ��������� ���� �� �����, ���� ���� ����� �� �� �������
        std::cout << ans << std::endl;
        for (int i = 0; i < ans; i++)
            std::cout << a[i].x << ' ' << a[i].y << std::endl;
    }
    else {
        n = atoi(s.c_str());
        for (int i = 0; i < n; i++) {
            std::cin >> k.x >> k.y;
            black[k.x][k.y] = 1;       // �������� ��� ������ ������ ��� ����������  � ����� � �������
            // ����� ��������� ������� ��� ������ ������
            if (i == 0) {
                q.push(k);
                std::cout << k.x << ' ' << k.y << std::endl;
                black[k.x][k.y] = 0;
            }
        }
        ans = 0;
        bfs_b();
    }
    return 0;
}