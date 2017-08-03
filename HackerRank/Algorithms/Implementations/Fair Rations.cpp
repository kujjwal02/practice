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

ll min_bread(vector<ll> &line) {
    ll count = 0;
    for(auto i=0; i<(line.size() - 1); ++i) {
        if(line[i]%2) {
            count += 2;
            line[i + 1] += 1;
        }
    }
    if (line[line.size() - 1] % 2)
        return -1;
    return count;
}




int main() {
    int n;
    cin >> n;
    vector<ll> line(n);
    for (auto& e : line)
        cin >> e;
    ll result = min_bread(line);
    if (result == -1)
        cout << "NO\n";
    else
        cout << result << endl;
    return 0;
}