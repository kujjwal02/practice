#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include <functional>

#define ll long long

using namespace std;

ll beautiful(vector<ll> &seq, int diff) {
    ll count = 0;
    auto exists = [&](int val)
    {return binary_search(begin(seq), end(seq), val); };

    for (auto e : seq)
        if (exists(e + diff) && exists(e + 2 * diff))
            ++count;
    return count;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<ll> seq(n);
    for (auto& c : seq)
        cin >> c;
    cout << beautiful(seq, d) << endl;
    system("pause");
    return 0;
}
