#include <iostream>
#include <cstdio>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

using ll = long long;

struct Point {
    ll x;
    ll y;
    ll t;
    Point(ll x, ll y, ll t) : x(x), y(y), t(t) {}
};

vector<Point> get_valid_points(Point curr, ll n, ll a, ll b) {
    vector<Point> v;
    if (curr.x + a < n) {
        if (curr.y + b < n)
            v.push_back(Point(curr.x + a, curr.y + b, curr.t + 1));

        if (curr.y - b >= 0)
            v.push_back(Point(curr.x + a, curr.y - b, curr.t + 1));

    }

    if (curr.x - a >= 0) {
        if (curr.y + b < n)
            v.push_back(Point(curr.x - a, curr.y + b, curr.t + 1));

        if (curr.y - b >= 0)
            v.push_back(Point(curr.x - a, curr.y - b, curr.t + 1));

    }

    if (curr.x + b < n) {
        if (curr.y + a < n)
            v.push_back(Point(curr.x + b, curr.y + a, curr.t + 1));

        if (curr.y - a >= 0)
            v.push_back(Point(curr.x + b, curr.y - a, curr.t + 1));

    }

    if (curr.x - b >= 0) {
        if (curr.y + a < n)
            v.push_back(Point(curr.x - b, curr.y + a, curr.t + 1));

        if (curr.y - a >= 0)
            v.push_back(Point(curr.x - b, curr.y - a, curr.t + 1));

    }
    return v;

}

Point pop(queue<Point>& q) {
    auto p = q.front();
    q.pop();
    return p;
}

ll min_path_count(ll n, ll a, ll b) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<Point> q;
    q.push(Point(0, 0, 0));
    visited[0][0] = true;
    while (!q.empty()) {
        for (auto p : get_valid_points(pop(q), n, a, b)) {
            if (!visited[p.x][p.y]) {
                visited[p.x][p.y] = true;
                if ((p.x == (n - 1)) && (p.y == (n - 1)))
                    return p.t;
                q.push(p);
            }
        }
    }
    return -1;
}

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> matrix(n-1, vector<ll>(n-1));
    for (ll i = 0; i < matrix.size(); ++i) {
        for (ll j = 0; j < matrix.size(); ++j)
            if (i <= j)
                matrix[i][j] = min_path_count(n, i + 1, j + 1);
            else
                matrix[i][j] = matrix[j][i];
    }

    for(auto row : matrix) {
        for (auto c : row)
            cout << c << ' ';
        cout << '\n';
    }
    system("pause");
    return 0;
}
