#ifndef UTIL_FUNCTIONS
#define UTIL_FUNCTIONS

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>
    #include <stdbool.h>
    
    void create_array(int array_size, int** array);
    void create_array_x(int array_size, int** array, int x);

    void spaces(int amount);

    #define MAX_PRINTABLE_HEAP 64
    void print_heap(int heap_size, int* heap);
    void print_list(int size, int* list);
    void print_complexity(int n, double time, double(*function_pointer)(int));  // TODO: add memory size in bytes

    bool greater(int a, int b);
    bool smaller(int a, int b);
    bool smaller_equal(int a, int b);
    bool is_sorted(int size, int* list, bool (*compare_function)(int, int ));
    void swap(int* a, int* b);
    int heap_levels(int n);

    int rightmost(int p, int r);
#endif