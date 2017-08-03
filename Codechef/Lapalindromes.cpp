#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool isLapalindrome(char s[]){
    int len = strlen(s);
    int pos2 = len%2 ? len/2 +1: len/2 ;
    sort(s,s+ len/2);
    sort(s+ pos2,s+len);
    //cout << s <<endl;
    for(int i=0,j=pos2; i<len/2; ++i,++j){
        if(s[i] != s[j])
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        char s[1001];
        cin >> s;
        cout << (isLapalindrome(s) ? "YES": "NO") << endl;
    }
    return 0;
}
