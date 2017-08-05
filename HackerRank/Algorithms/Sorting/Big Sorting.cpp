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


using ll = long long;

using namespace std;

bool less_str(string &l, string &r) {
    if (l.size() == r.size())
        return l < r;
    return l.size() < r.size();
}

int main() {
    ll n;
    cin >> n;
    vector<string> arr(n);
    for (auto& s : arr)
        cin >> s;
    sort(begin(arr), end(arr), less_str);
    for (auto& s : arr)
        cout << s << endl;
    system("pause");
    return 0;
}
