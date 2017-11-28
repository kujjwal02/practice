#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return string{};
        if (strs.size() == 1)
            return strs[0];
        int min_length = (*min_element(strs.begin(), strs.end(), [](auto a, auto b) {return a.size() < b.size(); })).size();
        auto length{ 0 };
        for(auto i{0}; i<min_length; ++i) {
            auto c = strs[0][i];
            if (!all_of(strs.begin(), strs.end(), [&](auto s) {return s[i] == c; }))
                break;
            ++length;
        }
        return strs[0].substr(0, length);
    }
};

int main() {
    Solution solution;
    system("pause");
    return 0;
}
