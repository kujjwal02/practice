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

ll find_min_adjecent(const vector<multiset<ll>>& v) {
    ll min_adjecent = LLONG_MAX;
    for(int i=0; i<v.size()-1; ++i){
        for(const auto& e1 : v[i]){
            auto it = upper_bound(v[i+1].begin(),v[i+1].end(),e1);
            if(it != end(v[i+1]))
                min_adjecent = min(min_adjecent,abs(*it - e1));
            if(it != begin(v[i+1]))
                min_adjecent = min(min_adjecent,abs(*prev(it)- e1));
        }
    }
    return min_adjecent;
}
/*
void print(const vector<multiset<ll>>& v) {
    for(const auto& row : v) {
        for(const auto& e : row) {
            cout << e << '\t';
        }
        cout << '\n';
    }
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll rows,cols;
    cin >> rows >> cols;
    vector<multiset<ll>> matrix(rows);

    for(auto& row : matrix){
        for(int i=0; i<cols; ++i){
            ll val;
            cin >> val;
            row.insert(val);
        }
    }
    //print(matrix);
    cout << find_min_adjecent(matrix);

    return 0;
}
