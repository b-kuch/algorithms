#ifndef BUBBLESORT
#define BUBBLESORT

    #include <stdbool.h>

    #include "util.h"
    
    void bubblesort(int size, int* array, bool (*compare_f)(int, int));

#endif