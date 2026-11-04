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

void pointer_sort(){
    int a[]={25,3,75,10,8};
    int *p[10];
    for (int i=0;i<5;i++){
        p[i]=&a[i];
        int n=5;

        for (int i=0;i<n;i++){
            for (int j=0; j<n;j++){
                if (*p[i]<*p[i+1]){
                    int *temp=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;
                }
            }
        }

    }
}
void print_pointer_sorted(int a[],int n,int p[]){
    cout<<" Original array: ";
    for (int j=0;j<n;n++){
        cout<<a[i]<<" ";
    }
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<*p[i]<<" ";
    }
}
void pointerSort(int *arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
    
        while (j > 0 && *arr[j - 1] > *arr[j]) {
            int *temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void binary_insertionsort(int arr[],int size) {

    for (int i = 1; i < size; i++) {
        int key = arr[i]; 

    int low= 0;
    int high= size-1;

    while(low < high){
        int middle= (high+low)/2;
        if (key < arr[middle]) {
                high = middle - 1; //left half
            } 
        else {                        
                low = middle + 1;  //right half 
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
    
    printArray(arr2, size2);

    const int pointerCount = sizeof(arr2) / sizeof(arr2[0]);
    int *pointers[pointerCount];
    for (int i = 0; i < size2; i++) {
        pointers[i] = &arr2[i];
    }

    pointerSort(pointers,size2);

    std::cout<<"SORTED array 2: ";

    for (int i = 0; i < size2; i++) {
        std::cout << *pointers[i] << " ";
    }
    std::cout << "\nOriginal array 2 unchanged: ";
    printArray(arr2,size2);

    int arr3[] = {42, 17, 8, 99, 17, -3};
    int expected3[] = {-3, 8, 17, 17, 42, 99};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    std::cout << "UNSORTED array 3: ";
    printArray(arr3, size3);

    binary_insertionsort(arr3, size3);

    std::cout << "BINARY INSERTION SORT array 3: ";
    printArray(arr3, size3);

    for (int i = 0; i < size3; i++) {
        if (arr3[i] != expected3[i]) {
            std::cout << "Binary insertion sort test FAILED. Expected: ";
            printArray(expected3, size3);
            return 1;
        }
    }
    std::cout << "Binary insertion sort test PASSED.\n";

    
    return 0;

}
