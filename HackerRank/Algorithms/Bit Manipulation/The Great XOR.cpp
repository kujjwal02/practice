#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ll q;
    cin >> q;
    while(q--) {
        ll x;
        cin >> x;
        cout << static_cast<ll>(pow(2, 64 - __builtin_clzll(x)) - x - 1) << endl;
    }
    return 0;
}
