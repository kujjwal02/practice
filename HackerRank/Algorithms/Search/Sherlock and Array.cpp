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

string solve(vector<ll> & arr) {
    if (arr.size() == 1)
        return "YES";
    if (arr.size() < 3)
        return "NO";

    ll left_sum = arr[0];
    ll right_sum = accumulate(begin(arr) + 2, end(arr), static_cast<ll>(0));
    ll curr_pos = 1;
    while(curr_pos < (arr.size() - 1)) {
        if (left_sum == right_sum)
            return "YES";
        left_sum += arr[curr_pos];
        ++curr_pos;
        right_sum -= arr[curr_pos];
    }

    return "NO";
}


int main() {
    ll queries;
    cin >> queries;
    while(queries--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (auto& e : arr)
            cin >> e;
        cout << solve(arr) << endl;
    }
    return 0;
}
