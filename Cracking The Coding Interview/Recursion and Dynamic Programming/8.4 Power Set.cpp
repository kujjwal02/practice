//Write a method to return all subsets of a set

#include <iostream>
#include <string>
#include <vector>


using namespace std;

static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> getSubset(vector<int>& set) {
        vector<vector<int>> allsubsets;
        allsubsets.reserve(2 << set.size());
        getSubsetHelper(set, set.size() - 1, allsubsets);
        return allsubsets;
    }

    void getSubsetHelper(vector<int>& set, int index,vector<vector<int>>& allsubsets) {
        if (index == -1)
            allsubsets.push_back(vector<int>());
        else {
            getSubsetHelper(set, index - 1, allsubsets);
            int n = allsubsets.size();
            for(int i=0; i < n; ++i) {
                vector<int> temp(allsubsets[i].begin(), allsubsets[i].end());
                temp.push_back(set[index]);
                allsubsets.push_back(temp);
            }
        }
    }
};




int main() {
    Solution solution;
    vector<int> test{ 1,2,3 };
    auto result = solution.getSubset(test);
    for(auto& v: result) {
        for (auto& e : v)
            cout << e << '\t';
        cout << '\n';
    }
    system("pause");
    return 0;
}
