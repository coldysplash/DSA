#include <iostream>

using namespace std;

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
    cout << "Enter massive size >> ";
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++){
	arr[i] = rand()%10;
    }
    cout << "Unsorted massive - ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    arr[size] = bubble(arr,size);
    cout << "\n";
    cout << "Sorted massive - ";
    for(int i = 0; i < size; i++){
	cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}

