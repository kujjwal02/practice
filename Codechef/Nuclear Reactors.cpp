#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll a,n,k;
    cin >> a >> n >> k;
    ll chambers[100]{0};
    for(int i=0; i<k && a; ++i,a/=n+1)
        chambers[i] = a%(n+1);

    for(int i=0;i<k; ++i)
        cout << chambers[i] << " ";
    return 0;
}
