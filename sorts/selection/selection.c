#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selection_sort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int min_i = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min_i]){
                min_i = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_i];
        arr[min_i] = temp;
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
    arr[size] = selection_sort(arr,size);
    printf("\n");
    printf("Sorted massive   - ");
    for(int i = 0; i < size; i++){
	printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}