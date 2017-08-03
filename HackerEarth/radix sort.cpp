#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int arr[1000];

const int range=10;

void count_sort(int n,int place){
    int freq[range] = {0};
    for(int i=0; i<n; ++i)
        ++freq[(arr[i]/place)%range];

    for(int i=1; i<range; ++i)
        freq[i] += freq[i-1];

    int result[n];
    for(int i=n-1; i>=0; --i){
        result[freq[(arr[i]/place)%range]-1] = arr[i];
        freq[(arr[i]/place)%range]--;
    }

    for(int i=0; i<n; ++i)
        arr[i]=result[i];
}

void display_arr(int n){
    for(int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void radix_sort(int n, int max_num){
    int place = 1;
    while(max_num){
        count_sort(n,place);
        display_arr(n);
        place*=10;
        max_num/=10;
    }
}

int main()
{
    int n;
    int max_num=INT_MIN;
    cin >> n;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        max_num = max(arr[i],max_num);
    }
    radix_sort(n,max_num);
    return 0;
}
