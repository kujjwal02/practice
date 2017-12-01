#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int pivot = pivot_index(nums);

        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int real_mid = (mid + pivot) % nums.size();
            if (nums[real_mid] == target)
                return real_mid;
            if (nums[real_mid] > target)
                high = mid - 1;
            else
                low = mid+ 1;
        }

        return -1;
    }

    int pivot_index(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low < high) {
            auto mid = (low + high) / 2;
            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};
static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


int main() {
    Solution solution;
//  vector<int> test{ 4,5,6,7,0,1,2 };
    vector<int> test{ 1,3 };
    cout << solution.search(test, 1) << '\n';
    cout << solution.search(test, 3) << '\n';
    cout << solution.search(test, 2) << '\n';
    cout << solution.search(test, 10) << '\n';
    system("pause");
    return 0;
}
