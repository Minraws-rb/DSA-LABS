#include<bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int n, int v) {
    int i = 0, l = n - 1, m;
    while (i <= l) {
        m = (i + l)/2;
        if(arr[m] == v){
            return m;
        }
        if(v < arr[m]) {
            l = m-1;
        } else {
            i = m+1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5,6,2,4,1,7,9,3};
    int n = 9;
    int value = 1, index;
    sort(arr, arr + n);
    index = binarysearch(arr, n, value);
        if(index == -1) {
        cout<<"Number not found!!"<<endl;
    }
    else {
        cout<<"Found on "<< index<<" index"<<endl;
    }
    return 0;
}