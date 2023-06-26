#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertion_sort(int arr[], int size){
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr[size];
}

int main(){

    srand(time(NULL));
    int size;
    printf("Enter massive size >> ");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++){
	arr[i] = rand()%10;
    }
    printf("Unsorted massive - ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    arr[size] = insertion_sort(arr,size);
    printf("\n");
    printf("Sorted massive - ");
    for(int i = 0; i < size; i++){
	printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}