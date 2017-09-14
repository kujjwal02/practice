#include <iostream>
#include <cstdio>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;


struct IceCream {
    ll index;
    ll cost;
    IceCream(ll index, ll cost):index(index), cost(cost) {}
    bool operator<(const IceCream &other) const {
        return this->cost < other.cost;
    }
    friend bool operator<(const IceCream & ice_cream, ll c) {
        return ice_cream.cost < c;
    }
};

pair<ll,ll> get_index(vector<IceCream> &parlor,  ll m) {
    sort(begin(parlor), end(parlor));
    for(ll i=0; i<parlor.size(); ++i) {
        ll to_find_cost = m - parlor[i].cost;
        auto pos = lower_bound(begin(parlor) + i + 1, end(parlor), to_find_cost) - begin(parlor);
        if (pos != parlor.size() && parlor[pos].cost == to_find_cost)
            return make_pair(parlor[i].index, parlor[pos].index);
    }
    return make_pair(-1, -1);
}


int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> m >> n;
        vector<IceCream> parlor;
        parlor.reserve(n);
        for(ll i=1; i<=n; ++i) {
            ll cost;
            cin >> cost;
            parlor.push_back(IceCream(i, cost));
        }
        auto indices = get_index(parlor, m);
        cout << min(indices.first, indices.second) << " " << max(indices.first, indices.second) << endl;
    }
    system("pause");
    return 0;
}
