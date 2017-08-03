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

int max_distance(vector<int> &s, int n) {
    sort(begin(s), end(s));
    auto max_dist = s[0];
    for(auto i=0; i<s.size()-1; ++i) {
        auto dist = (s[i + 1] - s[i]) / 2;
        max_dist = max(max_dist, dist);
    }
    auto dist_last = (n-1 - s[s.size()-1]);
    max_dist = max(max_dist, dist_last);
    return max_dist;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m);
    for (auto& e : s)
        cin >> e;
    cout << max_distance(s, n) << endl;
    system("pause");
    return 0;
}
