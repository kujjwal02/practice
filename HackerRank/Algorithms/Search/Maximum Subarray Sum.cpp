#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ll queries;
    cin >> queries;
    while(queries--) {
        ll n, m;
        cin >> n >> m;
        set<ll> prefix;
        ll max_sum = numeric_limits<ll>::min();
        ll curr_prefix = 0;
        for(ll i=0; i<n; ++i) {
            ll input;
            cin >> input;
            curr_prefix = ( curr_prefix + input%m )%m;
            max_sum = max(max_sum, curr_prefix);
            auto pos = prefix.upper_bound(curr_prefix);
            if(pos != prefix.end())
                max_sum = max(max_sum, (curr_prefix - *pos + m)%m);
            prefix.insert(curr_prefix);
        }
        cout << max_sum << '\n';
    }
    return 0;
}
