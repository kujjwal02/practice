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
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        auto start = upper_bound(nums.begin(), nums.end(), 0);
        if (start == nums.end() || *start > 1)
            return 1;
        
        int index = start - nums.begin();

        for(++index; index < nums.size(); ++index) {
            if (nums[index] - nums[index - 1] > 1)
                return nums[index - 1] + 1;
        }

        return nums.back() + 1;
    }
};


int main() {
    Solution solution;
    vector<int> test{ 3,4,-1,1 };
    cout << solution.firstMissingPositive(test) << '\n';
    system("pause");
    return 0;
}