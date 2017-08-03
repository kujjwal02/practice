#include <iostream>

using namespace std;

int main()
{
    long long destination;
    cin >> destination;
    long long reduced = destination%6;
    if(reduced == 0 || reduced == 1 || reduced == 3)
        cout << "yes";
    else
        cout << "no";
    return 0;
}
