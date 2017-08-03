#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cin >>a >> b;
    int diff = a-b;
    int y= diff%10;
    //cout<< diff << "\n";
    cout << (diff/10)*10 + (y==5?6:5);
    return 0;
}
