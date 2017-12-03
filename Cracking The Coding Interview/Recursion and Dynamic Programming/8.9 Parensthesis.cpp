/*
Parenthesis:
    Implement an algorithm to print all valid (e.g., properly opened and closed) 
    combinations of n pairs of parentheses.
    EXAMPLE 
        Input: 3 
        Output: ( ( () ) ) , 
                ( () () ) ,
                ( () ) () , 
                () ( () ) , 
                () () ()
*/

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
    vector<string> generateParams(int n) {
        vector<string> results;
        generateParamsHelper("", n, 0, results);
        return results;
    }

    void generateParamsHelper(string str, int left, int right, vector<string>& result) {
        if (left == 0 && right == 0)
            result.push_back(str);
        else {
            if (right > 0)
                generateParamsHelper(str + ")", left, right - 1, result);
            if (left > 0)
                generateParamsHelper(str + "(", left - 1, right + 1, result);
        }
    }
};




int main() {
    Solution solution;
    int test = 3;
    for(auto& s : solution.generateParams(test)) {
        cout << s << '\n';
    }
    system("pause");
    return 0;
}
