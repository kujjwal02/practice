#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    //int speed[10000];
    while(T--){
        int n,prev,curr;
        int count = 1;
        scanf("%d",&n);
        scanf("%d",&prev);
        for(int i=1; i<n; ++i,prev=curr){
            scanf("%d",&curr);
            if(curr > prev)
                curr = prev;
            else
                ++count;
        }
        printf("%d\n",count);
    }
    return 0;
}
