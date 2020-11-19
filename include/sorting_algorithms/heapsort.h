#ifndef HEAPSORT_FUNCTIONS
#define HEAPSORT_FUNCTIONS

#include <stdbool.h>

#include "util.h"

void heapify_iterative(int heap_size, int *heap, int parent);
void heapify_recursive(int heap_size, int *heap, int parent);

void build_heap(int heap_size, int *heap, void (*heapify)(int, int *, int));
void heap_sort(int heap_size, int *heap, void (*heapify)(int, int *, int));
void heap_sort_iterative(int heap_size, int *heap);
void heap_sort_recursive(int heap_size, int *heap);

#define MAX_PRINTABLE_HEAP 64
void print_heap(int heap_size, int *heap);
int heap_levels(int n);

#endif
