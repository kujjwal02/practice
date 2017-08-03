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

    ll n;
    cin >> n;
    queue<ll> harry_bag;
    for(ll i=0; i<n; ++i){
        ll val;
        cin >> val;
        harry_bag.push(val);
    }
    ll queries,x;
    cin >> queries >> x;
    stack<ll> monk_bag;
    ll monk_money = 0;
    ll temp;
    ll result = -1;
    while(queries--){
        string q;
        cin >> q;
        if(q == "Harry"){
            temp = harry_bag.front();
            harry_bag.pop();
            monk_bag.push(temp);
            monk_money += temp;
            if(result==-1 && monk_money == x)
                result = monk_bag.size();
        }
        else{
            temp = monk_bag.top();
            monk_bag.pop();
            monk_money -= temp;
        }
    }

    cout << result;

    return 0;
}
