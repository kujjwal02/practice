#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        cout << (360%n==0? "y ":"n ")
            << (n<=360? "y ":"n ")
            <<((n*(n+1))/2 <= 360 ? "y ":"n ")
            << endl;
    }
    return 0;
}
