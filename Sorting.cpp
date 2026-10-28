#include <iostream>
using namespace std;


void swapping(int& x, int& y ){
    int temp=x;
    x=y;
    y=temp;
}

void selectionSort(int arr[], int size) {
    // Loop through the entire array except the last element
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i; // Assume the first unsorted element is the minimum

        // Find the minimum element in the remaining unsorted array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index if a smaller element is found if arrj is less than the current minimum
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (min_idx != i) {
            swapping(arr[i], arr[min_idx]);
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j=i+1;
        // Inner loop moves backward, shifting larger elements
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
}

   void binary_insertionsort(int arr[],int size) {

    for (int i = 1; i < size; i++) {
        int key = arr[i]; //  key is the element to be inserted 

    int low= 0;
    int high= size-1;

    while(low < high){
        int middle= (high+low)/2;
        if (key < arr[middle]) {
                high = middle - 1; // Look in the left half
            } 
        else {                        //if(key > arr[middle] )
                low = middle + 1;  // Look in the right half 
            }
        

    }
    for (int j = i - 1; j >= low; j--) {
            arr[j + 1] = arr[j];
        }

       arr[low] = key;
    }
}


void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}


int main(){
    int arr[] = {11,5,7,23,4};

    int size=sizeof(arr)/sizeof(arr[0]);

    std::cout << "UNSORTED array:";
    
    printArray(arr, size);

    selectionSort(arr,size);

    std::cout<<"SORTED array: ";

    printArray(arr,size);


    int arr2[]= {101,206,141, 333, 717, 131};

    int size2= sizeof(arr2)/sizeof(arr2[0]);
    std::cout << "UNSORTED array 2:  ";
    
    printArray(arr2, size);

    binary_insertionsort(arr2,size2);

    std::cout<<"SORTED array 2: ";

    printArray(arr2,size2);

    
    return 0;

}
