#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int max_contigious_subArray_sum(int arr[], int n){
    int max_so_far = arr[0];
    int curr_max = arr[0];
    for(int i=1; i<n; ++i){
        curr_max = max(curr_max + arr[i],arr[i]);
        max_so_far = max(max_so_far,curr_max);
    }
    return max_so_far;
}

int max_subArray_sum(int arr[], int n){
    int max_so_far = INT_MIN;
    for(int i=0; i<n; ++i){
        if(arr[i] >0){
            if(max_so_far < 0)
                max_so_far = arr[i];
            else
                max_so_far += arr[i];
        }
        else
            if(max_so_far<0)
                max_so_far = max(max_so_far,arr[i]);
    }
    return max_so_far;
}

int main() {
    int t;
    cin >>t;
    while(t--){
        int n;
        int arr[100000];
        cin >> n;
        for(int i=0; i<n; ++i)
            cin >> arr[i];
        cout << max_contigious_subArray_sum(arr,n) << " "<< max_subArray_sum(arr,n) << endl;
    }
    return 0;
}
