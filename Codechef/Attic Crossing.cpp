#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    ll tests;
    cin >> tests;
    while(tests--){
        string passage;
        cin >> passage;
        ll  days = 0,
            max_length = 1,
            prev_pos = 0;

        for(ll i=1; i<passage.size(); ++i)
        if(passage[i] == '#'){
            if(i-prev_pos > max_length){
                max_length = i - prev_pos;
                ++days;
            }
            prev_pos = i;
        }

        cout << days << endl;
    }
    return 0;
}
