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


void sort_map(unordered_map<ll, vector<pair<ll, ll>>> &track) {
    for (auto& v : track)
        sort(begin(v.second), end(v.second));
}

vector<pair<ll, ll>> merged(vector<pair<ll, ll>> &list) {
    vector<pair<ll, ll>> merged_list;
    merged_list.push_back(list[0]);
    for (size_t i = 1; i<list.size(); ++i) {
        auto next = list[i];
        if (next.first > merged_list.back().second) {
            merged_list.push_back(next);
            break;
        }
        merged_list.back().second = max(next.second, merged_list.back().second);
    }
    return merged_list;
}

void merge_tracks(unordered_map<ll, vector<pair<ll, ll>>> &track) {
    sort_map(track);
    for(auto& v : track) {
        v.second = merged(v.second);
    }
}

ll vacant_count(unordered_map<ll, vector<pair<ll, ll>>> &track, ll n, ll m) {
    merge_tracks(track);
    ll count = n*m;
    for(auto& p_v : track) {
        for(auto& p : p_v.second) {
            count -= p.second - p.first + 1;
        }
    }
    return count;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    unordered_map<ll,vector<pair<ll,ll>>> track;
    for(ll i=0; i<k; ++i) {
        ll r, c1, c2;
        cin >> r >> c1 >> c2;
        track[r].push_back(make_pair(c1, c2));
    }
    cout << vacant_count(track, n, m) << endl;
    system("pause");
    return 0;
}
