#include "bubblesort.h"

void bubblesort(int n, int* array, bool (*compare_f)(int, int))
{
    while (n>1)
    {
        for (int i=0; i<n-1; i++)
        {
            if ((*compare_f)(array[i],array[i+1]))
            {
                swap(&array[i],&array[i+1]);
            }
        }
        n--;
    }
}

//  procedure bubbleSort( A : lista elementów do posortowania )
//    n = liczba_elementów(A)
//     do
//      for (i = 0; i < n-1; i++) do:
//        if A[i] > A[i+1] then
//          swap(A[i], A[i+1])
//        end if
//      end for
//      n = n-1
//    while n > 1
//  end procedure