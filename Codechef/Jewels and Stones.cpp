#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--){
        string j,s;
        int count = 0;
        cin >>j >> s;
        for(int i=0; i<s.size(); ++i){
            if(j.find(s[i]) != -1)
                count++;
        }
        cout << count<<endl;
    }
    return 0;
}
