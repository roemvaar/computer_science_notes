// utils.c - Auxiliary functions to make development easier

#include <stdio.h>

void print_array(int *array, size_t size)
{
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    printf("]\n");
}
