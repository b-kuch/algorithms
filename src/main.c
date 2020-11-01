#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "file_io.h"
#include "heapsort_rec.h"
#include "heapsort_iter.h"
#include "util.h"
#include "time_complexity.h"

double Fn(int n)
{
    return n*log2(n);
}

int main()
{
    double Tn;
    int* arr;
    char fname[1000]="numbers/nums.txt";
    bool sorted = true;
    srand(time(NULL));
    for(int n=1024;n<=1024*pow(2,20)&&sorted;n*=2)
    {
        save_random_list(n, fname);
        load_number_file_to_array(&arr,fname);
        Tn = my_timeit(&heap_sort_iter, n, arr);
        sorted = is_sorted(n, arr, &smaller);
        free(arr);
        print_complexity(n, Tn, &Fn);
    }

    // int n = 1000;
    // save_random_list(n, fname);
    // load_number_file_to_array(&arr,fname);
    // // print_list(n, arr);
    // // print_heap(n, arr);
    // heap_sort_iter(n, arr);
    // printf("\nJeden jeśli lista posortowana nierosnąco: %d\n\n", is_sorted(n, arr, &smaller));
    // save_list_to_file(n, arr, fname);
    // // print_list(n, arr);
    // // print_heap(n, arr);
    // free(arr);
    return 0;
}