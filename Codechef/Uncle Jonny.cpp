#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

typedef long long ll;

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int music[n];
        for(int i=0; i<n; ++i)
            cin >> music[i];
        int k;
        cin >> k;
        k = music[k-1];

        sort(music,music+n);
        int pos;
        for(pos=0;pos<n; ++pos){
            if(music[pos] == k)
                break;
        }

        cout << pos+1 << endl;
    }
    return 0;
}
