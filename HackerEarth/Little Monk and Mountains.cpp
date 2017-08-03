#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;

class mountain_range{
public:
    ll lower;
    ll upper;
    ll mountains_so_far;

    mountain_range() : mountains_so_far(0){}
    /*
    bool operator<(const mountain_range &m){
        //cout<< " first: " << this->upper << " second: " << m.lower << " diff(s - f): " << m.lower-this->upper <<endl;
        return this->upper < m.lower;
    }

    bool operator==(const ll num){
        return this->lower<=num && num<=this->upper;
    }
    */
};

bool operator<(const mountain_range &m,const ll num){

        return m.mountains_so_far < num;
    }

bool operator==(const mountain_range& m ,const ll num) {
        return m.lower<=num && num<=m.upper;
    }

void print(mountain_range &m){
    cout << m.lower<< "\t" << m.upper << "\t" << m.mountains_so_far <<endl;
}

bool cmp(const mountain_range& m,const ll x){
    return (m.upper < x);
}

mountain_range find_range(const vector<mountain_range> &v,const ll x){
    int first = 0;
    int last = v.size()-1;
    int mid = (first + last)/2;
    while(first<last){
        if(v[mid] == x)
            return v[mid];
        if(v[mid] < x)
            first = mid+1;
        else
            last = mid;
        mid = (first + last)/2;
    }
    return v[first];
}

ll mountain_count(vector<mountain_range> &v,ll x){
    mountain_range m = *lower_bound(v.begin(),v.end(),x);
    //ll last = min(x,m.upper);
    print(m);
    cout << "x - lower: " << x - m.lower << " upper - x: "<< m.upper-x<<endl;
    ll count = m.mountains_so_far;
    count += x>=m.lower ? (x - m.lower + 1) : 0;
    return count;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin >>n >> q;
    vector<mountain_range> v(n);
    ll mountains_so_far = 0;
    for(auto &m : v){
        cin >> m.lower >> m.upper;
        m.mountains_so_far = mountains_so_far;
        mountains_so_far += m.upper - m.lower + 1;
        if(mountains_so_far < 0)
            cout << mountains_so_far<<endl;
    }

    while(q--){
        ll x;
        cin >> x;
        cout << mountain_count(v,x)<<endl;
    }
    return 0;
}
