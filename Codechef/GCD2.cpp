#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

using namespace std;

int remainder(string a,int b){
    int rem=a[0] - '0';
    for(int i=0;(i+1)<a.size();){
        while((i+1)<a.size() && rem < b){
            int next = a[++i] - '0';
            rem = 10*rem +next;
        }
        rem%=b;
    }
    return rem;
}

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int gcdstr(string a,int b){
    if(b==0)
        cout << a;
    else
        return gcd(b,remainder(a,b));
    cout << endl;
}


void gcds(string a,int b){
    if(b==0)
        cout << a;
    else
        cout << gcd(b,remainder(a,b));
    cout << endl;
}

int main()
{
    /* stress test
    while(true){
        int a = rand()%1000000,
            b = rand()%1000000 + 1;
        cout << a<<"\t" << b<<endl;
        int intgcd = gcd(a,b);
        int stringgcd = gcdstr(patch::to_string(a),b);
        if( intgcd!= stringgcd){
            cout << intgcd << stringgcd <<endl;
            break;
        }
        else
            cout<<"ok"<<endl;
    }
    */
    int t;
    cin >> t;
    while(t--){
        int b;
        string a;
        cin >> b >> a;
        gcds(a,b);
    }
    return 0;
}
