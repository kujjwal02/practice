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

void print(vector<vector<int>>& matrix) {
    for (auto& v : matrix) {
        for (auto e : v)
            cout << e << '\t';
        cout << '\n';
    }
    cout << '\n';
}

class Solution {
public:
    

    int matrixProduct(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        const int n = matrix.size();
        const int m = matrix[0].size();
        vector<vector<int>> min_cache(n, vector<int>(m));
        vector<vector<int>> max_cache(n, vector<int>(m));

        min_cache[0][0] = max_cache[0][0] = matrix[0][0];

        for(auto i = 1; i < n; ++i) {
            min_cache[i][0] = min_cache[i - 1][0] * matrix[i][0];
            max_cache[i][0] = max_cache[i - 1][0] * matrix[i][0];
        }
        for (auto i = 1; i < m; ++i) {
            min_cache[0][i] = min_cache[0][i - 1] * matrix[0][i];
            max_cache[0][i] = max_cache[0][i - 1] * matrix[0][i];
        }

        for(auto i=1; i<n; ++i) {
            for(auto j=1; j<m; ++j) {
                max_cache[i][j] = max(matrix[i][j] * max_cache[i][j - 1], matrix[i][j] * min_cache[i][j - 1]);
                max_cache[i][j] = max(max_cache[i][j], matrix[i][j] * min_cache[i - 1][j]);
                max_cache[i][j] = max(max_cache[i][j], matrix[i][j] * max_cache[i-1][j]);

                min_cache[i][j] = min(matrix[i][j] * max_cache[i][j - 1], matrix[i][j] * min_cache[i][j - 1]);
                min_cache[i][j] = min(min_cache[i][j], matrix[i][j] * min_cache[i - 1][j]);
                min_cache[i][j] = min(min_cache[i][j], matrix[i][j] * max_cache[i - 1][j]);
            }
        }

        print(min_cache);
        print(max_cache);


        return max_cache[n-1][m-1];
        
    }
};




int main() {
    Solution solution;
    vector<vector<int>> matrix{
        {-1,2,3},
        {4,5,-6},
        {7,8,9}
    };
    cout << solution.matrixProduct(matrix) << '\n';
    system("pause");
    return 0;
}
