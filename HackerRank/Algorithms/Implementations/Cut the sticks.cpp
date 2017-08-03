#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int n;
    int smallest =INT_MAX;
    int newSmallest = INT_MAX;
    int largest = 0;
    int count = 0;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
       if(arr[arr_i] < smallest)
        smallest = arr[arr_i];
       if(arr[arr_i] > largest)
        largest = arr_i;
    }

    while(arr[largest] > 0)
    {
        count = 0;
        newSmallest = INT_MAX;
        for(int i = 0; i<n; ++i)
        {
            if(arr[i] > 0)
            {
                arr[i] -= smallest;
                ++count;
                if(arr[i] < newSmallest && arr[i] >0)
                    newSmallest = arr[i];
            }
        }
        cout << count<<endl;
        smallest = newSmallest;
    }

    return 0;
}
