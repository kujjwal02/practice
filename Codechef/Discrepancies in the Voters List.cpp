#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    map<int,int> votes;
    int n1,n2,n3;
    cin >>n1 >> n2 >> n3;
    for(int i=0,key; i<n1; ++i){
        cin >> key;
        votes[key] = 0;
    }
    for(int i=0,key; i<n2; ++i){
        cin >> key;
        if(votes.find(key) == votes.end())
            votes[key] = 0;
        else
            ++votes[key];
    }
    for(int i=0,key; i<n3; ++i){
        cin >> key;
        if(votes.find(key) == votes.end())
            votes[key] = 0;
        else
            ++votes[key];
    }
    /*
    for(auto p: votes){
        cout << p.first << " " << p.second << endl;
    }
    */
    cout << count_if(votes.begin(), votes.end(), [](pair<int,int> p){return p.second > 0;}) << endl;
    for(auto p: votes){
        if(p.second > 0)
            cout << p.first << endl;
    }
    return 0;
}
