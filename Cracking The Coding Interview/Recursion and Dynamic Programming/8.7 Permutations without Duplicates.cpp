/*
Permutations without Duplicates: 
    Write a method to compute all permutations of a string of unique characters.
*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    vector<string> getPerms(string& str) {
        vector<string> result;
        getPermsHelper(str, "", result);
        return result;
    }

    void getPermsHelper(string pool, string constructed, vector<string>& result) {
        if (pool.empty())
            result.push_back(constructed);
        else {
            for(int i=0; i<pool.size(); ++i) {
                getPermsHelper(pool.substr(0, i) + pool.substr(i + 1), constructed + pool[i], result);
            }
        }
    }
};




int main() {
    Solution solution;
    string test{ "abcd" };
    for(auto& s: solution.getPerms(test)) {
        cout << s << '\n';
    }
    system("pause");
    return 0;
}
