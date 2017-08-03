#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;

int greater_than(vector<int> &v,int elem){
    return  v.end() - upper_bound(v.begin(),v.end(),elem);
}

int not_less_than(vector<int> &v,int elem){
    return  v.end() - lower_bound(v.begin(),v.end(),elem);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >>n;
    vector<int> v(n);
    for(auto& e : v)
        cin >> e;
    sort(v.begin(),v.end());
    int q;
    cin >>q;
    for(int i=0; i<q; ++i){
        int op,elem;
        cin >> op;
        cin >> elem;
        int result = op ? greater_than(v,elem) : not_less_than(v,elem);
        cout << result << endl;
    }
    return 0;
}
