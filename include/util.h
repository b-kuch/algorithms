#ifndef UTIL_FUNCTIONS
#define UTIL_FUNCTIONS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

void create_array(int array_size, int **array);
void create_array_x(int array_size, int **array, int x);

void spaces(int amount);
void print_array(int size, int *array);
void print_complexity(int n, double time, double (*function_pointer)(int));

inline bool greater(int a, int b);
inline bool greater_equal(int a, int b);
inline bool smaller(int a, int b);
inline bool smaller_equal(int a, int b);

bool is_sorted(int size, int *array, bool (*compare_function)(int, int));
inline void swap(int *a, int *b);
inline bool in_range(int x, int a, int b);

#define ASCII_DIGITS 48, 57
#define ASCII_UPPERCASE 65, 90
#define ASCII_LOWERCASE 97, 122

#endif