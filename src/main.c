#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "file_io.h"
#include "heapsort_rec.h"
#include "heapsort_iter.h"
#include "util.h"

#define MLD 1000000000.0

// ifndef to hide error from IDE
#ifndef CLOCK_PROCESS_CPUTIME_ID
#define CLOCK_PROCESS_CPUTIME_ID 1
#endif

int main()
{
    struct timespec tp0, tp1;
    double Tn,Fn;
    int* heap;
    char fname[1000]="numbers/nums.txt";
    bool sorted = true;
    srand(time(NULL));
    // for(int n=1024;n<=1024*pow(2,20)&&sorted;n*=2)
    // {
    //     save_random_list(n, fname);
    //     load_number_file_to_array(&heap,fname);

    //     clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);
    //     heap_sort_iter(n, heap);
    //     clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);

    //     sorted = is_sorted(n, heap);
    //     free(heap);

    //     Fn = n*log2(n);
        
    //     Tn = (tp1.tv_sec+tp1.tv_nsec/MLD) - (tp0.tv_sec+tp0.tv_nsec/MLD);
    //     printf("n: %5d\t czas: %4.3lf \twspolczynnik: %3.0lf\t Fn=%3.0lf \n", n,  Tn, Fn/Tn, Fn);
    // }

    int n = 1000;
    save_random_list(n, fname);
    load_number_file_to_array(&heap,fname);
    // print_list(n, heap);
    // print_heap(n, heap);
    heap_sort_iter(n, heap);
    printf("\nJeden jeśli lista posortowana nierosnąco: %d\n\n", is_sorted(n, heap, &smaller));
    save_list_to_file(n, heap, fname);
    // print_list(n, heap);
    // print_heap(n, heap);
    free(heap);
    return 0;
}