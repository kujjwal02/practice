#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    map<int,int> reverse_index_map;
    cin >> n;
    int temp;
    for(int  i=1; i<=n; ++i){
        cin >> temp;
        reverse_index_map[temp] = i;
    }
    for(int i=1; i<=n; ++i)
        cout << reverse_index_map[reverse_index_map[i]] << endl;
    return 0;
}
