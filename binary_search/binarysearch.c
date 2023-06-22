#include "stdio.h"
#include "stdlib.h"

int binary_search(int *arr, size_t length, int key){
    int low = 0; // left bound
    int high = length - 1; // right bound
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == key){
            return mid;
        }else if(key > arr[mid]){
            low = mid + 1;
        }else if(key < arr[mid]){
            high = mid - 1;
        }
    }
    fprintf(stderr, "Element not found\n");
    return -1;
}