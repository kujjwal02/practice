#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>


using namespace std;

using ll = long long;

static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        if (lower == nums.end())
            return vector<int>{-1, -1};
        if (*lower != target)
            return vector<int>{-1, -1};

        auto upper = upper_bound(nums.begin(), nums.end(), target);
        return vector<int>{lower - nums.begin(), upper - nums.begin() - 1};
    }
};




int main() {
    Solution solution;
    vector<int> test{ 5, 7, 7, 8, 8, 10 };
    for (auto e : solution.searchRange(test, 8)) {
        cout << e << '\t';
    }
    system("pause");
    return 0;
}