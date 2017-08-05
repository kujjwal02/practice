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

string super_reduced_string(string &s) {
    for(int i=0; (i+1)<s.size();) {
        if (s[i] == s[i + 1]) {
            s.erase(i, 2);
            i = max(0, i - 1);
        }
        else
            ++i;
    }

    if (!s.size())
        return "Empty String";
    return s;
}


int main() {
    string s;
    cin >> s;
    cout << super_reduced_string(s) << endl;
    system("pause");
    return 0;
}
