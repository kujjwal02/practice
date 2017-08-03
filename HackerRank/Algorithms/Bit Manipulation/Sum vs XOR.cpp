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

ll solve(ll n) {
    ll count{ 0 };
    while (n) {
        count += n % 2 ? 0 : 1;
        n /= 2;
    }
    return pow(2, count);
}


int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    system("pause");
    return 0;
}
