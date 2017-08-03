#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <cmath>
#include <algorithm>
#include <functional>

#define ll long long

using namespace std;






int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> imp;
    imp.reserve(n);
    ll total_luck = 0;
    while(n--) {
        ll luck, important;
        cin >> luck >> important;
        if (important)
            imp.push_back(luck);
        else
            total_luck += luck;
    }

    sort(begin(imp), end(imp), greater<ll>());
    for (auto i = 0; i < k && i < imp.size(); ++i)
        total_luck += imp[i];
    for (auto i = k; i < imp.size(); ++i)
        total_luck -= imp[i];

    cout << total_luck << endl;
    return 0;
}
