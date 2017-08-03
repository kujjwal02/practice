#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double quadraticRoot(int sign,int p, int s){
    return (double)(p + sign*sqrt(p*p - 24*s))/12;
}

double maxVolume(double a1, double a2,int p){
    return max((a1*a1*(p/4 - 2*a1)), (a2*a2*(p/4 - 2*a2)));
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        int p,s;
        cin >>p >>s;
        double a1 = quadraticRoot(-1,p,s);
        double a2 = quadraticRoot(1,p,s);
        //cout << a1 << a2 <<endl;
        cout<< fixed<<setprecision(2) << maxVolume(a1,a2,p) << endl;
    }
    return 0;
}
