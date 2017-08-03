#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int n,k,weights[100];
        int total_sum = 0;
        cin >> n >> k;
        for(int i=0; i<n; ++i){
            cin >> weights[i];
            total_sum += weights[i];
        }
        sort(weights,weights+n);
        k = min(k,n-k);
        int small_sum = 0;
        for(int i=0; i<k; ++i)
            small_sum += weights[i];
        int diff = total_sum -2*small_sum;
        cout <<diff<<endl;
    }
    return 0;
}
