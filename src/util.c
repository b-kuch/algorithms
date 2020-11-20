#include "util.h"

void create_array(int array_size, int **heap)
{
    (*heap) = malloc(sizeof(int) * array_size);

    for (int i = 0; i < array_size; i++)
    {
        (*heap)[i] = rand() % 10 + 0;
    }
}

void create_array_x(int array_size, int **heap, int x)
{
    (*heap) = malloc(sizeof(int) * array_size);

    for (int i = 0; i < array_size; i++)
    {
        (*heap)[i] = x;
    }
}

void spaces(int amount)
{
    for (int i = 0; i < amount; i++)
        printf(" ");
}

void print_array(int size, int *array)
{
    for (int *i = array; i < array + size; i++)
    {
        printf("%d ", *i);
    }
    printf("\n");
}

void print_complexity(int n, double time, double (*function_pointer)(int))
{
    double fn = (*function_pointer)(n);
    printf("n: %5d\t czas: %4.3lf \twspolczynnik: %3.0lf\t Fn=%3.0lf \n",
           n, time, fn / time, fn);
}

extern bool greater(int a, int b);
extern bool greater_equal(int a, int b);
extern bool smaller(int a, int b);
extern bool smaller_equal(int a, int b);

bool is_sorted(int size, int *array, bool (*compare_function)(int, int))
{
    if (size < 2)
    {
        return true;
    }
    for (int *i = array + 1; i < array + size; i++)
    {
        if (!(*compare_function)(*(i - 1), *i))
        {
            return false;
        }
    }
    return true;
}

extern void swap(int *a, int *b);

// if a<=x<=b
extern bool in_range(int x, int a, int b);
