#include <iostream>
#include <stack>

int* ancestors, * tree_height;
int n, m, k;
bool* threads_removed;

std::stack<int> stack_ans;
std::stack<int> input_nodes;
int Find(int v)
{
	return (ancestors[v] == v) ? v : ancestors[v] = Find(ancestors[v]);
}

void Unit(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b) return;
	--k;

	if (tree_height[a] < tree_height[b]) ancestors[a] = b;
	else
	{
		ancestors[b] = a;
		if (tree_height[a] == tree_height[b]) ++tree_height[a];
	}
}




int main()
{
	int N, M, Q;
	std::cin >> N >> M;
	k = N;
	++N;
	++M;
	ancestors = new int[N];
	tree_height = new int[N];
	threads_removed = new bool[M] {0};

	int** edges = new int* [M];
	for (int i = 0; i < M; ++i)
		edges[i] = new int[2];

	for (int i = 0; i < N; ++i)
	{
		ancestors[i] = i;
		tree_height[i] = 1;
	}
	for (int i = 1; i < M; ++i)
	{
		std::cin >> edges[i][0] >> edges[i][1];
	}
	std::cin >> Q;
	int* ans = new int[Q];
	int d = 0;
	for (int i = 0; i < Q; ++i)
	{
		int temp = 1;
		std::cin >> temp;
		input_nodes.push(edges[temp][1]);
		input_nodes.push(edges[temp][0]);
		threads_removed[temp] = 1;
	}


	for (int i = 1; i < M; ++i)
	{
		if (threads_removed[i] == 0)
			Unit(edges[i][0], edges[i][1]);
	}
	stack_ans.push(k);
	while (!input_nodes.empty())
	{
		int a = input_nodes.top();
		input_nodes.pop();
		int b = input_nodes.top();
		input_nodes.pop();
		Unit(a, b);
		stack_ans.push(k);
	}
	stack_ans.pop();
	while (!stack_ans.empty())
	{
		std::cout << stack_ans.top() << ' ';
		stack_ans.pop();
	}
	return 0;
}