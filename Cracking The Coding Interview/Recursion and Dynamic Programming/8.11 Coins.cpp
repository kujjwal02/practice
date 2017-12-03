/*
Coins: 
    Given an infinite number of quarters (25 cents), dimes (10 cents), 
    nickels (5 cents), and pennies (1 cent), 
    write code to calculate the number of ways of representing n cents.
*/

#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;

using ll = long long;

static int some = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ll makeChange(ll n) {
        unordered_map<ll, ll> history;
        return makeChangeHelper(n, history);
    }

    ll makeChangeHelper(ll n, unordered_map<ll, ll>& history) {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        if (history.find(n) != history.end())
            return history[n];

        return makeChangeHelper(n - 25, history) + 
            makeChangeHelper(n - 10, history) + 
            makeChangeHelper(n - 5, history) + 
            makeChangeHelper(n - 1, history);
    }
};




int main() {
    Solution solution;
    cout << solution.makeChange(5) << '\n';
    cout << solution.makeChange(9) << '\n';
    cout << solution.makeChange(10) << '\n';
    cout << solution.makeChange(20) << '\n';
    system("pause");
    return 0;
}
