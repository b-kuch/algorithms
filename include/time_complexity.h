#ifndef TIME_COMPLEXITY_FUNCTIONS
#define TIME_COMPLEXITY_FUNCTIONS

    #include <stdio.h>
    #include <time.h>

    #define MLD 1000000000.0

    double my_timeit(void (*function_pointer)(int, int*), int array_size, int* array);
    void print_complexity(int n, double time, double(*function_pointer)(int));
#endif