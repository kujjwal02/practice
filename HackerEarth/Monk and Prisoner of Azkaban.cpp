#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> v(n+2);
    v[0] = LLONG_MAX;
    v[n+1] = LLONG_MAX;
    for(ll i=1; i<=n; ++i)
        cin >> v[i];
    vector<ll> x(n+1);
    vector<ll> y(n+1);
    //x[0] = LONG_MAX;
    x[1] = 0;
    for(ll i=2; i<=n; ++i){
        if(v[i] < v[i-1])
            x[i] = i-1;
        else{
            ll j = x[i-1];
            while(v[i] >= v[j])
                j = x[j];
            x[i] = j;
        }
    }
    y[n] = n+1;
    for(ll i=n-1; i>0; --i){
        if(v[i] < v[i+1])
            y[i] = i+1;
        else{
            ll j=y[i+1];
            while(v[i] >= v[j])
                j = y[j];
            y[i] = j;
        }
    }

    for(ll i=1; i<=n; ++i){
        if(x[i] == 0)
            x[i] = -1;
        if(y[i] == n+1)
            y[i] = -1;
        cout << x[i] + y[i] << " ";
    }

    return 0;
}

