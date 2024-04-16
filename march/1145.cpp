#include <iostream>
#include <queue>

struct Point
{
	Point(const int& X, const int& Y) : x(X), y(Y) {}
	Point() : x(-1), y(-1) {}
	int x;
	int y;
};

class Graph
{
public:
	Graph(const int& Rows, const int& Cols, bool** maze) : rows(Rows), cols(Cols)
	{
		used = new bool* [rows];
		dis = new int* [rows];
		points = new Point[rows * cols];
		for (int i = 0; i < rows; ++i)
		{
			dis[i] = new int[cols] {0};
			used[i] = new bool[cols] {0};
			int size_byts = sizeof(bool) * cols;
			memcpy_s(used[i], size_byts, maze[i], size_byts);
		}

		size_points = 0;

		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
			{
				if (maze[i][j] == 0)
					points[size_points++] = Point(i, j);
				else
					used[i][j] = 1;
			}

	}


	Point Get_First_Point() { return points[0]; }


	int bfs(const Point& in, Point& out)
	{
		if (in.x == -1) return 0;
		std::queue<Point> q;
		int Max = 0;
		q.push(in);
		used[in.x][in.y] = 1;


		while (!q.empty())
		{
			Point p = q.front();
			out = p;

			for (auto temp : { Point(-1, 0), Point(1, 0), Point(0, -1), Point(0, 1) })
			{
				int x = p.x + temp.x, y = p.y + temp.y;
				if (x < rows && y < cols && x >= 0 && y >= 0)
				{
					if (used[x][y] == 0 && dis[x][y] == 0)
					{
						dis[x][y] = dis[p.x][p.y] + 1;
						used[x][y] = 1;
						if (dis[x][y] > Max) Max = dis[x][y];
						q.push(Point(x, y));
					}
				}
			}
			q.pop();
		}
		return Max;
	}

	~Graph()
	{
		for (int i = 0; i < rows; ++i)
			delete[] dis[i];
		delete[] dis;
		delete[] points;
		for (int i = 0; i < rows; ++i)
			delete[] used[i];
		delete[] used;
	}
private:
	Point* points;
	bool** used;
	int** dis;
	int rows;
	int cols;
	int size_points;
};

int main()
{
	int n = 1, m = 1;
	std::cin >> n >> m;
	bool** maze = new bool* [m];
	for (int i = 0; i < m; ++i)
		maze[i] = new bool[n] {0};

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			char pars = ' ';
			std::cin >> pars;
			switch (pars)
			{
			case '#':
				maze[i][j] = 1;
				break;
			case '.':
				maze[i][j] = 0;
				break;
			default:
				break;
			}
		}



	Graph graph(m, n, maze);
	Graph graph1(m, n, maze);
	Point first = graph.Get_First_Point(), second;
	int ans = 0;
	graph.bfs(first, second);
	std::cout << graph1.bfs(second, first) << std::endl;
	return 0;
}