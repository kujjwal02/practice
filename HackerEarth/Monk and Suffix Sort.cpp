#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

string suffix(const string &s,int k){
    map<char,set<string>> alpha;

    for(int i=0; i<s.size(); ++i)
        alpha[s[i]].insert(s.substr(i));

    for(auto &p : alpha){
        if(p.second.size() >= k){
            --k;
            auto str = p.second.begin();
            while(k--)
                ++str;
            return *str;
        }
        k-= p.second.size();
    }
    return "";
}

int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << suffix(s,k);
    return 0;
}
