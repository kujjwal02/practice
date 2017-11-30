#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;



static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        auto i = 0;
        for(auto j=1; j<nums.size(); ++j) {
            if(nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    Solution solution;
//  vector<int> test{ 1,2,2,3,3,3,4,4,5 };
    //  vector<int> test{1,1,2,};
        vector<int> test{1,2,2,3,};
    auto n = solution.removeDuplicates(test);
    cout << n << "\n\n";
    for (auto i{ 0 }; i < n; ++i)
        cout << test[i] << '\n';
    system("pause");
    return 0;
}
