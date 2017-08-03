#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

ll base = 100000;

class Item {
public:
    ll raw;
    ll num;
    ll chunk;


};

bool operator<(const Item& a, const Item& b){
        return a.chunk < b.chunk;
}
/*
ll get_chunk(const ll &num){
    ll last_place = pow(10,5*chunk_index);
    ll first_place = pow(10,5*chunk_index-5);
    return ((num%last_place)/first_place);
}

bool chunk_compare(const ll &a,const ll &b){
   return (get_chunk(a) < get_chunk(b));
}
*/
void print_and_update(vector<Item> &v){
    for(auto &e : v){
        cout << e.raw << " ";
        e.num = e.num/base;
        e.chunk = e.num%base;
    }
    cout << "\n";
}

void chunk_sort(vector<Item> &v, ll max_num){
    //cout << "max_num: " <<max_num <<endl;
    while(max_num%base){
        //cout << "index: " << chunk_index<<endl;
        //cout << "get_chunk(max_num): " << get_chunk(max_num) << endl;
        stable_sort(v.begin(),v.end());
        print_and_update(v);
        max_num/=base;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll max_num = LONG_MIN;
    cin >> n;
    vector<Item> v(n);
    for(auto &e : v){
        cin >> e.raw;
        max_num = max(max_num,e.raw);
        e.num = e.raw;
        e.chunk = e.raw%base;
    }
    chunk_sort(v,max_num);
    return 0;
}
