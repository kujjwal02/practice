#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        for(int i=n%25; i>=0&&n%25!=0; --i)
            cout << (char)('a' + i%26);
        for(int i=0; i<n/25;  ++i)
            cout << "zyxwvutsrqponmlkjihgfedcba";
        cout << endl;
    }
    return 0;
}
