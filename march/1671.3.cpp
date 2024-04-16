/*
#include <iostream>
#include <stack>
int* tree_height, *ancestors;
int n, m, k;
bool* del;
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
	int n_, m_, q_;
	std::cin >> n_ >> m_;
	int k = n_;
	++n_;
	++m_;
	ancestors = new int[n_];
	tree_height = new int[n_];
	del = new bool[m_] {0};

	int** nodes = new int* [m_];
	for (int i = 0; i < m_; ++i)
		nodes[i] = new int[2];

	for (int i = 0; i < n_; ++i)
	{
		ancestors[i] = i;
		tree_height[i] = 1;
	}
	for (int i = 1; i < m_; ++i)
	{
		std::cin >> nodes[i][0] >> nodes[i][1];
	}
	std::cin >> q_;
	int* ans = new int[q_];
	int d = 0;
	for (int i = 0; i < q_; ++i)
	{
		int temp = 1;
		std::cin >> temp;
		input_nodes.push(nodes[temp][1]);
		input_nodes.push(nodes[temp][0]);
		del[temp] = 1;
	}


	for (int i = 1; i < m_; ++i)
	{
		if (del[i] == 0)
			Unit(nodes[i][0], nodes[i][1]);
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
*/