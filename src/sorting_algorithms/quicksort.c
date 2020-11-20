#include "sorting_algorithms/quicksort.h"

int rightmost_partition(
    int p,
    int r,
    int *array,
    bool (*compare_f)(int, int))
{
    int div = array[r];
    int q = p - 1;
    for (int i = p; i <= r; i++)
    {
        if ((*compare_f)(array[i], div))
        {
            q++;
            swap(&array[i], &array[q]);
        }
    }

    if (q < r)
    {
        return q;
    }
    else
    {
        return q - 1;
    }
}

int randomized_partition(
    int p,
    int r,
    int *array,
    bool (*compare_f)(int, int))
{
    srand(time(NULL));
    int k = p + rand() % (r - p + 1);
    swap(array + k, array + r);
    return rightmost_partition(p, r, array, compare_f);
}

int median_partition(
    int p,
    int r,
    int *array,
    bool (*compare_f)(int, int))
{
    int m = (p + r) / 2;
    if (array[m] < array[p])
    {
        swap(&array[p], &array[m]);
    }
    if (array[r] < array[p])
    {
        swap(&array[p], &array[r]);
    }
    if (array[m] < array[r])
    {
        swap(&array[m], &array[r]);
    }
    return rightmost_partition(p, r, array, compare_f);
}

void quicksort(
    int p,
    int r,
    int *array,
    bool (*compare_f)(int, int),
    int (*partition_method)(int, int, int *, bool (*)(int, int)))
{
    if (r > p)
    {
        int pivot = (*partition_method)(p, r, array, compare_f);
        quicksort(p, pivot, array, compare_f, partition_method);
        quicksort(pivot + 1, r, array, compare_f, partition_method);
    }
}
