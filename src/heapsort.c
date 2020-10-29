#include "heapsort_rec.h"

void heapify_recursive(int heap_size, int* heap, int parent)
{
    int left, right, larger;
    larger = parent;
    left    = 2*parent+1;
    right   = 2*parent+2;
    if (left < heap_size && heap[left] < heap[larger])
    {
        larger = left;
    }
    if (right < heap_size && heap[right] < heap[larger])
    {
        larger = right;
    }
    if (larger != parent)
    {
        swap(&heap[parent], &heap[larger]);
        heapify_recursive(heap_size, heap, larger);
    }
}

void build_heap_recursive(int heap_size, int* heap)
{
    for(int i=heap_size/2-1;i>=0;i--)
    {
        heapify_recursive(heap_size, heap, i);
    }
}

void heap_sort_recursive(int heap_size, int* heap)
{
    build_heap_recursive(heap_size, heap);
    for(int i=heap_size-1;i>=0;i--)
    {
        swap(&heap[0], &heap[i]);
        heapify_recursive(i, heap, 0);
    }
}