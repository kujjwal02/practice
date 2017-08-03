#include <iostream>

using namespace std;
/*
long long gcd(long long a, long long b){
    if(b == 0)
        return a;
    return gcd(b,a%b);
}
*/
long long gcd(long long a, long long b){
    long long temp;
    while(b != 0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}


int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        long long prev,curr;
        cin >> n;
        cin >> prev;
        for(int i=1; i<n; ++i){
            cin >> curr;
            prev = gcd(prev,curr);
        }
        cout << prev<<endl;
    }
    return 0;
}
