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


ll my_rank(vector<ll> &scores, ll my_score ) {
    auto pos = lower_bound(scores.begin(), scores.end(), my_score, greater<ll>());
    return pos - scores.begin() + 1;
}



int main() {
    ll n;
    cin >> n;
    vector<ll> ranks;
    ranks.reserve(n);
    for(ll i=0, prev=-1; i<n; ++i) {
        ll input;
        cin >> input;
        if(input == prev)
            continue;
        ranks.push_back(input);
        prev = input;
    }

    ll m;
    cin >> m;
    while(m--) {
        ll score;
        cin >> score;
        cout << my_rank(ranks, score) << endl;
    }
    system("pause");
    return 0;
}
