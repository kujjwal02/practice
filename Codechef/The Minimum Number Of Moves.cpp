#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int tests;
    cin >> tests;
    while(tests--){
        int n;
        int salary[100];
        cin >> n;
        for(int i=0; i<n; ++i)
            cin >> salary[i];

        int count = 0;
        sort(salary,salary+n);
        while(salary[0] != salary[n-1]){
            int diff = salary[n-1]-salary[0];
            count += diff;
            for(int i=0; i<n-1; ++i)
                salary[i]+= diff;
            if(salary[n-2]>salary[n-1])
                sort(salary,salary+n);
        }

        cout << count<< endl;
    }
    return 0;
}
