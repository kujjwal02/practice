#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>


using namespace std;
using ll = long long;

struct Point {
    ll x, y;
    Point(): x(0), y(0) {}
    Point(ll x, ll y): x(x), y(y) {}
};

vector<Point> get_valid_moves(vector<vector<char>> &matrix, Point curr) {
    ll rows = matrix.size();
    ll cols = matrix[curr.x].size();
    vector<Point> v;
    v.reserve(4);

    if (curr.x + 1 < rows && matrix[curr.x + 1][curr.y] != 'X')
        v.push_back(Point(curr.x + 1, curr.y));

    if (curr.x - 1 >= 0 && matrix[curr.x - 1][curr.y] != 'X')
        v.push_back(Point(curr.x - 1, curr.y));

    if (curr.y + 1 < cols && matrix[curr.x][curr.y + 1] != 'X')
        v.push_back(Point(curr.x, curr.y + 1));

    if (curr.y - 1 >= 0 && matrix[curr.x][curr.y - 1] != 'X')
        v.push_back(Point(curr.x, curr.y - 1));

    return v;
}

Point pop(queue<Point> &q) {
    auto p = q.front();
    q.pop();
    return p;
}

ll predicted(vector<vector<char>> &matrix, Point &start, ll count) {
    if (matrix[start.x][start.y] == '*')
        return count;
    matrix[start.x][start.y] = 'X';
    auto moves = get_valid_moves(matrix, start);
    if (moves.size() == 0)
        return -1;
    if (moves.size() > 1)
        ++count;
    for (auto& p : moves) {
        auto guess = predicted(matrix, p, count);
        if (guess != -1)
            return guess;
    }
    return -1;
}


int main() {
    ll queries;
    cin >> queries;
    while (queries--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<char>> forest(n, vector<char>(m));
        Point start;
        for(ll i=0; i<n;++i) {
            for(ll j=0; j<m; ++j) {
                cin >> forest[i][j];
                if (forest[i][j] == 'M')
                    start = Point(i, j);
            }
        }
        ll k; cin >> k;
        cout << (predicted(forest, start, 0) == k ? "Impressed" : "Oops!") << '\n';
    }
    system("pause");
    return 0;
}
