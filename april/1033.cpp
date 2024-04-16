#include <iostream>

int main()
{
    int unknow, know, n, ans, x, y;
    int adjacent_cells_x[4] = { -1, 0, 0, 1 },
        adjacent_cells_y[4] = { 0, 1, -1, 0 };
    int cell_coordinates_x[33 * 33];
    int cell_coordinates_y[33 * 33];
    char maze[35][35];
    bool path_traveled[35][35];
    memset(path_traveled, 0, 35 * 35 * sizeof(bool));
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        maze[0][i] = '#';
        maze[n + 1][i] = '#';
        maze[i][0] = '#';
        maze[i][n + 1] = '#';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> maze[i][j];
    unknow = 2;
    know = 0;
    ans = 0;
    cell_coordinates_x[1] = cell_coordinates_y[1] = 1;
    cell_coordinates_x[2] = cell_coordinates_y[2] = n;
    path_traveled[1][1] = 1;
    path_traveled[n][n] = 1;
    while (know < unknow)
    {
        know++;
        for (int i = 0; i < 4; i++)
        {
            x = cell_coordinates_x[know] + adjacent_cells_x[i];
            y = cell_coordinates_y[know] + adjacent_cells_y[i];
            if (maze[x][y] == '#')
                ans++;//Если соседняя клетка пустая, увеличиваем значение ans
            else if (path_traveled[x][y] == 0)
            {
                path_traveled[x][y] = 1;
                unknow++;
                cell_coordinates_x[unknow] = x;
                cell_coordinates_y[unknow] = y;
                //Если соседняя клетка не посещена,
                //помечаем ее как посещенную и добавляем в список неизвестных клеток.
            }
        }
    }
    std::cout << (ans - 4) * 9 << std::endl;//вычитания 4 учитывая угловые клетки
}