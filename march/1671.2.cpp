/*
#include<iostream>
struct Node
{
	int x;
	int y;
};
class DSU
{
private:
	int* numbers;
	int* rank;
	int n;
public:
	DSU(int n)
	{
		this->n = n;
		rank = new int[n];
		numbers = new int[n];
		for (int i = 0; i < n; ++i)
		{
			rank[i] = 1;
			numbers[i] = i + 1;
		}
	}
	int Differences()
	{
		int counter = 1;
		for (int i = 0; i < n-1; ++i)
		{
			if (numbers[i] != numbers[i + 1]) counter++;
		}
		return counter;
	}
	
	int Find(int x)
	{
		int x1 = x - 1;
		if (numbers[x1] != x) numbers[x1] = Find(numbers[x1]);
		return numbers[x1];
	}
	
	void Unite(int a, int b)
	{
		int a1 = Find(a);
		int b1 = Find(b);
		
		if (rank[a1] < rank[b1]) numbers[a1-1] = b1;
		else
		{
			numbers[b1-1] = a1;
			if (rank[a1] == rank[b1])++rank[a1];
		}
		
	}
};
int Function(int x, DSU& num, Node* nodes)
{
	Node A = nodes[x];
	//std::cout << A.x << " " << A.y << std::endl;
	num.Unite(A.x, A.y);
	return num.Differences();
}
int main()
{
	int n, m;
	std::cin >> n >> m;
	DSU num = DSU(n);
	Node* nodes = new Node[m];
	for (int i = 0; i < m; ++i)
	{
		std::cin >> nodes[i].x >> nodes[i].y;
	}
	int q;
	std::cin >> q;
	int* ans = new int[q];
	int* numbers_nodes = new int[q];
	for (int i = 0; i < q; ++i)
	{
		std::cin >> numbers_nodes[i];
		numbers_nodes[i]--;
	}
	for (int i = 0; i < q; ++i)
	{
		ans[i] = Function(numbers_nodes[i], num, nodes);
	}
	for (int i = q-1; i >=0 ; i--)
	{
		std::cout << ans[i] << " ";
	}
	return 0;
}
*/