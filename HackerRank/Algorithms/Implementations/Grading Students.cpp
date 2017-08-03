#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int students;
    cin >> students;
    while(students--){
        int grade;
        cin >> grade;
        if(grade >=38){
            int rounded = ceil((double)grade/5)*5;
            int diff = rounded - grade;
            if(diff < 3)
                grade = rounded;
        }
        cout << grade<<endl;
    }
    return 0;
}
