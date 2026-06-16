#include<bits/stdc++.h>
using namespace std;

void deletion(int a[], int &n, int pos){
    int i;
    for(i = pos; i<n-1 ; i++) {
        a[i] = a[i+1];
    }
    n--;
    
}
int main() {
    int a[100] = {1,2,3,4,5,2,6,7,8,9};
    int n = 10;
    int i;
    deletion(a, n, 5);
    for( i = 0; i<n; i++) {
        cout<< a[i] << " ";
    }
    return 0;
}