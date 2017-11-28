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
    int romanToInt(string s) {
        auto result{ 0 };
        for(auto i=0; i<s.size(); ++i) {
            const auto s1 = value(s[i]);

            if (i + 1 < s.size()) {
                const auto s2 = value(s[i + 1]);
                if (s1 >= s2)
                    result += s1;
                else {
                    result += s2 - s1;
                    ++i;
                }
            }
            else
                result += s1;
        }

        return result;
    }

    int value(char c) {
        switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
        }
    }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("IX") << '\n';
    cout << solution.romanToInt("XL") << '\n';
    cout << solution.romanToInt("MCMIV") << '\n';
    cout << solution.romanToInt("DCXXI") << '\n';
    system("pause");
    return 0;
}
