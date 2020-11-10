#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "file_io.h"
#include "util.h"


#include "quicksort.h"
#include "qs.h"
#include "bubblesort.h"
#include "insertsort.h"
#include "heapsort.h"

#define MLD 1000000000.0

// ifndef to hide error from IDE
#ifndef CLOCK_PROCESS_CPUTIME_ID
#define CLOCK_PROCESS_CPUTIME_ID 1
#endif

double Fn(int n)
{
    return n*log2(n);
}

int main()
{
    // int* arr;
    // struct timespec tp0, tp1;
    // double Tn = 0;
    // bool sorted = true;
    // srand(time(NULL));
    // for(int n=1024;n<=1024*pow(2,10)&&sorted;n*=2)
    // {
    //     create_array(n, &arr);
    //     my_quicksort(0, n-1, arr, &smaller_equal, 1);

    //     clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp0);
    //     my_quicksort(0, n-1, arr, &smaller_equal, 10);
    //     insertsort(n, arr, &smaller_equal);
    //     clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp1);
    //     Tn = (tp1.tv_sec+tp1.tv_nsec/MLD) - (tp0.tv_sec+tp0.tv_nsec/MLD);
    //     // printf("ge:%d se:%d\n",
    //     //     is_sorted(n, arr, &greater_equal),
    //     //     is_sorted(n, arr, &smaller_equal));
        
    //     sorted = is_sorted(n, arr, &smaller_equal);
    //     free(arr);
        
    //     print_complexity(n, Tn, &Fn);
    // }
    
    // int* arr;
    // int n = 2500;
    // struct timespec tp0, tp1;
    // double Tn = 0;
    // srand(time(NULL));

    // for(int i=0; i<n; i++){
        
    //     create_array(n, &arr);
    //     my_quicksort(0, n-1, arr, &smaller_equal, 10);

    //     clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp0);
    //     my_quicksort(0, n-1, arr, &smaller_equal, 10);
    //     clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp1);
    //     Tn += (tp1.tv_sec+tp1.tv_nsec/MLD) - (tp0.tv_sec+tp0.tv_nsec/MLD);
    //     free(arr);
    // }
    // printf("%.9lf\n", Tn/n);

    srand(time(NULL));
    int* arr;
    // int arr[] = {1, 5, 7, 2, 5, 4};
    int n = 65536*2;
    bool (*cmp)(int,int)  = &smaller_equal;
    
    create_array(n,&arr);
    
    // print_list(n, arr);
    // my_quicksort(0, n-1, arr, cmp, 1);
    // quicksort(0, n-1, arr, cmp, &median_partition);
    my_quicksort(0, n-1, arr, cmp, 1);
    // bubblesort(n, arr, cmp);
    // insertsort(n, arr, cmp);
    // heap_sort_recursive(n, arr);

    printf(">=:%d <=:%d\n",
            is_sorted(n, arr, &greater_equal),
            is_sorted(n, arr, &smaller_equal));


    // print_list(n, arr);
    free(arr);

    return 0;
}