#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> s(n);
        for(int i=0; i<n; ++i){
            cin >> s[i];
        }

        sort(s.begin(),s.end());


        int diff = INT_MAX;
        int newDiff;
        for(int i=0; i<(n - 1); ++i)
            if((newDiff = (s[i+1] - s[i])) < diff)
               diff = newDiff;

        cout << diff << endl;

    }
    return 0;
}
