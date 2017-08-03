#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        map<int,int> frequency;
        for(int i=0; i<n; ++i) {
            int index;
            cin >> index;
            frequency[index]++;
        }
        int smallest = (*frequency.begin()).second;
        cout << (smallest%2 ? "Lucky\n" : "Unlucky\n") ;
    }
}
