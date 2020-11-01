#ifndef TIME_COMPLEXITY_FUNCTIONS
#define TIME_COMPLEXITY_FUNCTIONS

    #include <time.h>

    #define MLD 1000000000.0

    double my_timeit(void (*function_pointer)(int, int*), int array_size, int* array);
#endif