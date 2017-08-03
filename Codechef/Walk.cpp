#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    int cases;
    cin >>cases;
    while(cases--){
        ll n;
        ll weight[100000];
        cin >> n;
        for(int i=0; i<n; ++i)
            cin >> weight[i];

        ll speed = 0;
        for(int i=n-1; i>=0; --i){
            speed = max(speed+1,weight[i]);
        }

        cout << speed << endl;
    }
    return 0;
}
