#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void display(const vector<int> &v) {
    for(auto p : v)
        cout << p << " ";
    cout << endl;
}

int main() {
    int n,temp;
    vector<int> v;
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> temp;
        v.push_back(temp);
        push_heap(v.begin(),v.end());
        display(v);
        if(i>=3){
            for(int j=0; j<3; ++j){
                cout << v[0] << " ";
                pop_heap(v.begin(),v.end()-j);
            }
            for(int j=2; j>=0; --j)
                push_heap(v.begin(),v.end() - j);
        }
        else
            cout << "-1";
        cout << endl;

    }
    return 0;
}

