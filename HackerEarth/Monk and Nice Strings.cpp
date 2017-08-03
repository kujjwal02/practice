#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

void printset(const multiset<string,greater<string>> &s){
    cout << "\t";
    for(auto &str : s)
        cout << str << " ";
    cout << endl;
}

void printNiceStringsNumber(const vector<string> &v){
    multiset<string,greater<string>> saved;
    int i=1;
    for(auto &s : v){
        cout << i++ << ": ";
        cout << "check for:" << s << " setsize: "<< saved.size()<< endl;
        printset(saved);
        auto saved_str = saved.begin();
        int set_size = saved.size();
        while(set_size && !(s > *saved_str)){
            set_size--;
            saved_str++;
        }
        cout<< "\t" << set_size << endl;
        saved.insert(s);
    }
}

int main()
{
    int n;
    cin >>n;
    vector<string> v(n);
    for(auto &s : v)
        cin >> s;
    printNiceStringsNumber(v);
    return 0;
}
