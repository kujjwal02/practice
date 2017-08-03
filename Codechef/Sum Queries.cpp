#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ll n,no_of_queries;
    cin >>n >> no_of_queries;
    while(no_of_queries--){
        ll query;
        ll occurence = 0;
        cin >>query;
        if(query > n+1 && query <=3*n)
            occurence = n- abs(2*n + 1 -query);

        cout << occurence << endl;
    }
    return 0;
}
