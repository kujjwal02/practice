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



int main() {
    ll t;
    cin >> t;
    ll k = log2((t + 2) / 3);
    cout << static_cast<ll>(3 * pow(2, k + 1) - t - 2) << endl;
    system("pause");
    return 0;
}
