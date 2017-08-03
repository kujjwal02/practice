#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        double l,d,s,c;
        cin >>l>>d>>s>>c;
        bool canLive = ( (d-1)*log(1+c) >= log(l/s) );
        cout << (canLive ? "ALIVE AND KICKING" : "DEAD AND ROTTING") << endl;
    }
    return 0;
}
