#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
    unordered_map<char, string> h_map{
        { '0', "" },
        { '1', "" },
        { '2', "abc" },
        { '3', "def" },
        { '4', "ghi" },
        { '5', "jkl" },
        { '6', "mno" },
        { '7', "pqrs" },
        { '8', "tuv" },
        { '9', "wxyz" },
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result{};
        if (digits.size() == 0)
            return result;
        
        if(digits.size() == 1) {
            for (auto e : h_map[digits[0]])
                result.push_back(string{ e });
            return result;
        }

        if(digits.size() == 2) {
            for(auto e: h_map[digits[0]]) {
                for (auto f : h_map[digits[1]])
                    result.push_back(string{ e, f });
            }
            return result;
        }

        auto comb = letterCombinations(digits.substr(1));
        for(auto e: h_map[digits[0]]) {
            for(auto& s: comb) {
                result.push_back(string{ e } + s);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    auto res{ solution.letterCombinations("234") };
    for (auto& s : res)
        cout << s << '\n';
    system("pause");
    return 0;
}
