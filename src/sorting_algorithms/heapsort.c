#include "sorting_algorithms/heapsort.h"

void heapify_iterative(int heap_size, int *heap, int parent)
{
    int left, right;
    int larger = parent;
    while (true)
    {
        left = 2 * parent + 1;
        right = 2 * parent + 2;
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
        parent = larger;
    }
}

void heapify_recursive(int heap_size, int *heap, int parent)
{
    int left, right, larger;
    larger = parent;
    left = 2 * parent + 1;
    right = 2 * parent + 2;
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

void build_heap(int heap_size, int *heap, void (*heapify)(int, int *, int))
{
    for (int i = heap_size / 2 - 1; i >= 0; i--)
    {
        (*heapify)(heap_size, heap, i);
    }
}

void heap_sort(int heap_size, int *heap, void (*heapify)(int, int *, int))
{
    build_heap(heap_size, heap, heapify);
    for (int i = heap_size - 1; i >= 0; i--)
    {
        swap(&heap[0], &heap[i]);
        (*heapify)(i, heap, 0);
    }
}

void heap_sort_iterative(int heap_size, int *heap)
{
    heap_sort(heap_size, heap, heapify_iterative);
}

void heap_sort_recursive(int heap_size, int *heap)
{
    heap_sort(heap_size, heap, heapify_recursive);
}

void print_heap(int heap_size, int *heap)
{
    if (heap_size >= MAX_PRINTABLE_HEAP)
    {
        printf("n too big for console.\n");
        return;
    }
    int levels = heap_levels(heap_size);
    for (int i = 1; i < heap_size + 1; i *= 2)
    {
        spaces(pow(2, levels - 1) - 1);

        for (int j = 0; j < i && i - 1 + j < heap_size; j++)
        {
            printf("%d", heap[i - 1 + j]);
            spaces(pow(2, levels) - 1);
        }
        levels--;
        printf("\n");
    }
}

int heap_levels(int n)
{
    return ceil(log2(n));
}
