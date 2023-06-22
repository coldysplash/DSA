#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "binarysearch.h"

int compare(const void * x1, const void * x2) // Comparison function
{
  return ( *(int*)x1 - *(int*)x2 );
}

int main(){
    int *arr;
    int key = 19; // necessary element
    size_t n = 1000; // Number of elements
    arr = malloc(sizeof(*arr) * n);
    for(int i = 0; i < n; i++){
        arr[i] = rand() / (((int)RAND_MAX / 300) + 1);
    }
    qsort(arr, n, sizeof(int), compare);
    
    int index_result = binary_search(arr, n, key);
    printf("Index of the key element: %d\n", index_result);
    free(arr);

    return 0;
}