#include<iostream>
#include<fstream>
class Graph
{
private:
    int tops;
    int side;
    bool** matrix;
public:
    Graph(int t, int s)
    {
        tops = t;
        side = s;
        matrix = new bool* [side];
        for (int i = 0; i < side; ++i)
        {
            matrix[i] = new bool[tops];
        }
    }

    friend std::istream& operator>>(std::istream& in, const Graph& g)
    {
        for (int i = 0; i < g.tops; ++i)
        {
            for (int j = 0; j < g.side; ++j)
            {
                in >> g.matrix[i][j];
            }
        }
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const Graph& g)
    {
        for (int i = 0; i < g.tops; ++i)
        {
            for (int j = 0; j < g.side; ++j)
            {
                out << g.matrix[i][j] << ' ';
            }
            out << std::endl;
        }
        return out;
    }
    int Count_The_Number_Of_Units()
    {
        int in = 0;
        for (int i = 0; i < tops; ++i)
        {
            for (int j = 0; j < side; ++j)
            {
                if (matrix[i][j] == 1) in++;
            }
        }
        return in;
    }
    int* Create_An_Adjacency_Array(int n)
    {
        int size_ans = n + tops + 1;
        int* ans = new int[size_ans] {0};
        //int counter1 = 0;
        int counter2 = tops + 1;
        for (int i = 0; i < tops; ++i)
        {
            ans[i + 1] = counter2;
            for (int j = 0; j < side; ++j)
            {
                if (matrix[i][j] == 1)
                {

                    for (int q = 0; q < tops; ++q)
                    {
                        if (matrix[q][j] == 1 && q != i)
                        {
                            //std::cout << counter2 << " " << size_ans << std::endl;
                            ans[counter2++] = q + 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


void Print(const int* arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        std::cout << i << " ";
        std::cout << arr[i] << std::endl;
    }
}
int main()
{
    std::ifstream in("FileName.txt");
    int tops, side;
    in >> tops >> side;
    Graph my_graph = Graph(tops, side);
    in >> my_graph;
    std::cout << my_graph;
    std::cout << std::endl;
    int number_of_units = my_graph.Count_The_Number_Of_Units();
    int* adjacency_array = my_graph.Create_An_Adjacency_Array(number_of_units);
    Print(adjacency_array, number_of_units + tops + 1);
    in.close();
    return 0;

}