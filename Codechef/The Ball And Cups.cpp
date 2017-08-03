#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int n,c,q;
        cin >> n >> c >> q;
        while(q--){
            int l,r;
            cin >> l >> r;
            if(l<=c && c<=r)
                c = r+l-c;
        }
        cout << c << endl;
    }
    return 0;
}
