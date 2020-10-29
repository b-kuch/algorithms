#include "heapsort_iter.h"


void heapify_iter(int heap_size, int* heap, int parent)
{
    int left, right;
    int larger = parent;
    while(true)
    {
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
        if (larger == parent)
        {
            break;
        }
        swap(&heap[parent], &heap[larger]);
        parent=larger;
    }
}

void build_heap_iter(int heap_size, int* heap)
{
    for(int i=heap_size/2-1;i>=0;i--)
    {
    heapify_iter(heap_size, heap, i);
    }
}

void heap_sort_iter(int heap_size, int* heap)
{
    build_heap_iter(heap_size, heap);
    for(int i=heap_size-1;i>=0;i--)
    {
        swap(&heap[0], &heap[i]);
        heapify_iter(i, heap, 0);
    }
}