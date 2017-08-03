#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int rows,cols;
    cin >> rows >> cols;
    array<array<ll,cols>,rows> matrix;

    for(auto& row : matrix)
        for(auto& elem : row)
            cin >> elem;

    int v1,v2,v3,v4;
    cin >> v1 >> v2 >> v3 >> v4;

    return 0;
}
