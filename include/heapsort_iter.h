#ifndef HEAPSORT_ITER_FUNTIONS
#define HEAPSORT_ITER_FUNTIONS

    #include <stdbool.h>

    #include "util.h"

    void heapify_iter(int heap_size, int* heap, int parent);
    void build_heap_iter(int heap_size, int* heap);
    void heap_sort_iter(int heap_size, int* heap);

#endif
