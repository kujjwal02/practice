#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
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
    ll n,x;
    cin >> n >> x;
    queue<pair<ll,ll>> spider;
    for(int i=1; i<=n; ++i){
        ll val;
        cin >> val;
        spider.push(make_pair(i,val));
    }
    queue<pair<ll,ll>> removed;
    for(int i=1; i<=x; ++i){
        auto max_spider = make_pair(LONG_MIN,LONG_MIN);
        int limit = min(x,(ll)spider.size());
        for(int j=1; j<=limit; ++j){
            auto sp = spider.front();
            spider.pop();
            if(sp.second > max_spider.second){
                max_spider = sp;
            }
            removed.push(sp);
        }
        for(int j=1; j<=limit; ++j){
            auto sp = removed.front();
            removed.pop();
            if(sp.first == max_spider.first)
                continue;
            if(sp.second)
                sp.second -= 1;
            spider.push(sp);
        }
        cout << max_spider.first << " ";
    }

    return 0;
}
