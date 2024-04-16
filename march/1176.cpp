
#include <iostream>
#include <stack>
#include <queue>

class Graph
{
public:
	Graph()
	{
		std::cin >> size;
		std::cin >> begin;
		G = new bool* [size + 1];
		for (int i = 0; i < size + 1; ++i)
		{
			G[i] = new bool[size + 1] {0};
			for (int j = 1; j < size + 1; ++j)
				if (i) std::cin >> G[i][j];
		}
		W.push(begin);
	}
	void Way()
	{
		while (!W.empty())
		{
			int v = W.top();
			bool Flag = true;
			for (int i = 1; i < size + 1; ++i)
				if (!G[v][i] && v != i)
				{
					W.push(i);
					G[v][i] = 1;
					Flag = false;
					break;
				}
			if (Flag)
			{
				R.push(W.top());
				W.pop();
			}
		}
	}

	void PrintPath()
	{

		int u = R.top();
		while (!R.empty())
		{
			R.pop();
			if (!R.empty())
			{
				std::cout << u << ' ';
				u = R.top();
				std::cout << u << std::endl;
			}
		}
	}

private:
	bool** G;
	int size;
	int begin;
	std::stack<int> W;
	std::stack<int> R;
};


int main()
{
	Graph graph;
	graph.Way();
	graph.PrintPath();
	std::stack<int> st;
	return 0;
}