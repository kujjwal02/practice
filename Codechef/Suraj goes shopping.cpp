#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int tests;
    cin >> tests;
    while(tests--){
        int n;
        int items[1000];
        cin >> n;
        for(int i=0; i<n; ++i)
            cin >> items[i];

        sort(items,items+n);

        int sum = 0;
        for(int i=n-1,count=0; i>=0; --i){
            if(count%4==0 || count%4==1)
                sum+= items[i];
            ++count;
        }
        cout << sum<< endl;
    }
    return 0;
}
