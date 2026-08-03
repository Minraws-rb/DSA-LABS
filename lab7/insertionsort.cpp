#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n) {
    int temp, i, j;
    for(i = 1; i< n ; i++) {
        temp = arr[i];
        j = i-1;
        while(temp < arr[j] && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main() {
    int arr[10] = {5, 2, 9, 1, 5, 6, 3, 7, 8, 4};
    insertion_sort(arr, 10);
    for(int i = 0; i<10 ; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
    
}