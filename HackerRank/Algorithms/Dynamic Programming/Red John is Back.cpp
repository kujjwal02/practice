#include <iostream>

#define LIMIT 250273

using namespace std;



bool primes[LIMIT];

void init_primes(){
    for(long long i=0; i<LIMIT; ++i)
        primes[i] = true;
    primes[0] = primes[1] = false;

    for(long long i=2; i*i<=LIMIT; ++i){
        if(primes[i])
            for(int j=i*i; j<LIMIT; j+= i)
                primes[j] = false;
    }
}

long long primes_less_than(long long n){
    long long count=0;
    for(long long i=1; i<=n; ++i)
        if(primes[i])
            ++count;
    return count;
}

long long get_no_of_combinations(int n){
    long long memo[41];

    memo[0] = 1;
    for(int b=1;b<=n; ++b){
        memo[b] = memo[b-1];
        if(b-4>=0)
            memo[b] += memo[b-4];
    }
    /*
    for(int b=0;b<=n; ++b)
        cout << memo[b]<< "\t";
    cout << endl;
    */
    return memo[n];
}

int main()
{
    init_primes();
    int tests;
    cin >> tests;
    while(tests--){
        int n;
        cin >> n;
        long long no_of_combinations = get_no_of_combinations(n);
        //cout << no_of_combinations << "\t";
        cout << primes_less_than(no_of_combinations)<<endl;
        /*
        for(long long i=no_of_combinations; i>0; --i)
            cout<< i<< "\t" << primes_less_than(i) <<endl;
        */
    }
    return 0;
}
