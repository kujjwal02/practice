#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <array>
#include <functional>
#include <unordered_set>

using namespace std;

using ll = long long;


int main() {
    ll n, score;
    cin >> n;
    cin >> score;
    ll max_score = score;
    ll min_score = score;
    ll max_count = 0;
    ll min_count = 0;
    for (auto i = 1; i < n ; ++i) {
        cin >> score;
        if(score > max_score) {
            ++max_count;
            max_score = score;
        }
        else if(score < min_score) {
            ++min_count;
            min_score = score;
        }
    }
    cout << max_count << " " << min_count << endl;
    system("pause");
    return 0;
}
