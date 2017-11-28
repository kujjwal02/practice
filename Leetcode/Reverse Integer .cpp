#include <iostream>
#include <string>

using namespace std;

static int some = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int reverse(int x) {
//      cout << x << "\t";
        int result{ 0 };
        while(x) {
            result = result * 10 + x % 10;
//          cout << result << '\n';
            if (result % 10 != x % 10)
                return 0;
            x /= 10;
        }
        return result;
    }
};


int main() {
    Solution solution;
    cout << solution.reverse(123) << '\n';
    cout << solution.reverse(-123) << '\n';
    cout << solution.reverse(120) << '\n';
    cout << solution.reverse(1234) << '\n';
    cout << solution.reverse(-1234) << '\n';
    cout << solution.reverse(1534236469) << '\n';
    system("pause");
    return 0;
}
