#include<bits/stdc++.h>
using namespace std;

void insertion(int a[], int &n,int v, int p) {
    cout<< n<< v<< p<<endl;
    int i;
    for(i = n; i>p; i--) {
        a[i] = a[i-1];
    }
    a[p] = v;
    n++;
}

int main() {
    int a[100] = {1,2,3,5,6,7,8,9};
    int n = 8;
    insertion(a, n, 4, 3);
    for(int i = 0; i<n ; i++) {
        cout<<a[i]<<" ";
    }
    return 0;

}