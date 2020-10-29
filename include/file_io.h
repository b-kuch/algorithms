#ifndef IO_FUNCTIONS
#define IO_FUNCTIONS

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <time.h>
    #include <string.h>

    bool file_exists(char* fname);
    int save_random_list(int n, char* fname);
    void save_list_to_file(int n, int* arr, char* fname);
    int load_number_file_to_array(int** arr, char* name);


#endif
