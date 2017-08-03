#include <iostream>

using namespace std;

int bevarages_required(const int hurdles[],int n,int k){
    int count=0;
    for(int i=0; i<n; ++i){
        if(hurdles[i]>k){
            count += hurdles[i] - k;
            k= hurdles[i];
        }
    }
    return count;
}

int main()
{
    int n,k;
    cin >> n >> k;
    int hurdles[n];
    for(int i=0; i<n; ++i)
        cin >> hurdles[i];
    cout << bevarages_required(hurdles,n,k);
    return 0;
}
