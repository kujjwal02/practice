#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        cin >> n;
        int width = ceil(sqrt(n));
        while(n%width != 0)
            --width;
        cout << abs(n/width - width) << endl;
    }
    return 0;
}
