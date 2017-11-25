#include <iostream>
#include <vector>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<deque<char>> cycle(numRows, deque<char>());

        auto change = 1;
        auto index = 0;
        for(auto c: s) {
            cycle[index].push_back(c);
            index += change;
            if(index == numRows) {
                index -= 2;
                change = -1;
            }
            if(index == -1) {
                index += 2;
                change = 1;
            }
        }

        string result{};
        for(auto& queue: cycle) {
            result.append(queue.begin(), queue.end());
        }

        return result;
    }
};



int main() {
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3) << '\n';
    cout << solution.convert("PAYPALISHIRING", 9) << '\n';
    system("pause");
    return 0;
}
