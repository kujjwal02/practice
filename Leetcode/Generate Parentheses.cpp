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
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParanthesisHelper(res, n, 0, "");
        return res;
    }

    void generateParanthesisHelper(vector<string>& res, int left, int right, string prev) {
        if(left == 0 && right == 0) {
            res.push_back(prev);
            return;
        }
        if (right > 0)
            generateParanthesisHelper(res, left, right - 1, prev + ")");
        if (left > 0)
            generateParanthesisHelper(res, left - 1, right + 1, prev + "(");
    }
};

int main() {
    Solution solution;
    for (auto& s : solution.generateParenthesis(4))
        cout << s << '\n';
    system("pause");
    return 0;
}
