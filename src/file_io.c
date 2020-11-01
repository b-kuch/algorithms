#include "file_io.h"

bool file_exists(char* fname)
{
    FILE *f = fopen(fname, "r");
    if (f == NULL)
    {
        fclose(f);
        return false;
    }
    else
    {
        fclose(f);
        return true;
    }
}
int save_random_list(int n, char* fname)
{
    srand(time(NULL));
    FILE *f = fopen(fname, "w");
    for (int i=0;i<n;i++)
    {
        fprintf(f,"%d\n", rand()%100 + 0);
    }
	fclose(f);
    return n;
}

void save_list_to_file(int n, int* arr, char* fname)
{
    FILE *f = fopen(fname, "w");
    for (int i=0;i<n;i++)
    {
        fprintf(f,"%d\n", *(arr+i) );
    }
	fclose(f);
}

int load_number_file_to_array(int** arr, char* fname)
{
    if (!file_exists(fname))
    {
        printf("Nie znaleziono pliku %s\n", fname);
        return 0;
    }
    int x;
    int n=0;
    FILE *f = fopen(fname, "r");

    while (fscanf (f, "%d",&x) != EOF)
    {
        n++;
    }
    rewind(f);


    *arr =(int*) malloc(n * sizeof(int));

    
    int i=0;
    while (fscanf (f, "%d", &(*arr)[i]) != EOF)
    {
        i++;
    }

    fclose(f);
    return n;
}