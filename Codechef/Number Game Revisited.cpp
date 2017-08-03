#include <iostream>
#include <cmath>
#include <sstream>



using namespace std;

bool isPrime(long long n){
    if(n<1)
        return false;
    if(n<4)
        return true;
    if(n%2==0 || n%3==0)
        return false;
    for(long long i=5, limit = sqrt(n);i<limit; i+=6 )
        if(n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}

long long primeLessThan(long long n){
    for(long long i=n-1; i>0; --i){
        if(isPrime(i))
            return i;
    }

    return -1;
}

string winner(long long n){
    int player = 1;
    while(true){
        long long move = primeLessThan(n);
        cerr << move<<endl;
        if(move == -1)
            break;
        n -= move;
        player *= -1;
    }

    return player == -1 ? "BOB":"ALICE";
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        long long n;
        cin >> n;
        cout << winner(n) <<endl;
    }
    return 0;
}
