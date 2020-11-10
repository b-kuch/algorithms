#include "bubblesort.h"

void bubblesort(int size, int* array, bool (*compare_f)(int, int))
{
    while (size>1)
    {
        for (int i=0; i<size-1; i++)
        {
            if (!(*compare_f)(array[i],array[i+1]))  // NOT TRUE aby użyć tego samego porównania co w QS i sprawdzaniu
            {
                swap(&array[i],&array[i+1]);
            }
        }
        size--;
    }
}