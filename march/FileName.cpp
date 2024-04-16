#include <iostream>

// Перегрузка функции min для двух переменных
template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

// Шаблонная функция для сортировки двух переменных
template <typename T>
void sort(T& a, T& b)
{
    T min_val = min(a, b);
    if (min_val == a)
    {
        b = a;
    }
    else
    {
        a = b;
        b = min_val;
    }
}