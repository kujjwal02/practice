#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;
using ll = long long;



int main() {
    ll n;
    cin >> n;
    set<ll> price;
    auto min_los = numeric_limits<ll>::max();
    for(ll i=0; i<n; ++i) {
        ll curr;
        cin >> curr;
        auto pos = price.upper_bound(curr);
        if (pos != price.end())
            min_los = min(min_los, *pos - curr);
        price.insert(curr);
    }
    cout << min_los << '\n';
    system("pause");
    return 0;
}
