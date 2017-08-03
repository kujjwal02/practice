#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;

ll no_of_points(vector<double> &v,double r){
    return upper_bound(v.begin(),v.end(),r) - v.begin();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<double> v(n);
    for(auto &e : v){
        ll x,y;
        cin >> x >>y;
        e = sqrt(x*x + y*y);
    }
    sort(v.begin(),v.end());
    ll q;
    cin >>q;
    while(q--){
        double r;
        cin >>r;
        //cout << r*r<<endl;
        cout << no_of_points(v,r) << endl;;
    }
    return 0;
}
