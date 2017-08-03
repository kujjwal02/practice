#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;

stack<int> first_row_min;

void operation1(vector<vector<int>> &v,int k){
    v[k-1].pop_back();
    if(k==1)
        first_row_min.pop();
}

void operation2(vector<vector<int>> &v,int k,int h){
    if(k==1)
        first_row_min.push(min(first_row_min.top(),h));
    v[k-1].push_back(h);
}

string operation3(vector<vector<int>> &v){
    int min = first_row_min.top();
    for(int i=1; i<v.size(); ++i){
        auto upp = upper_bound(v[i].begin(),v[i].end(),min);
        if(upp == v[i].end())
            return "NO";
        min = *upp;
        /*
        bool found_new_min = false;
        for(auto e : v[i]){
            if(min < e){
                min = e;
                found_new_min = true;
                break;
            }
        }
        if(!found_new_min) return "NO";
        */
    }
    return "YES";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> v(n);

    first_row_min.push(INT_MAX);
    int s;
    cin >> s;
    vector<int> row(s);
    for(auto& e : row){
            cin >> e;
            first_row_min.push(min(first_row_min.top(),e));
    }
    v[0] = row;
    row.clear();
    for(int i=1; i<n; ++i){
        cin >> s;
        row.resize(s);
        for(auto& e : row){
            cin >> e;
        }
        v[i] = row;
    }

    int queries;
    cin >> queries;
    while(queries--){
        int op,k,h;
        cin >> op;
        switch(op){
        case 0 :
            cin >> k;
            operation1(v,k);
            break;

        case 1 :
            cin >> k >> h;
            operation2(v,k,h);
            break;

        case 2 :
            cout <<  operation3(v) << endl;
        }
    }
    return 0;
}
