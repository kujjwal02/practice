#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> saved;
        int first_index = 0;
        int length = 1;
        for(auto i=0; i<s.size(); ++i) {
            if (saved.find(s[i]) != saved.end()) {
//              length = max(length, i - saved[s[i]]);
//              length = max(length, saved[s[i]] - first_index + 1);
                length = max(static_cast<size_t>(length), saved.size());
                i = saved[s[i]];
                first_index = i + 1;
                saved.clear();
            }
            else
                saved[s[i]] = i;
        }

        if (!saved.empty())
            length = max(static_cast<size_t>(length), saved.size());

        return length;
    }
};


int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << '\n';
    cout << solution.lengthOfLongestSubstring("bbbbb") << '\n';
    cout << solution.lengthOfLongestSubstring("pwwkew") << '\n';
    cout << solution.lengthOfLongestSubstring("") << '\n';
    cout << solution.lengthOfLongestSubstring("p") << '\n';
    cout << solution.lengthOfLongestSubstring("au") << '\n';
    cout << solution.lengthOfLongestSubstring("cdd") << '\n';
    cout << solution.lengthOfLongestSubstring("abcb") << '\n';
    system("pause");
    return 0;
}
