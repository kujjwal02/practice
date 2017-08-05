#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <array>
#include <functional>
#include <unordered_set>

using namespace std;

using ll = long long;

ll dfs(vector<vector<ll>>& graph, vector<bool>& visited, size_t pos, ll count) {
    visited[pos] = true;
    ++count;
    for (auto& e : graph[pos])
        if (!visited[e])
            count = dfs(graph, visited, e, count);
    return count;
}

ll solve(vector<vector<ll>>& graph) {
    ll total = 0;
    vector<bool> visited(graph.size(), false);
    ll sum = 0;
    for (size_t i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            ll count = dfs(graph, visited, i, 0);
            total += sum * count;
            sum += count;
        }
    }

    return total;
}


int main() {
    ll n, p;
    cin >> n >> p;
    vector<vector<ll>> graph(n, vector<ll>());
    for (auto i = 0; i < p; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout << solve(graph) << endl;
    system("pause");
    return 0;
}
