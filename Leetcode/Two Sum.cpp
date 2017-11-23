#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> visited;
    for (auto i = 0; i < nums.size(); ++i) {
        if (visited.find(nums[i]) != visited.end())
            return vector<int>{visited[nums[i]], i};
        visited[target - nums[i]] = i;
    }
    throw exception("No two sum solution");
}

int main() {
    vector<int> seq{ 3, 2, 4 };
    for (auto num : twoSum(seq, 6))
        cout << num << '\n';
    system("pause");
    return 0;
}
