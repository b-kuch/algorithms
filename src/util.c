#include "util.h"

void create_array(int array_size, int** heap)
{
    (*heap) = malloc(sizeof(int) * array_size);

    for(int i=0;i<array_size;i++)
    {
        (*heap)[i] = rand()%10 + 0;
    }
}

void create_array_x(int array_size, int** heap, int x)
{
    (*heap) = malloc(sizeof(int) * array_size);

    for(int i=0;i<array_size;i++)
    {
        (*heap)[i] = x;
    }
}


void spaces(int amount)
{
    for(int i=0; i<amount; i++)
        printf(" ");
}

void print_heap(int heap_size, int* heap)
{
    if(heap_size>=MAX_PRINTABLE_HEAP)
    {
        printf("n too big for console.\n");
        return;
    }
    int levels=heap_levels(heap_size);
    for(int i=1; i<heap_size+1 ;i*=2)
    {
        spaces(pow(2, levels-1)-1);

        for(int j=0; j<i&&i-1+j<heap_size;j++)
        {
            printf("%d", heap[i-1+j]);
            spaces(pow(2, levels)-1);
        }
        levels--;
        printf("\n");
    }
}

void print_list(int size, int* list)
{
    for(int* i=list;i<list+size;i++)
    {
        printf("%d ",*i);
    }
    printf("\n");
}

void print_complexity(int n, double time, double(*function_pointer)(int))
{
    double fn = (*function_pointer)(n);
    printf("n: %5d\t czas: %4.3lf \twspolczynnik: %3.0lf\t Fn=%3.0lf \n",
                n,  time, fn/time, fn);
}


bool greater(int a, int b)
{
    return a>b;
}

bool smaller(int a, int b)
{
    return a<b;
}

bool is_sorted(int size, int* list, bool (*compare_function)(int, int ))
{
    if(size<2)
    {
        return true;
    }
    for(int* i=list+1;i<list+size;i++)
    {
        if((*compare_function)(*(i-1),*i))
        {
            return false;
        }
    }
    return true;
}

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int heap_levels(int n)
{
    return ceil(log2(n));
}