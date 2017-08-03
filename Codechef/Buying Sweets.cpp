#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n,x;
        cin >>n >> x;
        int sum =0;
        int notes[100];
        for(int i=0; i<n; ++i){
            cin >> notes[i];
            sum += notes[i];
        }

        int possible = sum/x;
        for(int i=0; i<n; ++i){
            if((sum-notes[i])/x == possible){
                possible = -1;
                break;
            }
        }

        cout << possible << endl;
    }
    return 0;
}
