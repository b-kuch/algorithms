#ifndef TIME_COMPLEXITY_FUNCTIONS
#define TIME_COMPLEXITY_FUNCTIONS

    #include <time.h>
    #include <stdbool.h>
    #define MLD 1000000000.0

    double my_timeit(void (*function_pointer)(int, int*), int array_size, int* array);
    double my_timeit6
    (
        void (*function_pointer)(int,  int,  int,  int *,
            int (*)(int,  int,  int *), bool (*)(int,  int)),
        int p,
        int r,
        int array_size,
        int* array,
        int (*divider)(int, int, int*), bool (*compare_f)(int, int)
    );

#endif