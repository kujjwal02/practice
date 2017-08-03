#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        long long n,temp;
        cin >> n;
        //int num[100000];
        for(int i=0;i<n; ++i)
            cin >> temp;
        /*
        int count = 0;
        for(int i=0; i<n; ++i)
            for(int j=i+1; j<n; ++j)
                if()
        */
        cout << (n*(n-1))/2<< endl;
    }
    return 0;
}
