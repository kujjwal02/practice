#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <cctype>
#include <climits>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    deque<pair<int,deque<int>>> main_queue;
    while(q--){
        char ch;
        int school,roll_no;
        cin >> ch;
        int i=0;
        switch(ch){
        case 'E':
            cin >> school >> roll_no;

            while(main_queue[i].first != school && i<main_queue.size())
                ++i;
            if(i == main_queue.size()){
                deque<int> roll_queue;
                roll_queue.push_back(roll_no);
                main_queue.push_back(make_pair(school,roll_queue));
            }
            else{
                main_queue[i].second.push_back(roll_no);
            }
            break;

        case 'D':
            cout << main_queue[0].first << " " << main_queue[0].second.front() << endl;
            if(main_queue[0].second.size() == 1)
                main_queue.pop_front();
            else
                main_queue[0].second.pop_front();
        }
    }

    return 0;
}
