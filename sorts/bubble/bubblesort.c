#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubble(int arr[], int size){
    int i, j, temp;
    for(i = 0; i < size; i++){
	    for(j = 0; j < size - 1; j++){
	        if(arr[j] > arr[j + 1]){
		        temp = arr[j];
		        arr[j] = arr[j + 1];
		        arr[j + 1] = temp;
	        }
	    }
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
    arr[size] = bubble(arr,size);
    printf("\n");
    printf("Sorted massive - ");
    for(int i = 0; i < size; i++){
	printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}