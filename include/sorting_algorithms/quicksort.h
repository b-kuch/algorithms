#ifndef QUICKSORT_FUNCTIONS
#define QUICKSORT_FUNCTIONS

#include <stdbool.h>
#include <stdlib.h>

// #include "quicksort.h"
#include "util.h"

int rightmost_partition(
    int p,
    int r,
    int *array,
    bool (*compare_f)(int, int));

int randomized_partition(
    int p,
    int r,
    int *array,
    bool (*compare_f)(int, int));

int median_partition(
    int p,
    int r,
    int *array,
    bool (*compare_f)(int, int));

void quicksort(
    int p,
    int r,
    int *array,
    bool (*compare_f)(int, int),
    int (*partition_method)(int, int, int *, bool (*)(int, int)));

#endif