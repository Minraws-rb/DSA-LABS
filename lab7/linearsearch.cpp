#include<iostream>
using namespace std;

int linearsearch(int arr[], int n, int v) {
    int i;
    for( i = 0 ; i < n ; i++) {
        if(arr[i] == v) return i;
    }
    return -1;
}

int main() {
    int arr[] = {5,6,2,4,1,7,9,0,3};
    int value;
    int index;
    cout<<"Enter the number you want to search"<<endl;
    cin>>value;
    index = linearsearch(arr, 9, value);
    if(index == -1) {
        cout<<"Number not found!!"<<endl;
    }
    else {
        cout<<"Found on "<< index<<" index"<<endl;
    }
    return 0;
}