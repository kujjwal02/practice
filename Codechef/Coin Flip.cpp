#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int T;
    cin >>T;
    while(T--){
        int g;
        cin >> g;
        while(g--){
            ll i,n,q;
            cin >>i >> n >> q;
            ll head,tail;
            head = tail = n/2;
            if(n%2){
                if(i==1)
                    ++tail;
                else
                    ++head;
            }

            cout << (q==1 ? head : tail) << endl;
        }
    }

    return 0;
}
