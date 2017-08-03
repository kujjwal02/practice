#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

int k;

int modulo_comp(const int &a,const int &b){
    return a%k < b%k;
}

int main()
{
    int n;
    cin >> n>>k;
    int arr[10000];
    for(int i=0;i<n; ++i)
        cin >> arr[i];
    stable_sort(arr,arr+n,modulo_comp);
    for(int i=0; i<n; ++i)
        cout << arr[i] << " ";
    return 0;
}
