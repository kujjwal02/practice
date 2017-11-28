#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        vector<string> cycle(numRows, string());

        auto step = 1;
        auto index = 0;
        for(auto c: s) {
            cycle[index].push_back(c);
            
            if (index == 0)
                step = 1;
            if (index == numRows - 1)
                step = -1;

            index += step;
        }

        string result{};
        for(auto& row: cycle) {
            result.append(row);
        }

        return result;
    }
};



int main() {
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3) << '\n';
    cout << solution.convert("PAYPALISHIRING", 4) << '\n';
    cout << solution.convert("PAYPALISHIRING", 5) << '\n';
    cout << solution.convert("PAYPALISHIRING", 6) << '\n';
    cout << solution.convert("PAYPALISHIRING", 9) << '\n';
    cout << solution.convert("AB", 1) << '\n';
    system("pause");
    return 0;
}
