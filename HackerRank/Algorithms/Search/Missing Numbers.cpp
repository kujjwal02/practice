#include <iostream>
#include <cstdio>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

using ll = long long;




int main() {
    ll n, m;
    cin >> n;
    map<ll, ll> freq;
    for(ll i=0; i<n; ++i) {
        ll input;
        cin >> input;
        ++freq[input];
    }
    cin >> m;
    for(ll i=0; i<m; ++i) {
        ll input;
        cin >> input;
        --freq[input];
    }
    for(auto& p : freq) {
        if (p.second < 0)
            cout << p.first << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
