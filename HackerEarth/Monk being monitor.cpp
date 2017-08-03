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
#include <climits>
using namespace std;

typedef long long ll;

void print_height(const unordered_map<int,int> &map_data){
    for(auto& e : map_data){
        cout << e.first << " : " << e.second << endl;
    }
    cout << endl;
}
/*
void print_student(const map<int,set<int>> &map_data){
    for(auto& e : map_data){
        cout << e.first << " : ";
        for(auto& s: e.second)
            cout << s << " ";
        cout << endl;
    }
    cout << endl;
}

int heightDiff(const map<int,int> &height_map){
    map<int,set<int>> student_map;
    for(auto &h : height_map)
        student_map[h.second].insert(h.first);
    cout << "\n\nstudent map :\n\n";
    print_student(student_map);
    auto &lowest_no_of_student = *student_map.begin();
    auto &maximum_no_of_student = *(--student_map.end()) ;
    int min_height = *min_element(lowest_no_of_student.second.begin(),lowest_no_of_student.second.end());
    int max_height = *max_element(maximum_no_of_student.second.begin(),maximum_no_of_student.second.end());
    int diff = max_height - min_height;
    if(diff)
        return diff;
    return -1;
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tests;
    cin >> tests;
    while(tests--){
        int n;
        int max_student = INT_MIN;
        int min_student = INT_MAX;
        cin >> n;
        unordered_map<int,int> height_map;
        for(int i=0; i<n; ++i){
            int height;
            cin >> height;
            height_map[height]++;

        }
        for(auto& p : height_map){
            max_student = max(max_student,p.second);
            min_student = min(min_student,p.second);
        }
        int diff = max_student - min_student;
        print_height(height_map);
        cout << max_student << " " << min_student << endl;
        cout << (diff == 0 ? -1 : diff) << endl;
        rank
    }
    return 0;
}
