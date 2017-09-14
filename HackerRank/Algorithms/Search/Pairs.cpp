#include <iostream>
#include <cstdio>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <numeric>

using namespace std;

using ll = long long;

ll solve(vector<ll> &arr, ll diff) {
    ll count = 0;
    sort(begin(arr), end(arr));
    for(size_t i=0; i<(arr.size() - 1); ++i) {
        ll to_find = arr[i] + diff;
        auto pos = lower_bound(begin(arr) + i + 1, end(arr), to_find) - begin(arr);
        if (pos != arr.size() && arr[pos] == to_find)
            ++count;
    }
    return count;
}



int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (auto& e: arr)
        cin >> e;
    cout << solve(arr, k) << endl;
    return 0;
}
