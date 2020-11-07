#include "time_complexity.h"

// ifndef to hide error from IDE
#ifndef CLOCK_PROCESS_CPUTIME_ID
#define CLOCK_PROCESS_CPUTIME_ID 1
#endif

double my_timeit(void (*function_pointer)(int, int*), int array_size, int* array)
{
    struct timespec tp0, tp1;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp0);
    (*function_pointer)(array_size, array);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp1);
    return (tp1.tv_sec+tp1.tv_nsec/MLD) - (tp0.tv_sec+tp0.tv_nsec/MLD);
}

double my_timeitQS
    (
        void (*function_pointer)(int,  int,  int,  int *, int (*)(int,  int,  int *), bool (*)(int,  int)),
        int p,
        int r,
        int array_size,
        int* array,
        int (*divider)(int, int, int*),
        bool (*compare_f)(int, int)
    )
{
    struct timespec tp0, tp1;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp0);
    (*function_pointer)(p, r, array_size, array, divider, compare_f);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp1);
    
    return (tp1.tv_sec+tp1.tv_nsec/MLD) - (tp0.tv_sec+tp0.tv_nsec/MLD);
}
