#include <iostream>
#include <string>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        string num;
        cin >> num;
        long long count=0;
        for(int i=0; i<num.size(); ++i)
            if(num[i]!= '4'  &&  num[i]!='7')
                ++count;

        cout << count << endl;
    }
    return 0;
}
