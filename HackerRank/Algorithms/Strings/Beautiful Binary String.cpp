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

int min_steps(string &s) {
    auto count = 0;
    for(auto pos=s.find("010"); pos !=string::npos; pos = s.find("010", pos+3)) {
        s[pos + 2] = '1';
        ++count;
    }
    return count;
}


int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << min_steps(s) << endl;
    system("pause");
    return 0;
}
