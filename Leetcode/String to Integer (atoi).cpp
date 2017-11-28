#include <iostream>
#include <string>

using namespace std;

static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;

        int index = 0;
        while (index < str.size() && isspace(static_cast<int>(str[index])))
            ++index;

        int sign = 1;
        if (!isdigit(static_cast<int>(str[index]))) {
            switch (str[index]) {
            case '+':
                break;
            case '-':
                sign = -1;
                break;
            default:
                return 0;
            }
            ++index;
        }

        int result = 0;
        while (index < str.size() && isdigit(static_cast<int>(str[index]))) {
            int num = str[index++] - static_cast<int>('0');
            result = result * 10 + num;
            if (result%10 != num)
                return (sign > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min());
        }

        result = sign * result;


        return static_cast<int>(result);
    }
};


int main() {
    Solution solution;
    cout << solution.myAtoi("    10522545459") << '\n';
    cout << solution.myAtoi("-") << '\n';
    cout << solution.myAtoi("+") << '\n';
    cout << solution.myAtoi("-123456") << '\n';
    cout << solution.myAtoi("457863") << '\n';
    cout << solution.myAtoi("0.456") << '\n';
    cout << solution.myAtoi("-0.456") << '\n';
    cout << solution.myAtoi("123.456") << '\n';
    cout << solution.myAtoi("-123.456") << '\n';
    cout << solution.myAtoi("-+2") << '\n';
    cout << solution.myAtoi("2147483648") << '\n';
    cout << solution.myAtoi("9223372036854775809") << '\n';
    system("pause");
    return 0;
}
