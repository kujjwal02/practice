#include <iostream>

using namespace std;

bool primes[2004];

void initprimes(){
    for(int i=0;i<2004; ++i)
        primes[i] = true;

    primes[0] = primes[1] = false;
    for(int i=2; i*i<=2004; ++i){
        if(primes[i])
            for(int j=i*i; j<=2004; j+=i)
                primes[j]=false;
    }
}

int main()
{
    initprimes();
    int cases;
    cin >> cases;
    while(cases--){
        int x,y,sum;
        cin >>x >> y;
        sum = x+y+1;
        while(!primes[sum])
            ++sum;
        cout << sum-x-y<< endl;
    }
    return 0;
}
