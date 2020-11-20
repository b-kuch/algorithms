#include "sorting_algorithms/insertsort.h"

void insertsort(int size, int* array, bool(*compare_f)(int, int))
{
    for (int i=0;i<size;i++)
    {
        int l, r, key, m;
			key = array[i];
			l = 0;
			r = i-1;
			while ( l<=r )  //szukanie binarne miejsca w posortowanej liście
			{
				m=(l+r)/2;
				if((*compare_f)(key, array[m]))
				{
					r = m-1;
				} else {
					l = m+1;
				}
			}
			for(int j=i-1; j>=l; --j)   
			{
				array[j+1] = array[j];
			}
				array[l] = key;	// wstawienie elementu na miejsce w posortowanej liście
    }
}