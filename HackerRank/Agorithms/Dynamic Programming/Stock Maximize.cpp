#include <iostream>

using namespace std;

typedef long long ll;

ll max_profit(ll prices[], ll n){
    ll max_price = 0;
    ll profit = 0;
    for(ll i=n-1; i>=0; --i){
        if(max_price < prices[i])
            max_price = prices[i];
        else
            if(max_price > prices[i])
                profit += max_price - prices[i];
    }

    return profit;
}



int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        ll n;
        ll prices[50000];
        cin >> n;
        for(int i=0; i<n; ++i)
            cin >> prices[i];
        cout << max_profit(prices,n) << endl;
    }
    return 0;
}
