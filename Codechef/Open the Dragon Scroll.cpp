#include <iostream>
#include <string>
#include <vector>

using namespace std;

int no_of_1s(int a){
    int result = 0;
    while(a){
        if(a%2)
            ++result;
        a/=2;
    }
    return result;
}

int todecimal(vector<bool> &v){
    int result = 0;
    for(auto val : v)
        result = 2*result + val;
    return result;
}

int main()
{
    int T;
    cin >> T;
    while(T--){
        int n,a,b;
        cin >> n >> a >> b;
        vector<bool> newNum(n,false);
        int total_1 = no_of_1s(a) + no_of_1s(b);

        for(int i=0; i<n&&total_1>0; ++i,--total_1)
            newNum[i] = true;

        for(int i=n-1; i>=0&&total_1>0; --i,--total_1)
            newNum[i] = false;

        cout << todecimal(newNum) << endl;
    }
    return 0;
}
