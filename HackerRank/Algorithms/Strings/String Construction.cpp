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

ll cost(string &s) {
    unordered_set<char> char_set;
    for (auto c : s)
        char_set.insert(c);
    return char_set.size();
}


int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        cout << cost(s) << endl;
    }
    return 0;
}
