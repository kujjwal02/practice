#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <unordered_set>

using namespace std;

static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    unordered_set<char> brackets{ '(', ')', '{', '}', '[', ']' };
    unordered_map<char, char> bracket_pair{ {')', '('}, {'}', '{'}, {']', '['} };

public:
    bool isValid(string s) {
        stack<char> bracket_stack;
        for(auto c: s) {
            if(isBracket(c)) {
                if(isClosingBracket(c)) {
                    if (bracket_stack.empty())
                        return false;
                    if (bracket_stack.top() != bracket_pair[c])
                        return false;
                    bracket_stack.pop();
                }
                else
                    bracket_stack.push(c);
            }
        }

        return bracket_stack.empty() ? true : false;
    }



    bool isBracket(char c) {
        return brackets.find(c) != brackets.end();
    }
    bool isClosingBracket(char c) {
        return bracket_pair.find(c) != bracket_pair.end();
    }

};

int main() {
    Solution solution;
    system("pause");
    return 0;
}
