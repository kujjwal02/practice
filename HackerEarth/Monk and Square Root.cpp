#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;

ll solution(ll n, ll m){
    for(ll i=0; i<m; ++i){
        //if(i>166000)
        //cout << "i: " << i << " (i*i)%m = " << (i*i)%m << " n= " << n << " " << (int)((i*i)%m==n) << endl;
        if((i*i)%m==n)
            return i;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests;
    cin >> tests;
    while(tests--){
        ll n,m;
        cin >> n >> m;
        cout << solution(n,m) << endl;
    }

    return 0;
}
