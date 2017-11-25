#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return s;
        auto start = 0;
        auto max_length = 1;
        vector<vector<bool>> table(s.size(), vector<bool>(s.size(), false));
        for (auto i = 0; i < s.size(); ++i)
            table[i][i] = true;

        for(auto i=0; i<(s.size()-1); ++i) {
            if(s[i] == s[i+1]) {
                table[i][i + 1] = true;
                start = i;
                max_length = 2;
            }
        }

        for(auto length= 3; length <= s.size(); ++length) {
            for(auto i=0; i< (s.size() - length + 1); ++i) {
                auto j = i + length - 1;
                if (table[i + 1][j - 1] && s[i] == s[j]) {
                    table[i][j] = true;
                    start = i;
                    max_length = length;
                }
            }
        }

        return s.substr(start, max_length);
    }

};

int main() {
    Solution solution;
    cout << solution.longestPalindrome("ccc") << '\n';
    cout << solution.longestPalindrome("babad") << '\n';
    cout << solution.longestPalindrome("cbbd") << '\n';
    cout << solution.longestPalindrome("") << '\n';
    cout << solution.longestPalindrome("c") << '\n';
    system("pause");
    return 0;
}
