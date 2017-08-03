#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void circularRotate(int a[],int n,int k){
    int* arrPtr = new int[k];
    for(int i = 0 ; i < k ; ++i)
        arrPtr[i] = a[n - 1 - i];
    for(int i = n-k-1 ; i >= 0; --i)
        a[i+k] = a[i];
    for(int i = 0; i < k; ++i){
        a[k-i-1] = arrPtr[i];
    }
    delete arrPtr;
}

int main() {
    int n,k,q,m;
    int a[100000];
    cin >> n >> k >> q;
    for (int i = 0 ; i < n ; ++i)
        cin >> a[i];
    for (int i = 0 ; i < n ; ++i)
        cout << a[i] << " ";
    circularRotate(a,n,k);
    cout<<"rotate array complete";
    while(q-- > 0){
        cin >> m;
        cout << a[m];
    }
    return 0;
}
