#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>

using namespace std;

using ll = long long;

struct Point {
    ll x,y;
    Point(ll x, ll y): x(x), y(y) {}
};

vector<Point> get_valid_points( ll x, ll y, ll rows, ll cols) {
    vector<Point> v;
    v.reserve(8);
    if(x + 1 < rows) {
        v.push_back(Point(x+1,y));
        if(y + 1 < cols){
            v.push_back(Point(x+1,y+1));
            v.push_back(Point(x, y+1));
        }
        if(y -1 >=0){
            v.push_back(Point(x+1, y-1));
            v.push_back(Point(x, y-1));
        }
    }

    if(x -1 >= 0) {
        v.push_back(Point(x-1, y));

        if(y-1 >= 0)
            v.push_back(Point(x-1, y-1));

        if(y + 1 < cols)
            v.push_back(Point(x-1, y+1));
    }

    return v;
}

ll island_count(vector<vector<ll>> &matrix, ll x, ll y){
    ll count = 1;
    matrix[x][y] = 0;
    ll rows = matrix.size();
    ll cols = matrix[x].size();
    for(auto& p : get_valid_points(x, y, rows, cols)) {
        if(matrix[p.x][p.y]) {
            count += island_count(matrix, p.x, p.y);
        }
    }
    return count;
}

ll biggest_island_size(vector<vector<ll>> &matrix) {
    ll max_count = 0;
    for(ll i=0; i<matrix.size(); ++i) {
        for(ll j=0; j<matrix[i].size(); ++j) {
            if(matrix[i][j]) {
                auto count = island_count(matrix, i, j);
                max_count = max(max_count, count);
            }
        }
    }
    return max_count;
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> globe(n, vector<ll>(m));
    for(auto& row: globe)
        for(auto& e : row)
            cin >> e;
    cout << biggest_island_size(globe) << '\n';
    return 0;
}