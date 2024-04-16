#include <iostream>

int n;
int adjacency_matrix[100][100] = { 0 };
int vertex_colors[100];
int temp;

bool dfs(int v, int col);

int main() 
{
    std::cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        while (true) 
        {
            std::cin >> temp;
            if (temp == 0) break;
            adjacency_matrix[i][temp - 1] = adjacency_matrix[temp - 1][i] = 1;
        }
    }
    for (int i = 0; i < 100; ++i)
        vertex_colors[i] = -1;
    if (dfs(0, 0) == true) 
    {
        for (int i = 0; i < n; ++i) 
            std::cout << vertex_colors[i];
    }
    else 
    {
        std::cout << "-1";
    }
    return 0;
}

bool dfs(int v, int col) 
{
    if (vertex_colors[v] != -1 && vertex_colors[v] == col) 
        return true;
    else if (vertex_colors[v] != -1 && vertex_colors[v] != col) 
        return false;
    vertex_colors[v] = col;
    for (int i = 0; i < n; ++i) 
    {
        if (adjacency_matrix[v][i] && !dfs(i, 1 - col)) 
            return false;
    }
    return true;
}