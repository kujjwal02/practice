#include <iostream>
#include <set>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--){
        int n;
        set<int> unique_elements;
        cin >> n;
        for(int i=0; i<n; ++i){
            int curr_value;
            cin >> curr_value;
            unique_elements.insert(curr_value);
        }
        cout << unique_elements.size()<<endl;
    }
    return 0;
}
