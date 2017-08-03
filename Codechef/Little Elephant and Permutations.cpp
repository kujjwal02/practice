#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    cin >> T;
    int A[100];
    while(T--){
        int n;
        cin >> n;
        for(int i=0; i<n; ++i)
            scanf("%d",&A[i]);
        int inversion =0,
            local_inversion = 0;

        for(int i=0; i<(n-1); ++i)
            for(int j=i+1; j<n; ++j){
                if(A[i]> A[j]){
                    ++inversion;
                    if(i+1 == j)
                        ++local_inversion;
                }
            }

        cout << (inversion == local_inversion ? "YES": "NO") << endl;
    }
    return 0;
}
