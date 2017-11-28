#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        if (nums.size() < 3)
            return result;

        sort(nums.begin(), nums.end());

        for(auto i{0}; i<nums.size()-2; ++i) {
            if(nums[i]>0 || ( i > 0 && nums[i] == nums[i-1]))
                continue;

            for(auto j{i+1}; j<nums.size()-1; ++j) {
                if (nums[i] + nums[j] > 0)
                    break;

                auto c{ -nums[i] - nums[j] };

                auto pos = lower_bound(nums.begin() + j + 1, nums.end(), c);
                if(pos != nums.end() && *pos == c)
                    result.push_back(vector<int>{nums[i], nums[j], c});
                
                while (j < nums.size() - 1 && nums[j] == nums[j + 1])
                    ++j;
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> test1{ -1, 0, 1, 2, -1, -4 };
    vector<int> test2{ 0, 0, 0, 0};
    auto answer{ solution.threeSum(test2) };
    for(auto& v: answer) {
        for (auto e : v)
            cout << e << '\t';
        cout << '\n';
    }
    system("pause");
    return 0;
}
