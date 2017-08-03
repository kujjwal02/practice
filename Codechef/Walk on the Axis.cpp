#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        long long lights;
        cin >> lights;
        cout << (lights*(lights + 3))/2 << endl;
    }
    return 0;
}
