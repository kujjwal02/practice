#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for(int i=0; i<n; ++i){
        int curr_stamp;
        cin >> curr_stamp;
        sum += curr_stamp;
    }
    int stamp_after_redistribution = (n*(n+1))/2;
    cout << (stamp_after_redistribution==sum ? "YES": "NO");
    return 0;
}
