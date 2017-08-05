#include <iostream>
#include <cstdio>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll min_towers(vector<ll> &seq, ll k) {
    ll count = 0;
    auto pos = 0;
    while(pos < seq.size()) {
        ++count;
        int tower_loc = seq[pos] + k;
        while (pos < seq.size() && seq[pos] <= tower_loc) ++pos;
        tower_loc = seq[pos-1] + k;
        while (pos < seq.size() && seq[pos] <= tower_loc) ++pos;
    }
    return count;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> seq(n);
    for (auto& e : seq)
        cin >> e;
    sort(begin(seq), end(seq));
    cout << min_towers(seq, k) << endl;
    system("pause");
    return 0;
}
